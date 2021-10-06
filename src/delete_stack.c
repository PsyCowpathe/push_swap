/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:31:24 by agirona           #+#    #+#             */
/*   Updated: 2021/10/06 16:47:14 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_astack(t_stack *a_stack)
{
	t_element		*current;

	current = a_stack->first;
	while (current != NULL)
	{
		current = current->next;
		delete_element(a_stack->first);
		a_stack->first = current;
	}
	free(a_stack);
}

void	clean_bstack(t_stack *b_stack)
{
	t_element		*current;

	current = b_stack->first;
	while (current != NULL)
	{
		current = current->next;
		delete_element(b_stack->first);
		b_stack->first = current;
	}
	free(b_stack);
}

void	clean_inst(t_inst *list)
{
	t_inst_element	*current;

	current = list->first;
	while (current != NULL)
	{
		current = current->next;
		delete_inst_element(list->first);
		list->first = current;
	}
	free(list);
}

int	delete_stack(t_stack *a_stack, t_stack *b_stack, t_inst *list, int ret)
{
	if (a_stack != NULL)
		clean_astack(a_stack);
	if (b_stack != NULL)
		clean_bstack(b_stack);
	if (list != NULL)
		clean_inst(list);
	return (ret);
}
