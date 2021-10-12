/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:50:41 by agirona           #+#    #+#             */
/*   Updated: 2021/10/12 18:07:53 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	is_it_b(char *str, t_stack *a_stack, t_stack *b_stack)
{
	if (ft_strncmp(str, "pb", 2) == 0)
		push(a_stack, b_stack);
	else if (ft_strncmp(str, "sp", 2) == 0)
		swap(b_stack);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate(b_stack);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		reverse_rotate(b_stack);
	else if (ft_strncmp(str, "rr", 2) == 0)
	{
		rotate(b_stack);
		rotate(a_stack);
	}
}

void	is_it_a(char *str, t_stack *a_stack, t_stack *b_stack)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		push(b_stack, a_stack);
	else if (ft_strncmp(str, "sa", 2) == 0)
		swap(a_stack);
	else if (ft_strncmp(str, "ra", 2) == 0)
		rotate(a_stack);
	else if (ft_strncmp(str, "rra", 3) == 0)
		reverse_rotate(a_stack);
	else
		is_it_b(str, a_stack, b_stack);
}

void	sir_yes_sir(t_stack *a_stack, t_stack *b_stack)
{
	char	*tmp;

	while (get_next_line(0, &tmp) == 1)
	{
		is_it_a(tmp, b_stack, a_stack);
		free(tmp);
	}
	free(tmp);
}

int	checker(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = create_a_stack(argc, argv);
	if (a_stack == NULL)
		return (delete_stack(a_stack, b_stack, 0));
	if (check_duplicate(a_stack) == 0)
		return (delete_stack(a_stack, b_stack, 0));
	if (is_sort(a_stack) == 1)
		return (delete_stack(a_stack, b_stack, 1));
	b_stack = create_b_stack();
	if (b_stack == NULL)
		return (delete_stack(a_stack, b_stack, 0));
	sir_yes_sir(a_stack, b_stack);
	if (is_sort(a_stack) == 1)
		ft_putstr("OK");
	else
		ft_putstr("KO");
	return (delete_stack(a_stack, b_stack, 1));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_puterror("Error\n");
		return (0);
	}
	if (check_int(argc - 1, argv + 1) == 0)
	{
		ft_puterror("Error\n");
		return (0);
	}
	if (checker(argc, argv) == 0)
	{
		ft_puterror("Error\n");
		return (0);
	}
}
