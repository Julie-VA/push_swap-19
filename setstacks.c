/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:58:55 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/06/02 09:25:08 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestacks(t_stacks *stacks)
{
	if (stacks->a)
		ft_lstclear(&stacks->a);
	if (stacks->b)
		ft_lstclear(&stacks->b);
	if (stacks)
		free(stacks);
}

static int	setstacks_split(char **argv, t_list **tmp, int i, int j)
{
	j++;
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	if (argv[i][j] == ' ')
	{
		j++;
		if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-')
		{
			(*tmp)->next = (t_list *)malloc(sizeof(t_list));
			*tmp = (*tmp)->next;
		}
		return (j);
	}
	else if (!argv[i][j])
		return (j);
	else
	{
		(*tmp)->next = NULL;
		return (-1);
	}
}

t_stacks	*setstacks(char	**argv, int *count)
{
	t_stacks	*stacks;
	t_list		*tmp;
	int			i;
	int			j;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	i = 1;
	stacks->a = (t_list *)malloc(sizeof(t_list));
	tmp = stacks->a;
	stacks->b = NULL;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			tmp->cont = ft_atoi(argv[i] + j, stacks, &j, &tmp);
			(*count)++;
			if (j == -1)
				return (NULL);
			j = setstacks_split(argv, &tmp, i, j);
			if (j == -1)
			{
				print_error(stacks);
				return (NULL);
			}
		}
		i++;
		if (argv[i])
		{
			tmp->next = (t_list *)malloc(sizeof(t_list));
			tmp = tmp->next;
		}
	}
	tmp->next = NULL;
	return (stacks);
}
