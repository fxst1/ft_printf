#include "ft_printf.h"

int	main()
{
	printf("\n{%%.4d}\n{%.4d}\n", 42);
	ft_printf("{%.4d}\n", 42);

	printf("\n{%%-10d}\n{%-10d}\n", 42);
	ft_printf("{%-10d}\n", 42);

	return (0);
}
