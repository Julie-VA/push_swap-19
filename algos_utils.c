/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:13:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/14 15:35:15 by rvan-aud         ###   ########.fr       */
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

static int	get_half_r(t_list *lst, int *part, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (i < size / 2)
	{
		if (is_in_part(tmp->cont, part, size))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

static int	get_half_rr(t_list *lst, int *part, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
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

int	get_half(t_list *lst, int *part)
{
	int	size;
	int	rtn_r;
	int	rtn_rr;

	size = ft_lstsize(lst);
	rtn_r = get_half_r(lst, part, size);
	rtn_rr = get_half_rr(lst, part, size);
	if (rtn_r < rtn_rr && rtn_r > 0)
		return (1);
	else
		return (0);
}
