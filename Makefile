CC = gcc
SRC = radeonfetch.c
OBJ = $(SRC:.c=.o)
EXE = radeonfetch

all: $(EXE)
radeonfetch: radeonfetch.o
	$(CC) $(SRC) -o $@
debug:
	$(CC) -g $(SRC) -o debug
test:
	./$(EXE)
install:
	install -Dm755 ./$(EXE) /usr/local/bin/$(EXE)
uninstall:
	rm /usr/local/bin/$(EXE)
clean:
	rm -f $(OBJ) $(EXE) debug
