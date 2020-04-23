all: bin/run.out

bin/run.out: build/main.o build/board.o
	g++ -Wall --std=c++17 -Werror build/main.o build/board.o -o bin/run.out

build/main.o: src/main.cpp
	g++ -Wall --std=c++17 -Werror -c src/main.cpp -o build/main.o
build/board.o: src/board.cpp
	g++ -Wall --std=c++17 -Werror -c src/board.cpp -o build/board.o

clean:
	rm -rf *.o build/*.o

clean_all:
	rm -rf *.o build/*.o
