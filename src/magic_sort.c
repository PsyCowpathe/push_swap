/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:58 by agirona           #+#    #+#             */
/*   Updated: 2021/10/06 16:02:10 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rush_b(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int			i;
	float		percent;
	t_element	*current;
	int			pivot2;

	if (a_stack->len <= 100)
		percent = 0.13125 * 3;
	else
		percent = 0.13125;
	while (a_stack->len > 3)
	{
		a_stack->position = a_stack->len * percent;
		a_stack->pivot = select_pivot(a_stack, a_stack->position);
		pivot2 = select_pivot(a_stack, a_stack->position * 0.5);
		i = 0;
		while (i < a_stack->position && a_stack->position != 1)
		{
			current = a_stack->first;
			if (current->value <= a_stack->pivot)
			{
				push(a_stack, b_stack, list);
				if (b_stack->first->value < pivot2)
					rotate(b_stack, list);
				i++;
			}
			else
			{
				if (get_next_highter_value(a_stack, get_lower_value(a_stack)) == 2)
					swap(a_stack, list);
				else if (get_next_highter_value(a_stack, get_lower_value(a_stack)) < a_stack->len * 0.5)
					rotate(a_stack, list);
				else
					reverse_rotate(a_stack, list);
			}
		}
		if (percent < 0.70)
			percent += 0.195;
		//print_data(a_stack, b_stack);
	}
}

void	counter_b(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int			position;
	int			i;

	while (b_stack->len != 0)
	{
		position = get_next_highter_value(b_stack, a_stack->first->value);
		if (position == 2)
		{
			swap(b_stack, list);
			//print_data(a_stack, b_stack);
		}
		else if (position < b_stack->len * 0.5)
		{
			i = 1;
			while (i < position)
			{
				rotate(b_stack, list);
				//print_data(a_stack, b_stack);
				i++;
			}
		}
		else
		{
			i = b_stack->len + 1;
			while (i > position && b_stack->len != 1)
			{
				reverse_rotate(b_stack, list);
				//print_data(a_stack, b_stack);
				i--;
			}
		}
		push(b_stack, a_stack, list);
		//print_data(a_stack, b_stack);
	}
}

void	mini_sort(t_stack *stack, t_inst *list)
{
	if (stack->len == 2)
		swap(stack, list);
	else
	{
		if (stack->before_last->value < stack->first->value && stack->before_last->value < stack->last->value)
		{
			if (stack->first->value < stack->last->value)
				swap(stack, list);
			else
				rotate(stack, list);
		}
		else if (stack->before_last->value > stack->first->value && stack->before_last->value > stack->last->value)
		{
			if (stack->first->value < stack->last->value)
			{
				reverse_rotate(stack, list);
				swap(stack, list);
			}
			else
				reverse_rotate(stack, list);

		}
		else
		{
			swap(stack, list);
			reverse_rotate(stack, list);
		}
	}
}
