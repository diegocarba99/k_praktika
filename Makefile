CFLAGS=
CPPFLAGS= -std=c++11
CC= g++
SOURCES=parser.cpp main.cpp tokens.cpp Kodea.cpp SinboloTaulenPila.cpp SinboloTaula.cpp Printer.cpp

all: parser proba

.PHONY: clean

clean:
	rm parser.cpp parser.hpp parser tokens.cpp  *~

graph: parser.hpp
	bison -r all -g parser.y
	dot -Tpdf parser.dot -o parser.pdf

parser.cpp: parser.y 
	bison -d -v -o $@ $^

parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	flex -o $@ $<

parser: $(SOURCES) Kodea.h Lag.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^

proba:  parser ./probak/proba1.in ./probak/proba2.in ./probak/proba3.in ./probak/proba4.in ./probak/proba5.in ./probak/proba6.in ./probak/proba7.in ./probak/probatxar1.in ./probak/probatxar2.in ./probak/probatxar3.in
#	./parser < ./probak/proba1.in
#	./parser < ./probak/proba2.in
#	./parser < ./probak/proba3.in
#	./parser < ./probak/proba4.in
#	./parser < ./probak/proba5.in
#	./parser < ./probak/proba6.in
	./parser < ./probak/proba7.in
#	./parser <./probak/probatxar1.in
#	./parser <./probak/probatxar2.in
#	./parser <./probak/probatxar3.in
