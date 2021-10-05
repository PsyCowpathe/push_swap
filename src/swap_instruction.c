/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:23:33 by agirona           #+#    #+#             */
/*   Updated: 2021/10/05 21:21:36 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*create_inst_element(char *content)
{
	t_inst_element	*new;

	new = malloc(sizeof(*new)); //protection
	new->str = content;
	new->next = NULL;
	return (new);
}

void	add_list(t_inst_list *list, char *str)
{
	t_inst_element	*new;
	t_inst_element	*current;

	new = create_inst_element(str);
	list->len++;
	if (list->first == NULL)
		list->first = new;
	else
	{
		current = list->first;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

int		swap(t_stack *stack, t_inst_list *list)
{
	t_element	*new_first;
	t_element	*tmp;

	if (stack->len < 2)
		return (0);
	tmp = stack->first->next->next;
	new_first = stack->first->next;
	new_first->next = stack->first;
	new_first->next->next = tmp;
	stack->first = new_first;
	get_last_element(stack);
	add_list(list, stack->inst[0]);
	return (1);
}

int		push(t_stack *sender, t_stack *receiver, t_inst_list *list)
{
	t_element	*tmp;

	if (sender->len == 0)
		return (0);
	tmp = receiver->first;
	receiver->first = create_element(sender->first->value);
	receiver->first->next = tmp;
	tmp = sender->first;
	receiver->len++;
	sender->first = sender->first->next;
	delete_element(tmp);
	sender->len--;
	get_last_element(receiver);
	get_last_element(sender);
	add_list(list, receiver->inst[1]);
	return (1);
}

int		rotate(t_stack *stack, t_inst_list *list)
{
	t_element	*tmp;

	if (stack->len <= 1)
		return (0);
	tmp = stack->first->next;
	stack->first->next = NULL;
	stack->last->next = stack->first;
	stack->first = tmp;
	get_last_element(stack);
	add_list(list, stack->inst[2]);
	return (1);
}

int		reverse_rotate(t_stack *stack, t_inst_list *list)
{
	if (stack->len <= 1)
		return (0);	
	stack->before_last->next = NULL;
	stack->last->next = stack->first;
	stack->first = stack->last;
	get_last_element(stack);
	add_list(list, stack->inst[3]);
	return (1);
}
