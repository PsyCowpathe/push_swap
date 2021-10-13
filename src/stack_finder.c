/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:10 by agirona           #+#    #+#             */
/*   Updated: 2021/10/13 15:19:14 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_highter_value(t_stack *stack)
{
	t_element	*current;
	int			i;
	int			position;

	current = stack->first;
	i = 1;
	while (current != NULL)
	{
		if (current->value <= stack->pivot)
		{
			position = i;
			current = NULL;
		}
		else
		{
			current = current->next;
			i++;
		}
	}
	return (position);
}

int	get_smaller_value(t_stack *stack)
{
	t_element	*current;
	int			lower;

	current = stack->first;
	lower = stack->first->value;
	while (current != NULL)
	{
		if (current->value < lower)
			lower = current->value;
		current = current->next;
	}
	return (lower);
}

int	get_bigger_value(t_stack *stack, int *position)
{
	t_element	*current;
	int			highter;
	int			i;

	current = stack->first;
	highter = stack->first->value;
	i = 1;
	if (position)
		*position = -1;
	while (current != NULL)
	{
		if (current->value >= highter)
		{
			highter = current->value;
			if (position)
				*position = i;
		}
		current = current->next;
		i++;
	}
	return (highter);
}

int	get_next_value(t_stack *stack, long value, int *position)
{
	t_element	*current;
	int			find;
	int			i;

	current = stack->first;
	find = get_bigger_value(stack, NULL);
	if (position)
		*position = -1;
	i = 1;
	while (current != NULL)
	{
		if (current->value < find && current->value > value)
		{
			find = current->value;
			if (position)
				*position = i;
		}
		current = current->next;
		i++;
	}
	return (find);
}

int	select_pivot(t_stack *stack, int position)
{
	int			pivot;
	int			i;

	i = 1;
	pivot = get_smaller_value(stack);
	while (i < position)
	{
		pivot = get_next_value(stack, pivot, NULL);
		i++;
	}
	return (pivot);
}
