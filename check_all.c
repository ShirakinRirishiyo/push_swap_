#include "push_swap.h"

static int ft_duplicated(int num, char **av, int i)
{
	i++;
	while(av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int ft_insum(char *num)
{
	int i;

	i = 0;
	if(num[0] == '-')
		i++;
	while(num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void check_all(int ac, char **av)
{
	int i;
	long tmp;
	char **args;

	i = 0;
	if(ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if(!ft_insum(args[i]))
			error_handle("Error");
		if(tmp > 2147483647 || tmp < -2147483648)
			error_handle("Error");
		if(ft_duplicated(tmp, args, i))
			error_handle("Error");
		
	}
	if(ac == 2)
		ft_free(args);	
}
