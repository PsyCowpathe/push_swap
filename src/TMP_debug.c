/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMP_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:21:09 by agirona           #+#    #+#             */
/*   Updated: 2021/10/05 21:21:34 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction(t_inst_list *list)
{
	t_inst_element *current;

	current = list->first;
	while (current != NULL)
	{
		ft_putstr(current->str);
		current = current->next;
	}
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

int		is_sort(t_stack *stack)
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
