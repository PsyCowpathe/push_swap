/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:24:07 by agirona           #+#    #+#             */
/*   Updated: 2021/10/11 15:51:56 by agirona          ###   ########lyon.fr   */
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
