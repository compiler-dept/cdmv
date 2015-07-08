BIN=cdvm

CFLAGS=-Wall -Werror -g

OBJECTS=cdvm.o

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN) $(OBJECTS)
	rm -rf $(BIN).dSYM
