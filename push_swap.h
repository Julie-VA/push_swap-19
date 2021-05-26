/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:16:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/26 14:30:38 by rvan-aud         ###   ########.fr       */
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

void	swap(t_list *lst1, t_list *lst2);
void	pb(t_stacks *stacks);

//utils
int		ft_atoi(const char *nptr);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif