/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 09:53:57 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/27 16:00:36 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intlen_base(unsigned int n, int base)
{
	size_t			i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char		*ft_itoa_base(int64_t value, int base, char *basestr)
{
	size_t			size;
	size_t			i;
	char			*tmp;

	size = ft_intlen_base(value, base);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!value)
		tmp[0] = '0';
	i = size - 1;
	while (value)
	{
		tmp[i] = basestr[value % base];
		value = value / base;
		i--;
	}
	return (tmp);
}

char		*ft_itoa_base_unsigned(uint64_t value, int base, char *basestr)
{
	size_t			size;
	size_t			i;
	char			*tmp;

	size = ft_intlen_base(value, base);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!value)
		tmp[0] = '0';
	i = size - 1;
	while (value)
	{
		tmp[i] = basestr[value % base];
		value = value / base;
		i--;
	}
	return (tmp);
}
