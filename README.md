# CCodeDump
Personal repository dedicated to organizing C source code, experiments, and cheat sheets.

Also featuring [mini-games](https://github.com/0xSickb0y/CCodeDump/tree/main/games)!

# Cheat Sheet

### Structure of a C Program
```c
#include <stdio.h> // Standard I/O library
// Every C program consists of one or more functions.
// The main() function is the entry point of a C program.
int main() {
    printf("Hello, World!\n");
    return 0;
}
// Statements in C end with a semicolon ;
```

### Data Types
```c
int a;        // Integer data type
float b;      // Floating-point data type
double c;     // Double-precision floating-point data type
char d;       // Character data type
void function(); // Represents absence of type
```

### Variables and Constants
```c
int variable = 5;        // Variables hold values that can change during program execution
const int CONSTANT = 10; // Constants are values that do not change during program execution
```

### Operators
```c
// Arithmetic operators: +, -, *, /, %
int sum = a + b;
int difference = a - b;
int product = a * b;
int quotient = a / b;
int remainder = a % b;

// Relational operators: ==, !=, <, >, <=, >=
if (a == b) { /*...*/ }
if (a != b) { /*...*/ }
if (a < b)  { /*...*/ }
if (a > b)  { /*...*/ }
if (a <= b) { /*...*/ }
if (a >= b) { /*...*/ }

// Logical operators: &&, ||, !
if (a && b) { /*...*/ }
if (a || b) { /*...*/ }
if (!a)     { /*...*/ }

// Assignment operators: =, +=, -=, *=, /=, %=
a = b;
a += b;
a -= b;
a *= b;
a /= b;
a %= b;
```

### Control Flow
```c
// if, else, else if: Conditional statements
if (condition) {
    // code
} else if (another_condition) {
    // code
} else {
    // code
}

// switch, case, default: Multi-branching conditional statement
switch (variable) {
    case 1:
        // code
        break;
    case 2:
        // code
        break;
    default:
        // code
        break;
}

// while, do-while, for: Looping constructs
while (condition) {
    // code
}

do {
    // code
} while (condition);

for (initialization; condition; increment) {
    // code
}
```

### Functions
```c
// Functions encapsulate a block of code.
return_type function_name(parameters) {
    // code
    return value; // Functions can return values using return.
}

// Functions can be declared before being defined.
void declared_function(int a, int b);
```

### Arrays
```c
// Arrays are collections of elements of the same type.
int array[10]; // Arrays are zero-indexed.
array[0] = 1;  // Accessing array elements: array[index].
```

### Pointers
```c
// Pointers are variables that store memory addresses.
int *pointer;
pointer = &variable;  // Address of variable
*pointer = 10;        // Dereferencing pointer

// Pointers are extensively used for dynamic memory allocation.
```

### Memory Management
```c
#include <stdlib.h>

int *ptr;
ptr = (int *)malloc(sizeof(int));    // Allocates memory block
ptr = (int *)calloc(10, sizeof(int)); // Allocates and initializes memory block
ptr = (int *)realloc(ptr, new_size);  // Reallocates memory block

free(ptr); // Releases dynamically allocated memory
```

### Structures and Unions
```c
// struct: Allows grouping of variables of different types.
struct Example {
    int integer;
    float decimal;
    char character;
};

// union: Similar to struct, but shares memory among its members.
union ExampleUnion {
    int integer;
    float decimal;
    char character;
};
```

### File Handling
```c
#include <stdio.h>

FILE *file;
file = fopen("filename.txt", "r"); // fopen(): Opens a file
// Mode "r" for read, "w" for write, "a" for append

fprintf(file, "Hello, World!");    // fprintf(): Writes formatted output
fscanf(file, "%s", buffer);        // fscanf(): Reads formatted input

fclose(file); // fclose(): Closes a file
```

### Preprocessor Directives
```c
#include <stdio.h> // #include: Includes header files.
#define PI 3.14    // #define: Defines constants and macros.

#ifdef DEBUG
// #ifdef, #ifndef, #endif: Conditional compilation directives.
#endif
```

### Bitwise Operators
```c
int a = 5, b = 3;
int result;

// &, |, ^, ~, <<, >>: Perform operations at bit level.
result = a & b;  // AND
result = a | b;  // OR
result = a ^ b;  // XOR
result = ~a;     // NOT
result = a << 1; // Left shift
result = a >> 1; // Right shift
```

### Memory Management
```c
int size = sizeof(int); // sizeof(): Returns the size of a variable or type in bytes.
memset(ptr, 0, size);   // memset(): Fills memory with a constant byte.
memcpy(dest, src, size);// memcpy(): Copies memory area.
memmove(dest, src, size);// memmove(): Moves memory area.
```

### Function Pointers
```c
void (*func_ptr)(int);
void function(int a) {
    // code
}

func_ptr = &function; // Pointers that point to functions.
(*func_ptr)(5);       // Useful for implementing callback functions.
```

### Multi-dimensional Arrays
```c
// Arrays with more than one dimension.
int matrix[3][4];
matrix[0][0] = 1; // Accessing elements: matrix[row][col]
```

### Dynamic Memory Allocation
```c
#include <stdlib.h>

int *ptr;
ptr = (int *)malloc(10 * sizeof(int));  // Allocating memory at runtime
ptr = (int *)calloc(10, sizeof(int));   // Allocating and initializing memory
ptr = (int *)realloc(ptr, 20 * sizeof(int)); // Reallocating memory

free(ptr); // Releasing allocated memory
```

### File I/O Operations
```c
#include <stdio.h>

FILE *file;
file = fopen("filename.txt", "r");

char buffer[100];
fgets(buffer, 100, file); // Reading a line of text
fputs(buffer, file);      // Writing a line of text

fclose(file);
```

### Error Handling
```c
#include <errno.h>
#include <stdio.h>
#include <string.h>

FILE *file;
file = fopen("nonexistent.txt", "r");

if (file == NULL) {
    perror("Error opening file"); // Prints descriptive error message
    printf("Error: %s\n", strerror(errno)); // Returns error description
}
```

### Structures and Pointers
```c
struct Example {
    int integer;
    float decimal;
};

struct Example ex;
struct Example *ptr;
ptr = &ex;

ptr->integer = 10; // Accessing structure members using pointers
ptr->decimal = 3.14;
```

### Function Recursion
```c
// A function calling itself.
int factorial(int n) {
    if (n <= 1) // Base case
        return 1;
    else
        return n * factorial(n - 1); // Recursive call
}
```

### Command Line Arguments
```c
int main(int argc, char *argv[]) {
    // Accessing arguments passed to main() function.
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}
```

### Header Files
```c
// Organizing code into reusable modules.
// myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

void myFunction();

#endif

// mysource.c
#include "myheader.h"
void myFunction() {
    // code
}

// main.c
#include "myheader.h"
int main() {
    myFunction();
    return 0;
}
```
