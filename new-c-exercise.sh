#!/bin/bash

PROJECT_NAME=$1
MODULE_NAME=$2

if [ -z "$PROJECT_NAME" ] || [ -z "$MODULE_NAME" ]; then
    echo "Usage: $0 <project-name> <module-name>"
    exit 1
fi

mkdir -p "$PROJECT_NAME/src" "$PROJECT_NAME/include" "$PROJECT_NAME/build"

touch "$PROJECT_NAME/src/main.c" \
      "$PROJECT_NAME/src/$MODULE_NAME.c" \
      "$PROJECT_NAME/include/$MODULE_NAME.h" \
      "$PROJECT_NAME/Makefile"

TARGET_NAME="${PROJECT_NAME//-/_}"

cat > "$PROJECT_NAME/Makefile" <<EOF
CC = gcc
CFLAGS = -Iinclude
TARGET = $TARGET_NAME

OBJS = build/main.o build/$MODULE_NAME.o

\$(TARGET): \$(OBJS)
	\$(CC) \$(OBJS) -o \$(TARGET)

build/main.o: src/main.c include/$MODULE_NAME.h
	\$(CC) \$(CFLAGS) -c src/main.c -o build/main.o

build/$MODULE_NAME.o: src/$MODULE_NAME.c include/$MODULE_NAME.h
	\$(CC) \$(CFLAGS) -c src/$MODULE_NAME.c -o build/$MODULE_NAME.o

.PHONY: clean
clean:
	rm -f \$(TARGET) \$(OBJS)
EOF

echo "Created C exercise: $PROJECT_NAME"