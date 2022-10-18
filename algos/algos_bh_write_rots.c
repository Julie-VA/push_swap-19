/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bh_write_rots.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:03:03 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/28 09:29:37 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bothpos_write(int rota, int rotb, int check, int rrcount)
{
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

static void	bothpos_count(int rota, int rotb, int check)
{
	int	rrcount;

	rrcount = 0;
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
	bothpos_write(rota, rotb, check, rrcount);
}

static void	write_rots_else(int rota, int rotb)
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

void	write_rotations(int rota, int rotb)
{
	int	check;

	check = 0;
	if (rota < 0 && rotb < 0)
	{
		rota *= -1;
		rotb *= -1;
		check = 1;
	}
	if (rota > 0 && rotb > 0)
		bothpos_count(rota, rotb, check);
	else
		write_rots_else(rota, rotb);
}
