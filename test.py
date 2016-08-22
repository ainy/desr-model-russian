#!/usr/bin/env python2.7
#coding: utf-8
import re
splitter = re.compile(r'(\W*)(\S*?)(\W*?)\s', flags=re.U)

def tokenize(text):
  for lpunct,word,rpunct in splitter.findall(text+' '):
      if len(lpunct.lstrip()):
          yield lpunct.strip()
      if len(word):
          yield word
      if len(rpunct):
          yield rpunct

import readmodel
sent = tokenize(u"Целью курса является обучение магистрантов основам построения и функционирования программного обеспечения сетей ЭВМ.")

for x in readmodel.parse(list(sent)):
  print "%s %s\t%s %s"%x