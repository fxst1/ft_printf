/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:09:21 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/27 10:19:15 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **root, t_list *add)
{
	t_list *tmp;

	tmp = *root;
	if (!tmp)
		*root = add;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add;
	}
}
