CC = gcc
CFLAGS = -Iinclude
TARGET = http_switch

OBJS = build/main.o build/http.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/http.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/http.o: src/http.c include/http.h
	$(CC) $(CFLAGS) -c src/http.c -o build/http.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
