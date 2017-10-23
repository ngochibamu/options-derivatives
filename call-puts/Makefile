CC=g++
CFLAGS=-Wall -Werror -D_GLIBCXX_DEBUG -std=c++17 -g
COMPILE=$(CC) $(CFLAGS) -c
OBJFILES:=$(patsubst %.cpp, %.o, $(wildcard *.cpp))
PROG_NAME=Options

all: main

main: $(OBJFILES)
	$(CC) -o $(PROG_NAME) $(OBJFILES)

%.o: %.cpp
	$(COMPILE) -o $@ $<

clean:
	rm -f *.o *.html $(PROG_NAME)