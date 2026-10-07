CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude
TARGET = mark_and_sweep_gc

OBJS = build/main.o \
       build/vm.o \
       build/sneknew.o \
       build/snekobject.o \
       build/stack.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/vm.o: src/vm.c include/vm.h
	$(CC) $(CFLAGS) -c src/vm.c -o build/vm.o

build/sneknew.o: src/sneknew.c include/sneknew.h
	$(CC) $(CFLAGS) -c src/sneknew.c -o build/sneknew.o

build/snekobject.o: src/snekobject.c include/snekobject.h
	$(CC) $(CFLAGS) -c src/snekobject.c -o build/snekobject.o

build/stack.o: src/stack.c include/stack.h
	$(CC) $(CFLAGS) -c src/stack.c -o build/stack.o

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJS)
