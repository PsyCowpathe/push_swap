/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:08:08 by agirona           #+#    #+#             */
/*   Updated: 2021/10/12 17:41:18 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*create_element(int content)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

int	init_stack(t_stack *list, int argc, char **argv)
{
	int			i;
	t_element	*new;
	t_element	*current;

	i = 2;
	current = list->first;
	list->last = NULL;
	list->before = NULL;
	while (i < argc)
	{
		new = create_element(ft_atoi(argv[i]));
		if (new == NULL)
			return (0);
		current->next = new;
		current = current->next;
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
	a_stack->first = create_element(ft_atoi(argv[1]));
	if (init_stack(a_stack, argc, argv) == 0)
	{
		free(a_stack);
		return (NULL);
	}
	a_stack->len = argc - 1;
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
