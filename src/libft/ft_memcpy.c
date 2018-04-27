/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:20:31 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/26 22:12:59 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char*)dst;
	while (i < n)
	{
		((char*)dst)[i] = ((const char*)src)[i];
		i++;
	}
	return (tmp);
}
