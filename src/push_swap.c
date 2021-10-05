/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/10/05 21:21:37 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_stack_inst(t_stack *stack)
{
	int		i;

	i = 0;
	stack->inst = malloc(sizeof(char *) * 4);
	stack->inst[0] = ft_strdup("sa\n");
	stack->inst[1] = ft_strdup("pa\n");
	stack->inst[2] = ft_strdup("ra\n");
	stack->inst[3] = ft_strdup("rra\n");
}

void	b_stack_inst(t_stack *stack)
{
	int		i;

	i = 0;
	stack->inst = malloc(sizeof(char *) * 4);
	stack->inst[0] = ft_strdup("sb\n");
	stack->inst[1] = ft_strdup("pb\n");
	stack->inst[2] = ft_strdup("rb\n");
	stack->inst[3] = ft_strdup("rrb\n");
}

int	create_stack(int argc, char **argv)
{
	//t_list		*list;
	t_stack		*a_stack;
	t_stack		*b_stack;
	t_inst_list	*list;

	list = malloc(sizeof(*list));
	list->first = NULL;
	list->len = 0;
	a_stack = malloc(sizeof(*a_stack)); //protection
	a_stack->first = create_element(ft_atoi(argv[1]));
	init_stack(a_stack, argc, argv);
	a_stack->len = argc - 1;
	get_last_element(a_stack);
	a_stack_inst(a_stack);
	b_stack = malloc(sizeof(*b_stack)); //protection
	b_stack->first = NULL;
	b_stack->last = NULL;
	b_stack->before_last = NULL;
	b_stack->len = 0;
	b_stack_inst(b_stack);

	print_data(a_stack, b_stack);
	ft_putchar('\n');
	rush_b(a_stack, b_stack, list);;
	if (is_sort(a_stack) == 0)
		mini_sort(a_stack, list);
	counter_b(a_stack, b_stack, list);
	ft_putchar('\n');
	ft_putchar('\n');
	print_data(a_stack, b_stack);
	print_instruction(list);
	if (is_sort(a_stack) == 1)
		ft_putstr("DONE");
	else
		ft_putstr("FAIL");
	delete_stack(a_stack, b_stack, list);
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
