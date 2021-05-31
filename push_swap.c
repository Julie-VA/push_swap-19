/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:57:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/31 18:24:36 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printlst(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->cont);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	(void)argc;

	stacks = setstacks(argv);
	if (!stacks)
	{
		// system("leaks push_swap");
		return (0);
	}
	if (dupcheck(stacks->a))
	{
		print_error(stacks);
		// system("leaks push_swap");
		return (0);
	}
	printlst(stacks->a); //to remove
	printlst(stacks->b); //to remove
	freestacks(stacks);
	// system("leaks push_swap");
	return (0);
}
