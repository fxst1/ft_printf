/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:48:35 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/27 10:51:05 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != (char)c && str[i] != 0)
		i++;
	if (str[i] == 0 && str[i] != (char)c)
		return (NULL);
	else if (str[i] == (char)c)
		return ((char *)&str[i]);
	return ((char *)&str[i]);
}
