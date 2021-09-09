/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 04:11:41 by agirona           #+#    #+#             */
/*   Updated: 2021/09/09 04:16:16 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:25:36 by agirona           #+#    #+#             */
/*   Updated: 2021/09/09 04:09:24 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_list(char *value)
{
	t_stack		*list;
	t_element	*element;

	list = malloc(sizeof(*list)); //protection
	element = malloc(sizeof(*element)); // protection
	list->first = element;
	element->value = ft_atoi(value);
	element->next = NULL;
	return (list);
}

t_element	*create_element(char *value)
{
	t_element	*new;

	new = malloc(sizeof(*new)); //protection
	new->value = ft_atoi(value);
	new->next = NULL;
	return (new);
}

void	init_list(t_stack *list, int argc, char **argv)
{
	int		i;
	t_element	*new;
	t_element	*current;

	i = 1;
	current = list->first;
	while (i < argc)
	{
		new = create_element(argv[i]); //protection
		current->next = new;
		current = current->next;
		i++;
	}
}

void	print_list(t_stack *list)
{
	t_element	*current;

	current = list->first;
	while (current != NULL)
	{
		ft_putnbr(current->value);
		current = current->next;
	}
}

int		main(int argc, char **argv)
{
	t_stack	*list;

	if (argc == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	list = create_list(argv[1]);
	init_list(list, argc, argv);
	print_list(list);
	return (1);
}
