#include <push_swap.h>

void	check_args(int ac, char **av)
{
	int i;

	if (ac < 2)
		error("ERROR");
	i = 1;
	while (i < ac)
	{
		if (is_int(av[i]) == 0)
			error("ERROR");
		++i;
	}
}