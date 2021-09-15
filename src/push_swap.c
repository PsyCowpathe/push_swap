/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/09/15 19:50:45 by agirona          ###   ########lyon.fr   */
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
	int			len;
	t_element	*current;
	int			pivot2;

	if (a_stack->len <= 100)
		percent = 0.13125 * 3;
	else
		percent = 0.13125;
	while (a_stack->len > 2)
	{
		len = a_stack->len;
		a_stack->position = a_stack->len * percent;
		a_stack->pivot = select_pivot(a_stack, a_stack->position);
		pivot2 = select_pivot(a_stack, a_stack->position * 0.5);
		ft_putstr("pivot1 = ");
		ft_putnbr(a_stack->pivot);
		ft_putstr(" pivot2 = ");
		ft_putnbr(a_stack->position / 2);
		ft_putchar('\n');
		i = 0;
		while (i < a_stack->position && a_stack->position != 1)
		{
			current = a_stack->first;
			if (current->value <= a_stack->pivot)
			{
				push(a_stack, b_stack);
				if (b_stack->first->value < pivot2)
					rotate(b_stack);
				i++;
			}
			else
				rotate(a_stack);
		}
		if (percent < 0.70)
			percent += 0.195;
		print_data(a_stack, b_stack);
	}
}

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
	print_stack(stack);
	ft_putstr("valeur envoye = ");
	ft_putnbr(value);
	ft_putstr(" position = ");
	ft_putnbr(position);
	ft_putstr(" valeur = ");
	ft_putnbr(find);
	return (position);
}

void	counter_b(t_stack *a_stack, t_stack *b_stack)
{
	int			position;
	int			i;

	while (b_stack->len != 0)
	{
		position = get_next_highter_value(b_stack, a_stack->first->value);
		if (position < b_stack->len * 0.5)
		{
			i = 1;
			while (i < position)
			{
				rotate(b_stack);
				i++;
			}
		}
		else
		{
			i = b_stack->len + 1;
			while (i > position)
			{
				reverse_rotate(b_stack);
				i--;
			}
		}
		ft_putstr("valeur push = ");
		ft_putnbr(b_stack->first->value);
		ft_putchar('\n');
		push(b_stack, a_stack);
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
	//check if A is sorted
	rush_b(a_stack, b_stack);
	counter_b(a_stack, b_stack);
	ft_putchar('\n');
	ft_putchar('\n');
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
