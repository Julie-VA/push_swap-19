/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bh_get_rots.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:56:54 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/21 16:03:08 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rot_a(t_stacks *stacks, int *part, int size, int partsize)
{
	t_list	*tmp;
	int		i;
	int		top;
	int		bottom;

	tmp = stacks->a;
	i = 0;
	while (tmp)
	{
		if (is_in_part(tmp->cont, part, partsize))
		{
			top = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	tmp = stacks->a;
	i = 0;
	while (tmp)
	{
		if (is_in_part(tmp->cont, part, partsize))
			bottom = i;
		i++;
		tmp = tmp->next;
	}
	bottom = size - bottom;
	if (top < bottom)
		return (top);
	else
		return (-bottom);
}

int	get_rot_b_max(t_stacks *stacks, int max, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stacks->b;
	i = 0;
	while (tmp)
	{
		if (tmp->cont == max)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i > size / 2)
		return (-(size - i));
	else
		return (i);
}

int	get_rot_b(t_stacks *stacks, int cont, int size)
{
	t_stacks	*tmp;
	int			i;
	int			icpy;

	tmp = stacks;
	i = 0;
	while (i < size)
	{
		if (cont > tmp->b->cont && cont < ft_lstlast(tmp->b))
			break ;
		i++;
		rb(tmp, 0);
	}
	icpy = i;
	while (icpy)
	{
		rrb(tmp, 0);
		icpy--;
	}
	if (i > size / 2)
		return (-(size - i));
	else
		return (i);
}
