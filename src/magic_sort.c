/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:58 by agirona           #+#    #+#             */
/*   Updated: 2021/10/08 16:24:26 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	navigate(t_stack *a_stack, t_inst *list)
{
	int		position;

	position = get_next_highter_value(a_stack);
	if (position < a_stack->len * 0.5)
	{
		while (position != 1)
		{
			rotate(a_stack, list);
			position--;
		}
	}
	else
	{
		while (position != a_stack->len + 1)
		{
			reverse_rotate(a_stack, list);
			position++;
		}
	}
}

void	rush_b(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int			i;
	t_element	*current;

	while (a_stack->len > 3)
	{
		a_stack->position = a_stack->len * a_stack->percent;
		a_stack->pivot = select_pivot(a_stack, a_stack->position);
		b_stack->pivot = select_pivot(a_stack, a_stack->position * 0.5);
		i = 0;
		while (i < a_stack->position && a_stack->position != 1)
		{
			current = a_stack->first;
			if (current->value <= a_stack->pivot)
			{
				push(a_stack, b_stack, list);
				if (b_stack->first->value < b_stack->pivot)
					rotate(b_stack, list);
				i++;
			}
			else
				navigate(a_stack, list);
		}
		if (a_stack->percent < 0.70)
			a_stack->percent += 0.0195;
	}
}

void	counter_b(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int			position;
	int			i;

	while (b_stack->len != 0)
	{
		get_bigger_value(b_stack, &position);
		if (position < b_stack->len * 0.5)
		{
			i = 1;
			while (i++ < position)
				rotate(b_stack, list);
		}
		else
		{
			i = b_stack->len + 1;
			while (i-- > position && b_stack->len != 1)
				reverse_rotate(b_stack, list);
		}
		push(b_stack, a_stack, list);
	}
}
