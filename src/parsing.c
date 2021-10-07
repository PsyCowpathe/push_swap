/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:26:58 by agirona           #+#    #+#             */
/*   Updated: 2021/10/07 20:14:51 by agirona          ###   ########lyon.fr   */
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

int	check_int(int len, char **list)
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
