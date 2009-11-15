CXXFLAGS += -Wall -O2

all: game

game: environment.o character.o

clean:
	rm -fr *.o game
