/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 01:50:20 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/09 16:18:04 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	**swap(char **av, int i)
{
	char *tmp;

	tmp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = tmp;
	return (av);
}

char	**pre_swap(char **av, int i, int n, int ac)
{
	while (i + 1 < ac)
	{
		if (av[i][n] == '\0')
		{
			i++;
			n = 0;
		}
		else if (av[i][n] == av[i + 1][n])
			n++;
		else if (av[i][n] < av[i + 1][n])
		{
			i++;
			n = 0;
		}
		else
		{
			av = swap(av, i);
			i = 1;
			n = 0;
		}
	}
	return (av);
}

int		main(int ac, char **av)
{
	int		i;
	int		n;
	char	**res;

	i = 1;
	n = 0;
	res = pre_swap(av, i, n, ac);
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
}
