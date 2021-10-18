/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:45:05 by agirona           #+#    #+#             */
/*   Updated: 2021/10/18 20:46:06 by agirona          ###   ########lyon.fr   */
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

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

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
