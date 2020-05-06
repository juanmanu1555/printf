#include "libftprintf.h"

int main(void)
{
    int result;

    result = 0;

    result = ft_printf("|%x|", -52625);
    printf("\n%d\n", result -2);
    printf("\n");
}