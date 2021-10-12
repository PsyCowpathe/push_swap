/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:01:01 by agirona           #+#    #+#             */
/*   Updated: 2021/10/12 17:40:54 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

int	is_sort(t_stack *stack)
{
	t_element	*current;
	t_element	*verif;

	current = stack->first;
	while (current != NULL)
	{
		verif = current;
		while (verif != NULL)
		{
			if (verif->value < current->value)
				return (0);
			verif = verif->next;
		}
		current = current->next;
	}
	return (1);
}

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
			if (ft_isdigit(list[i][c]) == 0)
				if (!((list[i][0] == '-' || list[i][0] == '+')
					&& only_num(list[i]) == 1))
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
