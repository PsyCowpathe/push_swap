/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:26:58 by agirona           #+#    #+#             */
/*   Updated: 2021/10/05 17:28:13 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_duplicate(int len, char **list)
{
	int		i;
	int		c;

	i = 0;
	while (i < len)
	{
		c = 0;
		while (c < len)
		{
			if (ft_strcmp(list[c], list[i]) == 0 && c != i)
			{
				ft_putstr("Error\nSeveral ");
				ft_putstr(list[c]);
				ft_putstr(" in program argument.");
				return (0);
			}
			c++;
		}
		i++;
	}
	return (1);
}

int		check_int(int len, char **list)
{
	int			i;
	int			c;
	int			isint;

	i = 0;
	while (i < len)
	{
		c = 0;
		while (list[i][c])
		{
			if ((list[i][c] == '-' && ft_isdigit(list[i][c + 1]) == 0)
				|| (c != 0 && ft_isdigit(list[i][c] == 0)))
				return (0);
			c++;
		}
		if (c == 0)
			return (0);
		ft_atoi_check(list[i], &isint);
		if (isint == 0)
			return (0);
		i++;
	}
	return (1);
}
