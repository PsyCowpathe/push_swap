/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/10/19 16:58:10 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting(t_stack *a_stack, t_stack *b_stack, t_inst *list)
{
	if (a_stack->len == 5)
	{
		high_five(a_stack, b_stack, list);
		print_instruction(list);
		return (delete_stack(a_stack, b_stack, list, 1));
	}
	else if (a_stack->len == 3)
	{
		mini_sort(a_stack, list);
		print_instruction(list);
		return (delete_stack(a_stack, b_stack, list, 1));
	}
	rush_b(a_stack, b_stack, list);
	if (is_sort(a_stack) == 0)
		mini_sort(a_stack, list);
	counter_b(a_stack, b_stack, list);
	print_instruction(list);
	return (delete_stack(a_stack, b_stack, list, 1));
}

int	push_swap(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	t_inst		*list;

	a_stack = NULL;
	b_stack = NULL;
	list = NULL;
	a_stack = create_a_stack(argc, argv);
	if (a_stack == NULL)
		return (delete_stack(a_stack, b_stack, list, 0));
	if (a_stack_inst(a_stack) == 0)
		return (delete_stack(a_stack, b_stack, list, 0));
	if (check_duplicate(a_stack) == 0)
		return (delete_stack(a_stack, b_stack, list, 0));
	if (is_sort(a_stack) == 1)
		return (delete_stack(a_stack, b_stack, list, 1));
	b_stack = create_b_stack();
	if (b_stack == NULL)
		return (delete_stack(a_stack, b_stack, list, 0));
	if (b_stack_inst(b_stack) == 0)
		return (delete_stack(a_stack, b_stack, list, 0));
	list = create_inst_list();
	if (list == NULL)
		return (delete_stack(a_stack, b_stack, list, 0));
	return (sorting(a_stack, b_stack, list));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (check_int(argc - 1, argv + 1) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (push_swap(argc, argv) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
