.PHONY: directories clean

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/test_polynomial.h test/test_term.h  src/polynomial.h src/term.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/*.h src/*.cpp test/*.h test/*.cpp
