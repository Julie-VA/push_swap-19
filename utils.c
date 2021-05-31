/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:02:55 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/31 18:02:04 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checksign(const char *nptr, int *i, int *sign)
{
	if (nptr[*i] == '-')
	{
		*sign = 1;
		*i += 1;
	}
}

int	ft_atoi(const char *nptr, t_stacks *stacks, int *j, t_list **tmp)
{
	int				sign;
	int				i;
	long long int	rtrnval;

	sign = 0;
	i = 0;
	rtrnval = 0;
	if (nptr[i] == '-')
		checksign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		rtrnval = (rtrnval * 10) + (nptr[i++] - '0');
	if (sign == 1)
	{
		rtrnval *= -1;
		i--;
	}
	if (i > 10 || rtrnval > 2147483647 || rtrnval < -2147483648)
	{
		*j = -1;
		(*tmp)->next = NULL;
		print_error(stacks);
		return (0);
	}
	return ((int)rtrnval);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*temp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	else
		return (0);
}
