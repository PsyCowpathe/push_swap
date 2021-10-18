/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:01:36 by agirona           #+#    #+#             */
/*   Updated: 2021/10/18 20:47:16 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

typedef struct s_element
{
	int					value;
	struct s_element	*next;
}					t_element;

typedef struct s_stack
{
	t_element	*first;
	t_element	*last;
	t_element	*before;
	int			len;
	int			pivot;
	int			position;
}				t_stack;

//parsing

int		check_int(int len, char **list);
int		check_duplicate(t_stack *stack);
int		is_sort(t_stack *stack);

//delete_stack

int		delete_stack(t_stack *a_stack, t_stack *b_stack, int ret);
void	delete_element(t_element *element);

//stack_init

t_stack	*create_b_stack(void);
t_stack	*create_a_stack(int argc, char **argv);
void	get_last_element(t_stack *stack);

//swap_instruction

int		swap(t_stack *stack);
int		push(t_stack *sender, t_stack *receiver);
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);

//utility

void	ft_puterror(char *str);
void	*create_element(int content);

#endif
