/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 02:45:05 by agirona           #+#    #+#             */
/*   Updated: 2021/09/27 21:33:48 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_last_element(t_stack *stack)
{
	t_element	*current;

	current = stack->first;
	stack->before_last = NULL;
	stack->last = NULL;
	while (current != NULL)
	{
		if (current->next != NULL && stack->len > 1 && current->next->next == NULL)
			stack->before_last = current;
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

t_element	*create_element(int value)
{
	t_element	*new;

	new = malloc(sizeof(*new)); //protection
	new->value = value;
	new->next = NULL;
	return (new);
}

void	init_stack(t_stack *list, int argc, char **argv)
{
	int		i;
	t_element	*new;
	t_element	*current;

	i = 2;
	current = list->first;
	list->last = NULL;
	list->before_last = NULL;
	while (i < argc)
	{
		new = create_element(ft_atoi(argv[i])); //protection
		current->next = new;
		current = current->next;
		i++;
	}
}

void	delete_stack(t_stack *a_stack, t_stack *b_stack)
{
	t_element	*current;

	current = a_stack->first;
	while (current != NULL)
	{
		current = current->next;
		delete_element(a_stack->first);
		a_stack->first = current;
	}
	free(a_stack);
	current = b_stack->first;
	while (current != NULL)
	{
		current = current->next;
		delete_element(b_stack->first);
		b_stack->first = current;
	}
	free(b_stack);
}

void	print_stack(t_stack *list)
{
	t_element	*current;

	current = list->first;
	while (current != NULL)
	{
		ft_putnbr(current->value);
		ft_putchar(' ');
		current = current->next;
	}
}
