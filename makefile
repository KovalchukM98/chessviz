all: bin/programm clean

bin/programm: build/main.o
	g++ -Wall --std=c++17 -Werror build/main.o build/menu.o build/game.o build/sequence.o -o bin/programm

build/main.o: src/main.cpp
	g++ -Wall --std=c++17 -Werror -c src/main.cpp -o build/main.o

clean:
	rm -f *.o build/*.o
