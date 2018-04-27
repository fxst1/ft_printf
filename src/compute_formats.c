/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_formats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:27:21 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/27 16:29:09 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	compute_signednumber(t_format *f, char *base)
{
	char	*tmpout;
	int		i;
	char	c;

	if (f->fill_token == '0' || f->fill_token == '.')
		c = '0';
	else
		c = ' ';
	tmpout = ft_itoa_base(f->data.snumber, ft_strlen(base), base);
	f->output_len = ft_strlen(tmpout);
	f->output = (char*)ft_memalloc(f->output_len + f->n_token + 1);
	if (f->fill_token == '-')
	{
		ft_memcpy(f->output, tmpout, f->output_len);
		i = f->output_len;
		while (i < (int)f->n_token)
			f->output[i++] = c;
	}
	else
	{
		i = 0;
		while (i + (int)f->output_len < (int)f->n_token)
			f->output[i++] = c;
		ft_memcpy(f->output + i, tmpout, f->output_len);
	}
	free(tmpout);
}

void	compute_unsignednumber(t_format *f, char *base)
{
	char	*tmpout;
	size_t	i;

	i = 0;
	tmpout = ft_itoa_base_unsigned(f->data.unumber, ft_strlen(base), base);
	f->output_len = ft_strlen(tmpout);
	f->output = (char*)malloc(f->output_len + f->n_token + 1);
	while (i < f->output_len - f->n_token)
	{
		f->output[i] = f->fill_token;
		i++;
	}
	ft_memcpy(f->output + i, tmpout, f->output_len);
	free(tmpout);
}

void	compute_string(t_format *f)
{
	f->output = ft_strdup(f->data.str);
	f->output_len = ft_strlen(f->output);
}

void	compute_char(t_format *f)
{
	char	tmp[2];

	tmp[0] = f->data.c;
	tmp[1] = 0;
	f->output = ft_strdup(tmp);
	f->output_len = 1;
}

void	compute_formats(t_printer *p)
{
	int		i;
	char	*del;

	i = 0;
	p->output_len = 0;
	while (i < p->n_formats)
	{
		del = p->output;
		if (del)
			p->output = ft_strjoin(del, p->formats[i].output);
		else
			p->output = ft_strdup(p->formats[i].output);
		free(del);
		i++;
	}
	p->output_len = ft_strlen(p->output);
}
