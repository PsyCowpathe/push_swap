/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:05:49 by agirona           #+#    #+#             */
/*   Updated: 2021/10/12 17:40:46 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	delete_element(t_element *element)
{
	if (element)
	{
		free(element);
		element = NULL;
	}
}

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

int	delete_stack(t_stack *a_stack, t_stack *b_stack, int ret)
{
	if (a_stack != NULL)
		clean_astack(a_stack);
	if (b_stack != NULL)
		clean_bstack(b_stack);
	return (ret);
}
