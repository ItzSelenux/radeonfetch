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
	install -Dm755 ./$(CC) /usr/local/bin/$(CC)
uninstall:
	rm /usr/local/bin/$(CC)
clean:
	rm -f $(OBJ) $(EXE) debug
