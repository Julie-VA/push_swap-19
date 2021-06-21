/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_re.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:26:22 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/17 17:26:22 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_b(t_stacks *stacks, int *max, int *min, int rota)
{
	while (rota > 0)
	{
		write(1, "ra\n", 3);
		rota--;
	}
	while (rota < 0)
	{
		write(1, "rra\n", 4);
		rota++;
	}
	if (ft_lstsize(stacks->b) == 0)
		pb(stacks, 1);
	else if (ft_lstsize(stacks->b) == 1)
	{
		pb(stacks, 1);
		if (stacks->b->cont < stacks->b->next->cont)
			sb(stacks, 1);
	}
	*max = stacks->b->cont;
	if (ft_lstsize(stacks->b) == 2)
		*min = stacks->b->next->cont;
}

static void	write_rotations(int rota, int rotb)
{
	int	check;
	int	rrcount;

	check = 0;
	if (rota < 0 && rotb < 0)
	{
		rota *= -1;
		rotb *= -1;
		check = 1;
	}
	if (rota > 0 && rotb > 0)
	{
		if (rota > rotb)
		{
			rrcount = rotb;
			rota -= rrcount;
			rotb = 0;
		}
		else if (rota < rotb)
		{
			rrcount = rota;
			rotb -= rrcount;
			rota = 0;
		}
		else if (rota == rotb)
		{
			rrcount = rota;
			rota = 0;
			rotb = 0;
		}
		while (rota > 0)
		{
			if (check == 0)
				write(1, "ra\n", 3);
			else
				write(1, "rra\n", 4);
			rota--;
		}
		while (rrcount > 0)
		{
			if (check == 0)
				write(1, "rr\n", 3);
			else
				write(1, "rrr\n", 4);
			rrcount--;
		}
		while (rotb > 0)
		{
			if (check == 0)
				write(1, "rb\n", 3);
			else
				write(1, "rrb\n", 4);
			rotb--;
		}
	}
	else
	{
		while (rota > 0)
		{
			write(1, "ra\n", 3);
			rota--;
		}
		while (rota < 0)
		{
			write(1, "rra\n", 4);
			rota++;
		}
		while (rotb > 0)
		{
			write(1, "rb\n", 3);
			rotb--;
		}
		while (rotb < 0)
		{
			write(1, "rrb\n", 4);
			rotb++;
		}
	}
}

static void	rotate_b(t_stacks *stacks, int *max, int *min, int rota)
{
	int	rotb;
	
	if (stacks->a->cont > *max || stacks->a->cont < *min)
	{
		rotb = get_rot_b_max(stacks, *max, ft_lstsize(stacks->b));
		rotate_ab(stacks, rotb, 1, 0);
		write_rotations(rota, rotb);
		if (stacks->a->cont > *max)
			*max = stacks->a->cont;
		else if (stacks->a->cont < *min)
			*min = stacks->a->cont;
		pb(stacks, 1);
	}
	else
	{
		rotb = get_rot_b(stacks, stacks->a->cont, ft_lstsize(stacks->b));
		rotate_ab(stacks, rotb, 1, 0);
		write_rotations(rota, rotb);
		pb(stacks, 1);
	}
}

static void	algo_big_core(t_stacks *stacks, int *part, int *max, int *min)
{
	int	loop;
	int	partsize;
	int	rota;

	loop = 0;
	if (ft_lstsize(stacks->a) >= 18)
		partsize = 18;
	else
		partsize = ft_lstsize(stacks->a);
	while (loop < partsize)
	{
		rota = get_rot_a(stacks, part, ft_lstsize(stacks->a));
		rotate_ab(stacks, rota, 0, 0);
		if (ft_lstsize(stacks->b) < 2)
			empty_b(stacks, max, min, rota);
		else
			rotate_b(stacks, max, min, rota);
		loop++;
	}
}

void	algo_big(t_stacks *stacks, int count)
{
	int	*tab;
	int	part[18];
	int	max;
	int	min;

	tab = lst_tab(stacks->a, count);
	max = 0;
	min = 0;
	while (ft_lstsize(stacks->a) > 0)
	{
		make_part(tab, part, 18);
		algo_big_core(stacks, part, &max, &min);
		if (ft_lstsize(stacks->a) < 18 && ft_lstsize(stacks->a) > 0)
		{
			make_part(tab, part, ft_lstsize(stacks->a));
			algo_big_core(stacks, part, &max, &min);
		}
	}
	free(tab);
	rotate_ab(stacks, get_rot_b_max(stacks, max, ft_lstsize(stacks->b)), 1, 1);
	while (stacks->b)
		pa(stacks, 1);
}
