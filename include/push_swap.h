/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 02:30:11 by agirona           #+#    #+#             */
/*   Updated: 2021/10/11 14:01:27 by agirona          ###   ########lyon.fr   */
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
	char		**inst;
	t_element	*first;
	t_element	*last;
	t_element	*before;
	int			len;
	int			pivot;
	int			position;
	float		percent;
}				t_stack;

typedef struct s_inst_element
{
	char					*str;
	struct s_inst_element	*next;
}				t_inst_element;

typedef struct s_inst
{
	t_inst_element	*first;
	int				len;
}				t_inst;

//stack_utils

void	*create_element(int content);
void	delete_element(t_element *element);
int		init_stack(t_stack *list, int argc, char **argv);
void	get_last_element(t_stack *stack);

//swap_instruction

int		swap(t_stack *a_stack, t_inst *list);
int		push(t_stack *first_stack, t_stack *second_stack, t_inst *list);
int		rotate(t_stack	*stack, t_inst *list);
int		reverse_rotate(t_stack *stack, t_inst *list);

//magic_sort

void	rush_b(t_stack *a_stack, t_stack *b_stack, t_inst *list);
void	counter_b(t_stack *a_stack, t_stack *b_stack, t_inst *list);

//parsing

int		check_int(int len, char **list);
int		check_duplicate(t_stack *stack);

//stack_finder

int		get_next_highter_value(t_stack *stack);
int		get_next_value(t_stack *stack, int value, int *position);
int		get_smaller_value(t_stack *stack);
int		get_bigger_value(t_stack *stack, int *position);
int		select_pivot(t_stack *stack, int position);

//stack_init

int		a_stack_inst(t_stack *stack);
int		b_stack_inst(t_stack *stack);
t_stack	*create_a_stack(int argc, char **argv);
t_stack	*create_b_stack(void);
t_inst	*create_inst_list(void);

//instruction

void	print_instruction(t_inst *list);
void	delete_inst_element(t_inst_element *element);
void	*create_inst_element(char *content);
int		add_list(t_inst *list, char *str);

//utility

int		is_sort(t_stack *stack);

//delete_stack

int		delete_stack(t_stack *a_stack, t_stack *b_stack, t_inst *list, int ret);

//mini_sort

void	mini_sort(t_stack *stack, t_inst *list);

#endif
