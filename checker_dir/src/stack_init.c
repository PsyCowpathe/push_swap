/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:08:08 by agirona           #+#    #+#             */
/*   Updated: 2021/10/18 20:47:18 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	cut_arg(t_stack *list, t_element **current, char *argv, int *c)
{
	t_element	*new;

	list->len++;
	new = create_element(ft_atoi(argv + *c));
	if (new == NULL)
		return (0);
	if (list->first == NULL)
	{
		list->first = new;
		*current = list->first;
	}
	else
	{
		(*current)->next = new;
		*current = (*current)->next;
	}
	while (argv[*c] != ' ' && argv[*c] != '\0')
		*c = *c + 1;
	return (1);
}

int	init_stack(t_stack *list, int argc, char **argv)
{
	int			i;
	int			c;
	t_element	*current;

	i = 1;
	current = NULL;
	list->last = NULL;
	list->before = NULL;
	while (i < argc)
	{
		c = 0;
		while (argv[i][c])
		{
			if (argv[i][c] == ' ')
				c++;
			if (argv[i][c] == '-' || argv[i][c] == '+'
				|| ft_isdigit(argv[i][c]) == 1)
			{
				if (cut_arg(list, &current, argv[i], &c) == 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

void	get_last_element(t_stack *stack)
{
	t_element	*current;

	current = stack->first;
	stack->before = NULL;
	stack->last = NULL;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (stack->len > 1 && current->next->next == NULL)
				stack->before = current;
		}
		stack->last = current;
		current = current->next;
	}
}

t_stack	*create_a_stack(int argc, char **argv)
{
	t_stack		*a_stack;

	a_stack = malloc(sizeof(*a_stack));
	if (a_stack == NULL)
		return (NULL);
	a_stack->first = NULL;
	a_stack->len = 0;
	if (init_stack(a_stack, argc, argv) == 0)
	{
		free(a_stack);
		return (NULL);
	}
	get_last_element(a_stack);
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
	b_stack->before = NULL;
	b_stack->len = 0;
	return (b_stack);
}
