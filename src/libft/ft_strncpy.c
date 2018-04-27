/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:48:02 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/27 00:52:40 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		cur;

	cur = 0;
	while (src[cur] != '\0' && cur < len)
	{
		dst[cur] = src[cur];
		cur++;
	}
	while (cur < len)
	{
		dst[cur] = '\0';
		cur++;
	}
	return (dst);
}
