/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:16:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/31 18:01:28 by rvan-aud         ###   ########.fr       */
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
int			sa(t_stacks *stacks);
int			sb(t_stacks *stacks);
int			ss(t_stacks *stacks);
int			pa(t_stacks *stacks);
int			pb(t_stacks *stacks);
int			ra(t_stacks *stacks);
int			rb(t_stacks *stacks);
int			rr(t_stacks *stacks);
int			rra(t_stacks *stacks);
int			rrb(t_stacks *stacks);
int			rrr(t_stacks *stacks);

//utils
int			ft_atoi(const char *nptr, t_stacks *stacks, int *j, t_list **tmp);
void		ft_lstclear(t_list **lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_strcmp(char *s1, char *s2);

//setstacks
t_stacks	*setstacks(char	**argv);
void		freestacks(t_stacks *stacks);

//gnl
int			get_next_line(int fd, char **line);
int			ft_strchr(const char *s, int c);
int			ft_modstrlen(const char *s, int mod);
char		*ft_strjoin(char const *s1, char const *s2);

//printerror
void		print_error(t_stacks *stacks);

#endif