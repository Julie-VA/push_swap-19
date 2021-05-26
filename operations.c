/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:27:17 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/26 14:30:33 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst1, t_list *lst2)
{
	int	tmp;

	tmp = lst1->cont;
	lst1->cont = lst2->cont;
	lst2->cont = tmp;
}

void	pb(t_stacks *stacks)
{
	t_list		*tmp;

	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
}
