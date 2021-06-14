/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:13:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/14 14:33:22 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_part(int cont, int *part, int partsize)
{
	int	i;

	i = 0;
	while (i < partsize)
	{
		if (cont == part[i])
			return (1);
		i++;
	}
	return (0);
}

int	end_algo_med(t_stacks *stacks, int *tab, int j, int size)
{
	while (ft_lstsize(stacks->a) <= size && ft_lstsize(stacks->a) > 3)
	{
		if (stacks->a->cont == tab[j])
		{
			j++;
			pb(stacks, 1);
		}
		else
			ra(stacks, 1);
		if (ft_lstsize(stacks->a) == 3)
		{
			alg3(stacks);
			return (1);	
		}
	}
	return (0);
}

void	end_algo_big(t_stacks *stacks, int *tab, int j, int max)
{
	while (stacks->b->cont != max)
		rrb(stacks, 1);
	while (ft_lstsize(stacks->a) > 3)
	{
		while (stacks->a->cont != tab[j])
		{
			if (stacks->a->next->cont == tab[j] || stacks->a->next->next->cont == tab[j])
				ra(stacks, 1);
			else
				rra(stacks, 1);
		}
		pb(stacks, 1);
		j++;
	}
}

static int	get_half_ra(t_stacks *stacks, int *part, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stacks->a;
	while (i < size / 2)
	{
		if (is_in_part(tmp->cont, part, size))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

static int	get_half_rra(t_stacks *stacks, int *part, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stacks->a;
	while (i < size / 2)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (is_in_part(tmp->cont, part, size))
			return (size - i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	get_half(t_stacks *stacks, int *part)
{
	int	size;
	int	rtnra;
	int	rtnrra;

	size = ft_lstsize(stacks->a);
	rtnra = get_half_ra(stacks, part, size);
	rtnrra = get_half_rra(stacks, part, size);
	if (rtnra < rtnrra && rtnra > 0)
		return (1);
	else
		return (0);
}
