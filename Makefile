CFLAGS=-Wall
CPPFLAGS= -std=c++11
CC= g++
SOURCES=parser.cpp main.cpp tokens.cpp

all: parser proba

.PHONY: clean

clean:
	rm parser.cpp parser.hpp parser tokens.cpp  *~

graph: parser.hpp
	bison -r all -g parser.y
	dot -Tpdf parser.dot -o parser.pdf

parser.cpp: parser.y
	bison -d -o $@ $^

parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	flex -o $@ $<

parser: $(SOURCES)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^

proba:  parser ./probak/proba1.in ./probak/proba2.in ./probak/probatxar1.in
	./parser <./probak/proba1.in
	./parser <./probak/proba2.in
	./parser <./probak/proba3.in
	./parser <./probak/proba4.in
	./parser <./probak/probatxar1.in
	./parser <./probak/probatxar2.in
	./parser <./probak/probatxar3.in
