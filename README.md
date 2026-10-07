# Hello C

A collection of C exercises and small projects created while learning
the language.

This repository documents my progression from basic C concepts to
lower-level topics such as pointers, dynamic memory management, object
relationships, reference counting, and mark-and-sweep garbage
collection.

## Topics Practiced

-   Pointers and pointer arithmetic
-   Arrays and strings
-   Structs, enums, unions, and `typedef`
-   Forward declarations
-   `void *` and generic pointers
-   Dynamic memory allocation
-   `malloc`, `calloc`, `realloc`, and `free`
-   Stack data structures
-   Multi-file C projects
-   Header files
-   Compilation and linking with GCC
-   Makefiles
-   Reference counting garbage collection
-   Mark-and-sweep garbage collection

## Exercises

### `concat-strings`

Manual implementation of string concatenation using pointers.

### `smart-append`

String concatenation with a fixed-size buffer while keeping track of the
remaining available space.

### `forward-declarations`

Practice with structs, `typedef`, pointers, and forward declarations
between related structures.

### `http-switch`

Conversion of HTTP status codes to strings using an enum and a `switch`
statement.

### `array-of-pointers`

Practice working with arrays of pointers and accessing values through
pointer indirection.

### `helper-fields`

Exercises using additional fields in data structures to keep track of
state and support low-level operations.

### `void-pointers`

Practice with `void *`, generic pointers, and working with pointers
without a specific data type.

### `low-level-stack`

Practice implementing and working with a low-level stack structure and
dynamically managed memory.

### `snek-objects`

A small object system supporting several object types, including
integers, floats, strings, vectors, and arrays.

This exercise practices structs, unions, enums, dynamic allocation, and
relationships between objects.

### `refcounting-gc`

Memory management using reference counting.

Objects track how many references point to them and can be freed when
their reference count reaches zero. The exercise explores ownership,
nested object references, and cleanup of dynamically allocated data.

### `mark-and-sweep-gc`

Implementation of a simple mark-and-sweep garbage collector using a
small virtual-machine model with stack frames and tracked heap objects.

Garbage collection is divided into three stages:

1.  **Mark** --- objects directly reachable from active stack frames are
    marked.
2.  **Trace** --- references contained inside reachable vectors and
    arrays are followed.
3.  **Sweep** --- unreachable objects are freed and removed from the
    VM's tracked object list.

The exercise also demonstrates an important difference from simple
reference counting: unreachable reference cycles can still be collected
because reachability is determined from the root set.

## Project Structure

The exercises are organized as small independent C projects. A typical
exercise uses a structure like:

``` text
exercise-name/
├── build/
├── include/
│   └── module.h
├── src/
│   ├── main.c
│   └── module.c
└── Makefile
```

Larger exercises can contain several source and header files.

For example, `mark-and-sweep-gc` contains separate modules for the
virtual machine, Snek objects, object creation, and the stack
implementation.

## Building an Exercise

Each exercise contains its own `Makefile`.

Move into the exercise directory:

``` bash
cd mark-and-sweep-gc
```

Build the project:

``` bash
make
```

Run the generated executable:

``` bash
./mark_and_sweep_gc
```

Clean generated object files and the executable:

``` bash
make clean
```

The exercises are compiled with GCC. Compiler warning options such as
the following are used to catch potential problems while learning C:

``` text
-Wall -Wextra -Wpedantic
```

## Creating a New Exercise

New exercises can be scaffolded with the included `new-c-exercise.sh`
script.

Usage:

``` bash
./new-c-exercise.sh <project-name> <module-name>
```

For example:

``` bash
./new-c-exercise.sh http-switch http
```

This creates:

``` text
http-switch/
├── build/
├── include/
│   └── http.h
├── src/
│   ├── main.c
│   └── http.c
└── Makefile
```

The first argument defines the project directory:

``` text
http-switch
```

The second defines the module name used for the `.c`, `.h`, and `.o`
files:

``` text
http
```

The script also creates a Makefile for the exercise.

Hyphens in project names are converted to underscores for executable
names:

``` text
http-switch → http_switch
```

## VS Code Workspace

The repository also includes `Hello-C.code-workspace`, which can be used
to open the exercises as a multi-root workspace in Visual Studio Code.

``` bash
code Hello-C.code-workspace
```

This keeps the individual exercises visible as separate project roots
while they remain part of the same Git repository.

## Purpose

This is primarily a learning repository.

The goal is not only to produce working programs, but to build a better
understanding of what happens at a lower level: how pointers reference
memory, how dynamically allocated objects are represented and released,
how objects can reference each other, and how different
memory-management strategies work.
