DesrDL dependency parser model for Russian. This model includes morphology, dependency syntax and embeddings with no need in external tools pipeline. Parser was trained on SemCorRus corpora. Original SWIG python binding throws SEGFAULTs and I decided to write my own. Parser 1.6.0 also includes PHP and Java bindings.

Parser lives here:

*  [https://sites.google.com/site/desrparser/]
*  [http://sourceforge.net/projects/desr]

Scores
======

| LAS | 69.19 % | 74546/107737 |
|-----|---------|--------------|
| UAS | 76.31 % | 82214/107737 |

Sentences: 6130
796.16 sec user 2.40 sec system 13:21 elapsed 99% CPU (137M maxresident)

Installation
============
See build.sh


Usage(python)
============

        > import readmodel
        > sent = tokenize(u"Целью курса является обучение магистрантов основам построения и функционирования программного обеспечения сетей ЭВМ.")
        > readmodel.parse(list(sent))
        [(1, 'Целью', 3, 'dobj'), (2, 'курса', 1, 'dobj'), (3, 'является', 0, 'root'), (4, 'обучение', 3, 'nsubj'), (5, 'магистрантов', 4, 'dobj'), (6, 'основам', 4, 'nmod'), (7, 'построения', 6, 'dobj'), (8, 'и', 7, 'cc'), (9, 'функционирования', 7, 'conj'), (10, 'программного', 11, 'amod'), (11, 'обеспечения', 9, 'nmod'), (12, 'сетей', 11, 'dobj'), (13, 'ЭВМ', 12, 'nmod'), (14, '.', 3, 'punct')]

