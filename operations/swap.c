/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:16:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/26 16:16:57 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a->cont;
	stacks->a->cont = stacks->a->next->cont;
	stacks->a->next->cont = tmp;
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->b->cont;
	stacks->b->cont = stacks->b->next->cont;
	stacks->b->next->cont = tmp;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
