/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:10 by agirona           #+#    #+#             */
/*   Updated: 2021/10/05 21:21:35 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_next_highter_value(t_stack *stack, int value)
{
	int			find;
	int			position;
	int			i;
	t_element	*current;

	find = 0;
	position = 0;
	i = 1;
	current = stack->first;
	while (current != NULL)
	{
		if (current->value < value)
		{
			find = current->value;
			current = NULL;
			position = i;
		}
		else
			current = current->next;
		i++;
	}
	current = stack->first;
	i = 1;
	while (current != NULL)
	{
		if (current->value > find && current->value < value)
		{
			find = current->value;
			position = i;
		}
		current = current->next;
		i++;
	}
	return (position);
}

int		get_next_value(t_stack *stack, int value)
{
	t_element	*current;
	int			find;

	current = stack->first;
	while (current != NULL)
	{
		if (current->value > value)
		{
			find = current->value;
			current = NULL;
		}
		else
			current = current->next;
	}
	current = stack->first;
	while (current != NULL)
	{
		if (current->value < find && current->value > value)
			find = current->value;
		current = current->next;
	}
	return (find);
}

int		get_lower_value(t_stack *stack)
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

int		select_pivot(t_stack *stack, int position)
{
	int			pivot;
	int			i;

	i = 1;
	pivot = get_lower_value(stack);
	while (i < position)
	{
		pivot = get_next_value(stack, pivot);
		i++;
	}
	return (pivot);
}
