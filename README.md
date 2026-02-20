*This Project has been created as part of the 42 curriculum by nyramana.*

# FT PRINTF

## Description:
The ft_printf is a project that remakes the basics of the popular printf function from the libc. Its main goal is to make us understand how printf works and how we can manipulate strings using the libft library we made and some other functions we added; we also learn variadic functions. With that, we can use our own program to show something on the screen.

**Function name:**
```c
int	ft_printf(const char *str, ...);
```
**Parameter:**
`str`: The string you want to print.
`...`: The other parameters if you use a conversion.
**Return value:**
- Length of the string printed
- -1 if an error was found

## Instructions:
**Compilation:**
Simply type this command in the source directory to get a static library named `libftprintf.a`:
```bash
make
```
Other useful make commands:
```bash
make all #Same as the make command
make clean #clean every .o files
make fclean #clean every .o and the libftprintf.a files
make re #rebuild the static library
```
**Installation:**
Just create your program in the source file and use the following command:
```bash
cc -Wall -Werror -Wextra libftprintf.a main.c -Iincludes -o program
```
**Program example:**
```c
#include "ft_printf.h"

int main(void)
{
    int i;

    i = ft_printf("Hello %s!", "world");
    ft_printf("The length of the previous printf is : %s", i);
    return (0);
}
```

**Execution:**
```bash
./program
```

## Resources:

- The `man` command
- [printf](https://koor.fr/C/cstdio/fprintf.wp) manual but in French

**AI usage:**
AI was mainly used to try to test my program, like using a null or some error that may occur when we do some dumb things. It also helps me to correct my README and some missing information that I didn't write.

## Algorithm:
- Scan the format string from left to right.
- If the current character is not `%`, write it and increment the printed length.
- If it is `%`, read the next character as the specifier.
- Dispatch to a handler for that specifier (e.g., `c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`, `%`).
- Each handler prints the value using helpers (write, number to string, base conversion) and returns the number of bytes written.
- Accumulate the total length; if any write fails, return `-1`.

### explanation and justification
Single-pass parser: scan the format string left-to-right, and when `%` is found, dispatch the corresponding handler and write immediately. This preserves output order and makes the code clearer without using a buffer.

Data structures: a `const char *` format string for linear scanning, `va_list` for sequential variadic access, and small temporary buffers for numeric conversion. These choices minimize allocations while matching the specifier order.