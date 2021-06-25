/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_bh_write_rots.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:03:03 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/21 16:03:37 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_rotations(int rota, int rotb)
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