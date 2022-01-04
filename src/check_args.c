#include <push_swap.h>

void	check_args(t_turn *turn, int ac, char **av)
{
	int i;
	int num;

	if (ac < 2)
		error("ERROR");
	i = 1;
	while (i < ac)
	{
		if (is_int(av[i]) == 0)
			error("ERROR");
		num = atoi(av[i]);
		if (push_stack(&(turn->stack_a), &num))
			error("ERROR");
		++i;
	}
}