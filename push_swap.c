/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:57:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/28 10:38:37 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selectalgo(t_stacks *stacks, int count)
{
	if (count == 2)
		sa(stacks, 1);
	else if (count == 3)
		alg3(stacks);
	else if (count == 4)
		alg4(stacks);
	else if (count == 5 || count == 6)
		alg5_6(stacks, count);
	else if (count <= 20)
		alg_small(stacks, count);
	else if (count <= 200)
		algo_big(stacks, count);
	else
		algo_huge(stacks, count);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			count;

	if (argc <= 2)
		return (0);
	stacks = setstacks(argv, &count);
	if (!stacks)
		return (0);
	if (dupcheck(stacks->a))
	{
		print_error(stacks);
		return (0);
	}
	if (!sorted(stacks->a, count))
		return (0);
	else
		selectalgo(stacks, count);
	freestacks(stacks);
	return (0);
}
