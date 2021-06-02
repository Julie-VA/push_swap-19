/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:56:40 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 11:31:53 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	printlst(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d\n", lst->cont);
// 		lst = lst->next;
// 	}
// 	printf("\n");
// }

void	alg3(t_stacks *stacks)
{
	if (stacks->a->cont > stacks->a->next->cont
		&& stacks->a->next->cont < stacks->a->next->next->cont
		&& stacks->a->cont < stacks->a->next->next->cont)
		sa(stacks, 1);
	if (stacks->a->cont > stacks->a->next->cont
		&& stacks->a->next->cont < stacks->a->next->next->cont
		&& stacks->a->cont > stacks->a->next->next->cont)
		ra(stacks, 1);
	if (stacks->a->cont < stacks->a->next->cont
		&& stacks->a->next->cont > stacks->a->next->next->cont
		&& stacks->a->cont > stacks->a->next->next->cont)
		rra(stacks, 1);
	if (stacks->a->cont < stacks->a->next->cont
		&& stacks->a->next->cont > stacks->a->next->next->cont
		&& stacks->a->cont < stacks->a->next->next->cont)
	{
		rra(stacks, 1);
		sa(stacks, 1);
	}
	if (stacks->a->cont > stacks->a->next->cont
		&& stacks->a->next->cont > stacks->a->next->next->cont)
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
}

void	alg4(t_stacks *stacks)
{
	pb(stacks, 1);
	pb(stacks, 1);
	if (stacks->a->cont > stacks->a->next->cont
		&& stacks->b->cont < stacks->b->next->cont)
		ss(stacks, 1);
	else
	{
		if (stacks->a->cont > stacks->a->next->cont)
			sa(stacks, 1);
		if (stacks->b->cont < stacks->b->next->cont)
			sb(stacks, 1);
	}
	pa(stacks, 1);
	if (stacks->a->cont > stacks->a->next->next->cont)
	{
		if (stacks->b->cont < stacks->a->next->next->cont)
			ra(stacks, 1);
		else
		{
			pa(stacks, 1);
			ra(stacks, 1);
			ra(stacks, 1);
			return ;
		}
	}
	else if (stacks->a->cont > stacks->a->next->cont)
		sa(stacks, 1);
	pa(stacks, 1);
	if (stacks->a->cont > stacks->a->next->cont)
		sa(stacks, 1);
}