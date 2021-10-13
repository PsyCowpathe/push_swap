/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:58 by agirona           #+#    #+#             */
/*   Updated: 2021/10/13 15:20:10 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	navigate(t_stack *a_stack, t_inst *list)
{
	if (a_stack->last->value <= a_stack->pivot)
		reverse_rotate(a_stack, list);
	else
		rotate(a_stack, list);
}

void	rush_b(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int			i;
	t_element	*current;

	while (a_stack->len > 2 && is_sort(a_stack) == 0)
	{
		a_stack->position = a_stack->len * a_stack->percent;
		a_stack->pivot = select_pivot(a_stack, a_stack->position);
		b_stack->pivot = select_pivot(a_stack, a_stack->position * 0.5);
		i = 0;
		while (i < a_stack->position)
		{
			current = a_stack->first;
			if (current->value <= a_stack->pivot)
			{
				push(a_stack, b_stack, list);
				if (b_stack->first->value <= b_stack->pivot)
					rotate(b_stack, list);
				i++;
			}
			else
				navigate(a_stack, list);
		}
		if (a_stack->percent < 0.50)
			a_stack->percent += 0.0195;
	}
}

void	counter_b(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int			position;

	while (b_stack->len != 0)
	{
		get_bigger_value(b_stack, &position);
		if (position == 1)
			push(b_stack, a_stack, list);
		else if (position == 2)
			swap(b_stack, list);
		else if (position <= b_stack->len * 0.5)
			rotate(b_stack, list);
		else if (position > b_stack->len * 0.5)
			reverse_rotate(b_stack, list);
	}
}
