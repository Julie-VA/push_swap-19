/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:56:40 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 10:10:43 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
