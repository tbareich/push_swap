#include "../push_swap.h"

void	check_args(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (is_numeric(av[i]) == 0)
			error("ERROR");
		++i;
	}
	
}