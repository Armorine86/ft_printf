#include "../includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len = 0;
	len = printf("%s%n", "tripouille");
	printf("\n");
	printf("%d\n", len);
	//len = ft_printf("%s%i%n42", "tripouille", INT_MAX, &n);
	//printf("\n");
	//printf("%d\n", len);
}