#!/bin/bash

PROJECT_NAME=$1

if [ -z "$PROJECT_NAME" ]; then
    echo "Usage: $0 <project-name>"
    exit 1
fi

mkdir -p "$PROJECT_NAME/src" "$PROJECT_NAME/include" "$PROJECT_NAME/build"

touch "$PROJECT_NAME/src/main.c" \
      "$PROJECT_NAME/src/exercise.c" \
      "$PROJECT_NAME/include/exercise.h" \
      "$PROJECT_NAME/Makefile"

TARGET_NAME="${PROJECT_NAME//-/_}"

cat > "$PROJECT_NAME/Makefile" <<EOF
CC = gcc
CFLAGS = -Iinclude
TARGET = $TARGET_NAME

OBJS = build/main.o build/exercise.o

\$(TARGET): \$(OBJS)
	\$(CC) \$(OBJS) -o \$(TARGET)

build/main.o: src/main.c include/exercise.h
	\$(CC) \$(CFLAGS) -c src/main.c -o build/main.o

build/exercise.o: src/exercise.c include/exercise.h
	\$(CC) \$(CFLAGS) -c src/exercise.c -o build/exercise.o

.PHONY: clean
clean:
	rm -f \$(TARGET) \$(OBJS)
EOF

echo "Created C exercise: $PROJECT_NAME"