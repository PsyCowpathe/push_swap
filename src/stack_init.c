/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:03:15 by agirona           #+#    #+#             */
/*   Updated: 2021/10/06 16:29:22 by agirona          ###   ########lyon.fr   */
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

t_stack	*create_a_stack(int argc, char **argv)
{
	t_stack		*a_stack;

	a_stack = malloc(sizeof(*a_stack));
	if (a_stack == NULL)
		return (NULL);
	a_stack->first = create_element(ft_atoi(argv[1]));
	if (init_stack(a_stack, argc, argv) == 0)
		return (NULL);
	a_stack->len = argc - 1;
	get_last_element(a_stack);
	a_stack_inst(a_stack);
	return (a_stack);
}

t_stack	*create_b_stack(void)
{
	t_stack		*b_stack;

	b_stack = malloc(sizeof(*b_stack));
	if (b_stack == NULL)
		return (NULL);
	b_stack->first = NULL;
	b_stack->last = NULL;
	b_stack->before_last = NULL;
	b_stack->len = 0;
	b_stack_inst(b_stack);
	return (b_stack);
}

t_inst	*create_inst_list(void)
{
	t_inst	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->len = 0;
	return (list);
}
