/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:57:15 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/24 16:08:55 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlst(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->n);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list		*tmp;
	int			i;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	i = 1;
	stacks->a = (t_list *)malloc(sizeof(t_list));
	tmp = stacks->a;
	while (i < argc)
	{
		tmp->n = ft_atoi(argv[i]);
		i++;
		if (i < argc)
		{
			tmp->next = (t_list *)malloc(sizeof(t_list));
			tmp = tmp->next;
		}
	}
	tmp->next = NULL;
	printlst(stacks->a); //to remove
	// swap(tab);
	ft_lstclear(&stacks->a);
	free(stacks);
	system("leaks a.out");
	return (0);
}
