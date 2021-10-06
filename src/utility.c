/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:18:02 by agirona           #+#    #+#             */
/*   Updated: 2021/10/06 16:22:55 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *stack)
{
	t_element	*current;
	t_element	*verif;

	current = stack->first;
	while (current != NULL)
	{
		verif = current;
		while (verif != NULL)
		{
			if (verif->value < current->value)
				return (0);
			verif = verif->next;
		}	
		current = current->next;
	}
	return (1);
}
