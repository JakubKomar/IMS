# Ims projekt: infrastruktura přepravy LNG 
# @file  makefile
#
# @authors Jakub Komárek (xkomar33)
# @authors Kroupa Dominik (xkroup12)

CFLAGS= -Wall -g -lsimlib -lm

BIN=ims
ZIP=xkomar33.zip
CC=g++ 
RM=rm -f
SRC=$(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
.PHONY: all build run pack clean

all: build

build: 
	$(CC) $(CFLAGS) -o $(BIN) $(SRC) 

pack: clean
	cd src && \
	zip -r $(ZIP) *  && \
	mv $(ZIP) ../

run:
	test -f $(BIN) && ./$(BIN)

valgrind:
	test -f $(BIN) && valgrind ./$(BIN)

clean:
	rm -rf $(BIN) $(ZIP)



