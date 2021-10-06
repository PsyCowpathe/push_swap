/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMP_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:21:09 by agirona           #+#    #+#             */
/*   Updated: 2021/10/06 16:22:53 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *list)
{
	t_element	*current;

	current = list->first;
	while (current != NULL)
	{
		ft_putnbr((int)current->value);
		ft_putchar(' ');
		current = current->next;
	}
}

void	print_two(t_stack *b_stack)
{
	ft_putstr("\nStack B : ");
	print_stack(b_stack);
	ft_putstr("   Len = ");
	ft_putnbr(b_stack->len);
	ft_putstr(" before = ");
	if (b_stack->before_last != NULL)
		ft_putnbr(b_stack->before_last->value);
	else
		ft_putstr("NULL");
	ft_putstr("   Last = ");
	if (b_stack->last)
		ft_putnbr(b_stack->last->value);
	else
		ft_putstr("NULL");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
}

void	print_data(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("Stack A : ");
	print_stack(a_stack);
	ft_putstr("   Len = ");
	ft_putnbr(a_stack->len);
	ft_putstr(" before = ");
	if (a_stack->before_last != NULL)
		ft_putnbr(a_stack->before_last->value);
	else
		ft_putstr("NULL");
	ft_putstr("   Last = ");
	if (a_stack->last)
		ft_putnbr(a_stack->last->value);
	else
		ft_putstr("NULL");
	print_two(b_stack);
}
