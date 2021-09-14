/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/09/14 19:42:31 by agirona          ###   ########lyon.fr   */
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

void	rush_b(t_stack *a_stack, t_stack *b_stack)
{
	int			i;
	float		percent;
	t_element	*current;

	percent = 0.13125;
	while (a_stack->len > 2)
	{
		a_stack->position = a_stack->len * percent;
		a_stack->pivot = select_pivot(a_stack, a_stack->position);
		ft_putstr("pivot = ");
		ft_putnbr(a_stack->pivot);
		ft_putchar('\n');
		i = 0;
		while (i < a_stack->position && a_stack->position != 1)
		{
			current = a_stack->first;
			if (current->value <= a_stack->pivot)
			{
				push(a_stack, b_stack);
				i++;
			}
			else
				rotate(a_stack);
		}
		percent += 0.425;
	}
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
	ft_putchar('\n');
	rush_b(a_stack, b_stack);
	print_data(a_stack, b_stack);




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
