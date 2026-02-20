#include "ft_printf.h"

int main(void)
{
    int i;

    i = ft_printf("Hello %s!", "world");
    ft_printf("The length of the previous printf is : %s", i);
    return (0);
}