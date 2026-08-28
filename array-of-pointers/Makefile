CC = gcc
CFLAGS = -Iinclude
TARGET = array_of_pointers

OBJS = build/main.o build/token.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/token.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/token.o: src/token.c include/token.h
	$(CC) $(CFLAGS) -c src/token.c -o build/token.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
