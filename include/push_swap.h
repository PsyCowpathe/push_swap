/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:30:11 by agirona           #+#    #+#             */
/*   Updated: 2021/09/14 19:42:31 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
	t_element	*before_last;
	int			len;
	int			pivot;
	int			position;
}				t_stack;

//stack_utils

t_element	*create_element(int value);
void		delete_element(t_element *element);
void		init_stack(t_stack *list, int argc, char **argv);
void		print_stack(t_stack *list); //tmp
void		delete_stack(t_stack *a_stack, t_stack *b_stack);
void		get_last_element(t_stack *stack);

//swap_instruction

int			swap(t_stack *a_stack);
int			push(t_stack *first_stack, t_stack *second_stack);
int			rotate(t_stack	*stack);
int			reverse_rotate(t_stack *stack);

#endif
