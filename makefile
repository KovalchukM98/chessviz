CFLAGS = -Wall -Werror --std=c++17

all: bin/run.out bin/test.out

bin/run.out: build/main.o build/board.o
	g++ $(CFLAGS) build/main.o build/board.o -o bin/run.out

build/main.o: src/main.cpp
	g++ $(CFLAGS) -c src/main.cpp -o build/main.o

build/board.o: src/board.cpp
	g++ $(CFLAGS) -c src/board.cpp -o build/board.o

bin/test.out: build/test.o build/board.o
	g++ $(CFLAGS) -L googletest/lib -l gtest_main -l gtest -l pthread build/test.o build/board.o -o bin/test.out

build/test.o: test/test.cpp
	g++ $(CFLAGS) -isystem googletest/googletest/include -l pthread -I googletest/googletest/include -I src -c test/test.cpp -o build/test.o

.PHONY : clean
clean :
	rm -rf *.o build/*.o
