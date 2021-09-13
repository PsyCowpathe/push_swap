/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/09/13 20:41:49 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

#include <stdio.h>

void	select_pivot(t_stack *stack)
{
	int			max;
	int			min;
	float		pivot;
	t_element	*current;

	max = stack->first->value;
	min = stack->first->value;
	current = stack->first;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	pivot = ((((max - min) * 0.5) * 0.5) * 0.5);
	pivot = (int)pivot + min;
	dprintf(1, "pivot = %f", pivot);
}

void	create_stack(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;

	a_stack = malloc(sizeof(*a_stack)); //protection
	a_stack->first = create_element(ft_atoi(argv[1]));
	init_stack(a_stack, argc, argv);
	a_stack->len = argc - 1;
	get_last_element(a_stack);
	b_stack = malloc(sizeof(*b_stack)); //protection
	b_stack->first = NULL;
	b_stack->last = NULL;
	b_stack->before_last = NULL;
	b_stack->len = 0;

	print_data(a_stack, b_stack);
	reverse_rotate(a_stack);
	print_data(a_stack, b_stack);
	select_pivot(a_stack);

	delete_stack(a_stack, b_stack);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	create_stack(argc, argv);
	return (1);
}
