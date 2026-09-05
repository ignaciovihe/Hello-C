CC = gcc
CFLAGS = -Iinclude
TARGET = low_level_stack

OBJS = build/main.o build/stack.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/stack.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/stack.o: src/stack.c include/stack.h
	$(CC) $(CFLAGS) -c src/stack.c -o build/stack.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
