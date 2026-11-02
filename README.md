*This project has been created as part of the 42 curriculum by aahmamou.*

# ft_printf

## Description

The **ft_printf** project consists of recreating the standard C `printf()` function as a custom library named `libftprintf.a`.

The goal is to understand variadic functions, format-string parsing, character output, number conversion, recursion, and return-value management.

The mandatory part supports the following conversions:

- `%c` — print a character.
- `%s` — print a string.
- `%p` — print a pointer in hexadecimal format.
- `%d` and `%i` — print a signed decimal integer.
- `%u` — print an unsigned decimal integer.
- `%x` — print a hexadecimal number using lowercase letters.
- `%X` — print a hexadecimal number using uppercase letters.
- `%%` — print a percent sign.

The implementation uses helper functions to handle output and conversions. It does not reproduce the original `printf()` buffer management.

## Instructions

### Requirements

- A C compiler (`cc`).
- `make`.
- `ar`, to create the static library.

### Compilation

Clone the repository and enter the project directory. Run:

```bash
make
```

This creates `libftprintf.a` at the root of the repository.

Other Makefile rules:

```bash
make clean
make fclean
make re
```

- `make clean` removes object files.
- `make fclean` removes object files and the library.
- `make re` rebuilds the library from scratch.

### Usage

Include `ft_printf.h` in your C source file and link the library when compiling.

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d\n", "world", 42);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror main.c -I. libftprintf.a -o test
./test
```

## Algorithm and Data Structure

### Algorithm

The implementation processes the format string sequentially, from left to right.

1. Initialize a `va_list` using `va_start()` to access the variable arguments.
2. Read the format string one character at a time.
3. When a conversion marker (`%`) is encountered, identify the following conversion character and dispatch it to the corresponding helper function.
4. For ordinary characters, write the character directly.
5. Retrieve the corresponding argument using `va_arg()`.
6. Accumulate the number of characters successfully written by each helper.
7. Call `va_end()` when argument processing is finished.
8. Return the total number of characters written, or `-1` if an output error occurs.

Each output helper returns the number of characters successfully written, or `-1` if an output operation fails. Errors are propagated through the helper functions to `ft_printf()`.

### Data Structures

The implementation uses `va_list`, provided by `<stdarg.h>`, to manage the variable arguments passed to `ft_printf()`.

It does not require a custom linked list, tree, or other complex data structure. The format string is traversed using an integer index, while local variables track the current conversion, output count, and values being printed.

### Design Choices

The implementation separates format parsing from output operations.

- `ft_printf.c` handles the format string, retrieves arguments, and dispatches conversions.
- `ft_printf_utils.c` contains character output, string output, unsigned decimal printing, and hexadecimal printing.
- `ft_printf_nbr.c` handles signed integer printing using a private recursive helper.

Recursive functions are used to print numbers from the most significant digit to the least significant digit.

Signed integer printing uses a `long` variable to safely handle the magnitude of `INT_MIN` on the target platform.

The project is organized so that no source file contains more than five functions. This keeps the implementation modular and each function focused on a specific responsibility.

## Resources

- [`printf(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html): reference for formatted output.
- [`stdarg(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html): reference for variadic argument handling.
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/): additional reference for C library functions.
- The official `ft_printf` subject.

### AI Usage

AI tools were used as a learning aid to explain variadic functions, clarify conversion logic, review implementation decisions, identify edge cases, and develop testing strategies.