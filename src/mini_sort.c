/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:24:07 by agirona           #+#    #+#             */
/*   Updated: 2021/10/18 17:32:41 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	low_low(t_stack *stack, t_inst *list)
{
	if (stack->before->value < stack->first->value
		&& stack->before->value < stack->last->value)
	{
		if (stack->first->value < stack->last->value)
			swap(stack, list);
		else
			rotate(stack, list);
		return (1);
	}
	return (0);
}

int	hight_hight(t_stack *stack, t_inst *list)
{
	if (stack->before->value > stack->first->value
		&& stack->before->value > stack->last->value)
	{
		if (stack->first->value < stack->last->value)
		{
			reverse_rotate(stack, list);
			swap(stack, list);
		}
		else
			reverse_rotate(stack, list);
		return (1);
	}
	return (0);
}

void	mini_sort(t_stack *stack, t_inst *list)
{
	if (stack->len == 2)
		swap(stack, list);
	else
	{
		if (low_low(stack, list) == 0)
		{
			if (hight_hight(stack, list) == 0)
			{
				swap(stack, list);
				reverse_rotate(stack, list);
			}
		}
	}
}

void	high_five(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	int		position;
	int		tmp;

	while (a_stack->len > 3)
	{
		tmp = get_smaller_value(a_stack);
		get_next_value(a_stack, (long)tmp - 1, &position);
		if (position > a_stack->len * 0.5)
			while (position++ < a_stack->len + 1)
				reverse_rotate(a_stack, list);
		else
			while (position-- > 1)
				rotate(a_stack, list);
		push(a_stack, b_stack, list);
	}
	if (is_sort(a_stack) == 0)
		mini_sort(a_stack, list);
	if (b_stack->first->value < b_stack->first->next->value)
		swap(b_stack, list);
	push(b_stack, a_stack, list);
	push(b_stack, a_stack, list);
}
