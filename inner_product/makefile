.phony: clean stat directories


CFLAGS = -std=c++11 -Wfatal-errors # -fno-elide-constructors

all: bin/dot bin/test

bin/dot: src/main.cpp src/dot.h
	g++ $(CFLAGS) src/main.cpp -o bin/dot

bin/test: test/ut_all.cpp test/ut_matrix.h test/ut_convex_polygon.h test/ut_inner_product.h src/dot.h src/math_vector.h src/matrix.h src/convex_polygon.h
	g++ $(CFLAGS) test/ut_all.cpp -o bin/test -lgtest -lpthread

clean:
	rm -f bin/*

stat:
	wc -l src/* test/*

directories:
	mkdir bin obj