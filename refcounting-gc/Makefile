CC = gcc
CFLAGS = -Iinclude
TARGET = refcounting_gc

OBJS = build/main.o build/snekobject.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/snekobject.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/snekobject.o: src/snekobject.c include/snekobject.h
	$(CC) $(CFLAGS) -c src/snekobject.c -o build/snekobject.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
