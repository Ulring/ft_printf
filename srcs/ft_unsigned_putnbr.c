#include "../includes/ft.h"

void ft_unsigned_putnbr(unsigned int n)
{
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    else
        ft_putchar(n + '0');
}
