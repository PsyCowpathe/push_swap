/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/09/27 21:33:47 by agirona          ###   ########lyon.fr   */
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
	return (position);
}

void	rush_b(t_stack *a_stack, t_stack *b_stack)
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
				push(a_stack, b_stack);
				ft_putstr("pb\n");
				if (b_stack->first->value < pivot2)
				{
					rotate(b_stack);
					ft_putstr("rb\n");
				}
				i++;
			}
			else
			{
				if (get_next_highter_value(a_stack, get_lower_value(a_stack)) == 2)
				{
					swap(a_stack);
					ft_putstr("sa\n");
				}
				else if (get_next_highter_value(a_stack, get_lower_value(a_stack)) < a_stack->len * 0.5)
				{
					rotate(a_stack);
					ft_putstr("ra\n");
				}
				else
				{
					reverse_rotate(a_stack);
					ft_putstr("rra\n");
				}
			}
		}
		if (percent < 0.70)
			percent += 0.195;
		//print_data(a_stack, b_stack);
	}
}


void	counter_b(t_stack *a_stack, t_stack *b_stack)
{
	int			position;
	int			i;

	while (b_stack->len != 0)
	{
		position = get_next_highter_value(b_stack, a_stack->first->value);
		if (position == 2)
		{
			swap(b_stack);
			ft_putstr("sb\n");
			//print_data(a_stack, b_stack);
		}
		else if (position < b_stack->len * 0.5)
		{
			i = 1;
			while (i < position)
			{
				rotate(b_stack);
				ft_putstr("rb\n");
				//print_data(a_stack, b_stack);
				i++;
			}
		}
		else
		{
			i = b_stack->len + 1;
			while (i > position && b_stack->len != 1)
			{
				reverse_rotate(b_stack);
				ft_putstr("rrb\n");
				//print_data(a_stack, b_stack);
				i--;
			}
		}
		push(b_stack, a_stack);
		ft_putstr("pa\n");
		//print_data(a_stack, b_stack);
	}
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

void	mini_sort(t_stack *stack)
{
	if (stack->len == 2)
	{
		swap(stack);
		ft_putstr("sa\n");
	}
	else
	{
		if (stack->before_last->value < stack->first->value && stack->before_last->value < stack->last->value)
		{
			if (stack->first->value < stack->last->value)
			{
				swap(stack);
				ft_putstr("sa\n");
			}
			else
			{
				rotate(stack);
				ft_putstr("ra\n");

			}
		}
		else if (stack->before_last->value > stack->first->value && stack->before_last->value > stack->last->value)
		{
			if (stack->first->value < stack->last->value)
			{
				reverse_rotate(stack);
				ft_putstr("rra\n");
				swap(stack);
				ft_putstr("sa\n");
			}
			else
			{
				reverse_rotate(stack);
				ft_putstr("rra\n");

			}
		}
		else
		{
			swap(stack);
			ft_putstr("sa\n");
			reverse_rotate(stack);
			ft_putstr("rra\n");
		}
	}
}

int	create_stack(int argc, char **argv)
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
	if (is_sort(a_stack) == 0)
		mini_sort(a_stack);
	counter_b(a_stack, b_stack);
	ft_putchar('\n');
	ft_putchar('\n');
	print_data(a_stack, b_stack);


	if (is_sort(a_stack) == 1)
		ft_putstr("DONE");
	else
		ft_putstr("FAIL");
	delete_stack(a_stack, b_stack);
	return (1);
}

int		check_duplicate(int len, char **list)
{
	int		i;
	int		c;

	i = 0;
	while (i < len)
	{
		c = 0;
		while (c < len)
		{
			if (ft_strcmp(list[c], list[i]) == 0 && c != i)
			{
				ft_putstr("Error\nSeveral ");
				ft_putstr(list[c]);
				ft_putstr(" in program argument.");
				return (0);
			}
			c++;
		}
		i++;
	}
	return (1);
}

#include <stdio.h>

int		check_int(int len, char **list)
{
	int			i;
	int			c;
	int			isint;

	i = 0;
	while (i < len)
	{
		c = 0;
		while (list[i][c])
		{
			if ((list[i][c] == '-' && ft_isdigit(list[i][c + 1]) == 0)
				|| (c != 0 && ft_isdigit(list[i][c] == 0)))
				return (0);
			c++;
		}
		if (c == 0)
			return (0);
		ft_atoi_check(list[i], &isint);
		if (isint == 0)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (check_int(argc - 1, argv + 1) == 0)
	{
		ft_putstr("Error\nSome arguments aren't integer.");
		return (0);
	}
	if (check_duplicate(argc - 1, argv + 1) == 0)
		return (0);
	if (create_stack(argc, argv) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
