/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:48:14 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/27 14:39:48 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)src) + 1;
	str = (char*)ft_memalloc(sizeof(char) * len);
	return (!str ? NULL : ft_memcpy(str, src, len));
}
