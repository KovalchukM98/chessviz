all: bin/programm clean

bin/programm: build/main.o build/board.o
	g++ -Wall --std=c++17 -Werror build/main.o build/board.o -o bin/run.out

build/main.o: src/main.cpp
	g++ -Wall --std=c++17 -Werror -c src/main.cpp -o build/main.o
build/board.o: src/board.cpp
	g++ -Wall --std=c++17 -Werror -c src/board.cpp -o build/board.o

clean:
	rm -f *.o build/*.o
