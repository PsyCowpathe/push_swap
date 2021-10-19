/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:26:58 by agirona           #+#    #+#             */
/*   Updated: 2021/10/19 17:13:47 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack)
{
	t_element	*current;
	t_element	*verif;

	current = stack->first;
	while (current != NULL)
	{
		verif = stack->first;
		while (verif != NULL)
		{
			if (verif != current && verif->value == current->value)
				return (0);
			verif = verif->next;
		}
		current = current->next;
	}
	return (1);
}

int	only_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_format(char **list, int i, int *c)
{
	int		isint;

	ft_atoi_check(list[i] + *c, &isint);
	if (isint == 0)
		return (0);
	if ((list[i][*c] == '-' || list[i][*c] == '+'))
	{
		*c = *c + 1;
		if (ft_isdigit(list[i][*c]) == 0)
			return (0);
	}
	while (ft_isdigit(list[i][*c]) == 1)
		*c = *c + 1;
	if (list[i][*c] != ' ' && list[i][*c] != '\0')
		return (0);
	return (1);
}

int	check_int(int len, char **list)
{
	int		i;
	int		c;

	i = -1;
	while (++i < len)
	{
		c = 0;
		if (list[i][0] == '\0')
			return (0);
		while (list[i][c])
		{
			if (list[i][c] == ' ')
				c++;
			else if (list[i][c] == '-' || list[i][c] == '+'
				|| ft_isdigit(list[i][c]) == 1)
			{
				if (check_format(list, i, &c) == 0)
					return (0);
			}
			else if (list[i][c] != '\0')
				return (0);
		}
	}
	return (1);
}
