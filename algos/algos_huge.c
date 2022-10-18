/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_huge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:37:08 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/21 15:58:41 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_huge_core(t_stacks *stacks, int *part, int *max, int *min)
{
	int	loop;
	int	partsize;
	int	rota;

	loop = 0;
	if (ft_lstsize(stacks->a) >= 40)
		partsize = 40;
	else
		partsize = ft_lstsize(stacks->a);
	while (loop < partsize)
	{
		rota = get_rot_a(stacks, part, ft_lstsize(stacks->a), 40);
		rotate_ab(stacks, rota, 0, 0);
		if (ft_lstsize(stacks->b) < 2)
			empty_b(stacks, max, min, rota);
		else
			rotate_b(stacks, max, min, rota);
		loop++;
	}
}

void	algo_huge(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[40];
	int	max;
	int	min;

	tab = lst_tab(stacks->a, count);
	max = 0;
	min = 0;
	while (ft_lstsize(stacks->a) > 0)
	{
		make_part(tab, part, 40);
		algo_huge_core(stacks, part, &max, &min);
		if (ft_lstsize(stacks->a) < 40 && ft_lstsize(stacks->a) > 0)
		{
			make_part(tab, part, ft_lstsize(stacks->a));
			algo_huge_core(stacks, part, &max, &min);
		}
	}
	free(tab);
	rotate_ab(stacks, get_rot_b_max(stacks, max, ft_lstsize(stacks->b)), 1, 1);
	while (stacks->b)
		pa(stacks, 1);
}
