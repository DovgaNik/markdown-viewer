CppC=g++
CFlags= -pipe -Wall -Wextra -Wpedantic
EXE=mdview
SRC=src/main.cpp lib/msleep/msleep.cpp lib/parser/parser.cpp
OBJ=build/main.o build/msleep.o build/parser.o
DESTDIR=/usr/local/bin

all: bin/$(EXE)

bin/$(EXE): $(OBJ)
	mkdir -p bin
	$(CppC) $(CFlags) $(OBJ) -o bin/$(EXE)

$(OBJ): $(SRC)
	mkdir -p build
	$(CppC) $(CFlags) -c $(SRC)
	cp *.o build/	
	rm ./*.o

clean:
	rm -rf build bin

.PHONY: install
install: bin/$(EXE)
	mkdir -p $(DESTDIR)
	cp bin/$(EXE) $(DESTDIR)

.PHONY: uninstall
uninstall:
	rm $(DESTDIR)/$(EXE)
