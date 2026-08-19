# Hello C

A collection of small C exercises while learning the language.

## Exercises

### concat-strings

Manual implementation of string concatenation using pointers.

### smart-append

String concatenation with a fixed-size buffer, keeping track of the available space.

### forward-declarations

Practice with structs, typedefs, pointers, and forward declarations between related structures.

### http-switch

Conversion of HTTP status codes to strings using an enum and a switch statement.

## Building an Exercise

Each exercise contains its own Makefile.

Move into the exercise directory:

```bash
cd concat-strings
```

Build:

```bash
make
```

Run:

```bash
./concat_strings
```

Clean generated files:

```bash
make clean
```

## Creating a New Exercise

New exercises can be created with the `new-c-exercise.sh` script.

Usage:

```bash
./new-c-exercise.sh <project-name> <module-name>
```

For example:

```bash
./new-c-exercise.sh http-switch http
```

This creates the following structure:

```text
http-switch/
├── build/
├── include/
│   └── http.h
├── src/
│   ├── main.c
│   └── http.c
└── Makefile
```

The first argument is the project directory name:

```text
http-switch
```

The second argument is the module name used for the `.c`, `.h`, and `.o` files:

```text
http
```

The script also generates a Makefile configured for the new project. Hyphens in the project name are automatically converted to underscores for the executable name:

```text
http-switch → http_switch
```