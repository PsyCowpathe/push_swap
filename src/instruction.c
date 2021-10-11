/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:12:13 by agirona           #+#    #+#             */
/*   Updated: 2021/10/11 15:51:55 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction(t_inst *list)
{
	t_inst_element	*current;

	current = list->first;
	while (current != NULL)
	{
		if (current->next != NULL && ft_strncmp(current->str, "rb\n", 4) == 0
			&& ft_strncmp(current->next->str, "ra\n", 4) == 0)
		{
			ft_putstr("rr\n");
			current = current->next;
		}
		else
			ft_putstr(current->str);
		current = current->next;
	}
}

void	delete_inst_element(t_inst_element *element)
{
	if (element)
	{
		free(element);
		element = NULL;
	}
}

void	*create_inst_element(char *content)
{
	t_inst_element	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->str = content;
	new->next = NULL;
	return (new);
}

int	add_list(t_inst *list, char *str)
{
	t_inst_element	*new;
	t_inst_element	*current;

	new = create_inst_element(str);
	if (new == NULL)
		return (0);
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
	return (1);
}
