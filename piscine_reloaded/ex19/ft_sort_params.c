/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:33:39 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/06 19:20:10 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_tab(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		c;
	char	*temp;

	i = 2;
	c = 0;
	if (ac < 2)
		return (0);
	while (av[i])
	{
		while (av[i][c] == av[i - 1][c] && av[i][c] && av[i - 1][c])
			c++;
		if (ft_strcmp(&av[i - 1][c], &av[i][c]) > 0)
		{
			temp = av[i - 1];
			av[i - 1] = av[i];
			av[i] = temp;
			i = 0;
		}
		i++;
		c = 0;
	}
	print_tab(av);
}
