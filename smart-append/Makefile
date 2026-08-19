CC = gcc
CFLAGS = -Iinclude
TARGET = smart_append

OBJS = build/main.o build/exercise.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/exercise.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/exercise.o: src/exercise.c include/exercise.h
	$(CC) $(CFLAGS) -c src/exercise.c -o build/exercise.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)