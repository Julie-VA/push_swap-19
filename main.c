/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:57:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/26 14:31:09 by rvan-aud         ###   ########.fr       */
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
	t_list		*tmp_a;
	int			i;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	i = 1;
	stacks->a = (t_list *)malloc(sizeof(t_list));
	tmp_a = stacks->a;
	stacks->b = NULL;
	while (i < argc)
	{
		tmp_a->cont = ft_atoi(argv[i]);
		i++;
		if (i < argc)
		{
			tmp_a->next = (t_list *)malloc(sizeof(t_list));
			tmp_a = tmp_a->next;
		}
	}
	tmp_a->next = NULL;
	// swap(stacks->b, stacks->b + 1);
	pb(stacks);
	pb(stacks);
	printlst(stacks->a); //to remove
	printlst(stacks->b); //to remove
	if (stacks->a)
		ft_lstclear(&stacks->a);
	if (stacks->b)
		ft_lstclear(&stacks->b);
	free(stacks);
	system("leaks a.out");
	return (0);
}
