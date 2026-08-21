CC = gcc
CFLAGS = -Iinclude
TARGET = helper_fields

OBJS = build/main.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/packet_header.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
