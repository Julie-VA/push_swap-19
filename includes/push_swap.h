/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:16:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/07 10:08:50 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

//operations
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

//utils
int			ft_atoi(const char *nptr, t_stacks *stacks, int *j, t_list **tmp);
void		ft_lstclear(t_list **lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_strcmp(char *s1, char *s2);
int			ft_lstsize(t_list *lst);

//setstacks
t_stacks	*setstacks(char	**argv, int *count);
void		freestacks(t_stacks *stacks);

//gnl
int			get_next_line(int fd, char **line);
int			ft_strchr(const char *s, int c);
int			ft_modstrlen(const char *s, int mod);
char		*ft_strjoin(char const *s1, char const *s2);

//errors
void		print_error(t_stacks *stacks);
int			dupcheck(t_list	*a);
int			sorted(t_list *a, int count);

//algos
void		alg3(t_stacks *s);
void		rev_alg3(t_stacks *s);
void		alg4(t_stacks *stacks);
void		alg5_6(t_stacks *stacks, int count);
void		algo_small(t_stacks *stacks, int count);
void		algo(t_stacks *stacks, int count);

//tabinitsort
int			*lst_tab(t_list *a, int count);

//algos3
void		mod_rev_alg3(t_stacks *s);

#endif