#include "src/Parser.h"
#include "src/Corpus.h"
#include <Python.h>

using namespace Parser;
using namespace Tanl;
using namespace IXE;
using namespace std;

Language const* language;
Corpus* c = 0;
Parser::Parser* p;
    

static PyObject* parse(PyObject* self, PyObject* obj) {
  PyObject* result = PyList_New(0);
  if (!c) return result;
  if (!PyList_Check(obj)) return result;
  
    obj = PyObject_GetIter(obj);
    Sentence sentence = Sentence(language);
    int id = 1;
    PyObject* item;
    //char* s[15] = {"Целью", "курса", "является", "обучение", "магистрантов", "основам", "построения", "и", "функционирования", "программного", "обеспечения", "сетей", "ЭВМ", "."};
    while (item = PyIter_Next(obj)) {
      if (!PyUnicode_Check(item)) return result;
      item = PyUnicode_AsEncodedString(item, "utf-8", "strict");
      
      Token tok = Token(PyString_AsString(item), *c);
      TreeToken* token = new TreeToken(id++, &tok);
      sentence.push_back(token);
    }
    Sentence* sentence2 = p->parse(&sentence);
    //printf("%s",c->toString(*sentence2).c_str());
    for(int i = 0; i < sentence2->size(); i++){
      item = Py_BuildValue("(isis)", i+1, sentence2->at(i)->form().c_str(), sentence2->at(i)->linkHead(), sentence2->at(i)->linkLabel().c_str() );
      PyList_Append(result, item);
    }
  delete sentence2;
  return result;
}

PyMethodDef methods[] = {
  {"parse", parse, METH_O},
  {NULL, NULL},
};

PyMODINIT_FUNC
initreadmodel(void)
{
    Py_InitModule("readmodel", methods);
    language = Language::get("eu");
    c = Corpus::create("eu", "CoNLL");
    p = Parser::Parser::create("ru.model");
}

