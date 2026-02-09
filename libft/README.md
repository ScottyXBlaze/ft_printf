*This project has been created as part of the 42 curriculum by nyramana.*

# Libft

## **Description:**

This project is a library of functions that are used in the 42 curriculum. It reimplement a set of functions from the C library like string manipulation, memory management and structure especially linked list.

## **Instructions:**

### **Compilation:**
To compile the project, you need to use the Makefile provided in the repository. Just type in the root repository and it will create the `libft.a`.
```bash
make
```
By doing that, you will have a static library that you can use in your project.

**Other make command:**
```bash
make clean # To remove every .o file
make fclean # use make clean and remove the `libft.a`
make re # Recompile the library
```

## **Example:** 
**Simple usage:** 
```
.
├── libft.h         # Header
├── libft.a         # Library
└── project.c          # Your program
```
```c
#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int integer;

    integer = ft_atoi("   +833783");
    printf("%d\n", integer); // Output: 833783
    return (0);
}
```
### Usage: 
To use the library, you need to include the header file `libft.h` in your project. Then compile your project with the library using the following command:

**Warning:** *Make sure to have the `libft.a` and `libft.h` files in the same directory as your project to make the compilation easier*

```bash
gcc -o  project project.c -L. -lft
# You can also use the following command to compile your program
gcc project.c libft.a -o project
```


## **Functions:**

*remember to add the `ft_` prefix before the name.* 


| Categories | Functions | Description |
| :--- | :--- | :--- |
| **Memory** | `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc` | Set and manipulate memory. |
| **Character** | `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower` | Test et convert individual characters (ASCII). |
| **String** | `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup` | Standards function to manipulate strings. |
| **Transformation** | `substr`, `strjoin`, `strtrim`, `split`, `itoa`, `atoi`, `strmapi` | Advanced Function to cut, join or convert data. |
| **Input/Output** | `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd` | Simplified writing to file descriptors (`fd`). |
| **Lists** | `lstnew`, `lstadd_front`, `lstsize`, `lstlast`, `lstadd_back`, `lstdelone`... | Management of linked list data structures|


## **Resources:** 

### references
* The libft subject given by 42.
* `man` pages.
* Youtube playlist like [linked list](https://youtube.com/playlist?list=PLBlnK6fEyqRi3-lvwLGzcaquOs5OBTCww&si=xiVstZLwszN4652O) or  [pointer](https://youtube.com/playlist?list=PLBlnK6fEyqRgZQ079Wa5H8D1oa43HGRQb&si=OOZIT1QzGjpywx_F) by Neso Academy.



## **Verification & Testing**

### Automated Testing
This project has been tested using community-standard tools to ensure compatibility with the subject requirements:
* **[Libfttester](https://github.com/Tripouille/libftTester/):** All tests passed.

### Development Process
* **Documentation:** AI was used as a learning assistant to clarify complex `man` pages (especially `strlcat` and `strlcpy`) and to help structure this documentation.
* **Manual Testing:** Custom main functions were created to test memory edge cases and linked list pointers.
