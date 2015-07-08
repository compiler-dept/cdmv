BIN=cdvm

CFLAGS=-std=c11 -Wall -Werror -g

SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN) $(OBJECTS)
	rm -rf $(BIN).dSYM
