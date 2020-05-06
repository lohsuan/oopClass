.PHONY: directories clean stat

CFLAGS = -std=c++11 -Wfatal-errors

all: directories bin/main bin/ut_all

bin/main: src/main.cpp src/dot.h
	g++ $(CFLAGS) src/main.cpp -o bin/main

bin/ut_all: obj/ut_main.o
	g++ $(CFLAGS) -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/ut_vector.h test/ut_matrix.h src/dot.h src/math_vector.h src/math_matrix.h
	g++ $(CFLAGS) -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*
