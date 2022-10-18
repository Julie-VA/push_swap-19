/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:16:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/28 10:41:54 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				cont;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

/*
** operations
*/
int			sa(t_stacks *stacks, int mod);
int			sb(t_stacks *stacks, int mod);
int			ss(t_stacks *stacks, int mod);
int			pa(t_stacks *stacks, int mod);
int			pb(t_stacks *stacks, int mod);
int			ra(t_stacks *stacks, int mod);
int			rb(t_stacks *stacks, int mod);
int			rr(t_stacks *stacks, int mod);
int			rra(t_stacks *stacks, int mod);
int			rrb(t_stacks *stacks, int mod);
int			rrr(t_stacks *stacks, int mod);

/*
** utils
*/
int			ft_atoi(const char *nptr, int *j, t_list **tmp);
int			ft_strcmp(char *s1, char *s2);
int			ft_lstsize(t_list *lst);
int			ft_lstlast(t_list *lst);

/*
** set_stacks
*/
t_stacks	*setstacks(char	**argv, int *count);

/*
** free_stacks
*/
void		freestacks(t_stacks *stacks);

/*
** modgnl & modgnl_utils
*/
int			get_next_line(int fd, char **line);
int			ft_strchr(const char *s, int c);
int			ft_modstrlen(const char *s, int mod);
char		*ft_strjoin(char const *s1, char const *s2);

/*
** errors
*/
void		print_error(t_stacks *stacks);
int			dupcheck(t_list	*a);
int			sorted(t_list *a, int count);

/*
** tabinit_sort
*/
int			*lst_tab(t_list *a, int count);

/*
** algos3
*/
void		alg3(t_stacks *s);
void		rev_alg3(t_stacks *s);
void		mod_rev_alg3(t_stacks *s);

/*
** algos4_6
*/
void		alg4(t_stacks *stacks);
void		alg5_6(t_stacks *stacks, int count);

/*
** algos_small
*/
void		alg_small(t_stacks *stacks, int count);

/*
** algos_big
*/
void		algo_big(t_stacks *stacks, int count);

/*
** algos_huge
*/
void		algo_huge(t_stacks *stacks, int count);

/*
** algos_bh_utils
*/
void		rotate_ab(t_stacks *stacks, int val, int mod, int write);
void		rotate_b(t_stacks *stacks, int *max, int *min, int rota);
void		empty_b(t_stacks *stacks, int *max, int *min, int rota);
void		make_part(int *tab, int *part, int partsize);

/*
** algos_bh_get_rots
*/
int			get_rot_a(t_stacks *stacks, int *part, int size, int partsize);
int			get_rot_b_max(t_stacks *stacks, int max, int size);
int			get_rot_b(t_stacks *stacks, int cont, int size);

/*
** algos_bh_write_rots
*/
void		write_rotations(int rota, int rotb);

/*
** algos_utils
*/
int			is_in_part(int cont, int *part, int partsize);

#endif