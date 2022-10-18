/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 23:59:35 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/27 15:37:36 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_small(t_stacks *stacks, int count)
{
	int	*tab;
	int	i;

	tab = lst_tab(stacks->a, count);
	i = 0;
	while (stacks->a->next->next->next)
	{
		if (stacks->a->cont == tab[i] && ++i)
			pb(stacks, 1);
		else if (stacks->a->next->cont == tab[i]
			&& stacks->a->cont == tab[i + 1])
			sa(stacks, 1);
		else if (stacks->a->next->cont == tab[i]
			|| stacks->a->next->next->cont == tab[i])
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
	free(tab);
	alg3(stacks);
	while (i-- > 0)
		pa(stacks, 1);
}
