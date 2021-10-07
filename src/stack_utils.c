/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:45:05 by agirona           #+#    #+#             */
/*   Updated: 2021/10/07 19:19:49 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	delete_element(t_element *element)
{
	if (element)
	{
		free(element);
		element = NULL;
	}
}

void	*create_element(int content)
{
	t_element	*new;

	new = NULL;
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
