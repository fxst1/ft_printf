/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:46:55 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/27 16:21:41 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		count_formats(const char *s)
{
	int			i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '#' || *s == ' ' || *s == '0' || *s == '-' || *s == '+' || *s == '.')
				s++;
			while (*s >= '0' && *s <= '9')
				s++;
			if (!*s)
				return (-1);
			if (*s == 'h' || *s == 'l' || *s == 'q' || *s == 'L' || *s == 'z' || *s == 'j')
				s++;
			else if ((*s == 'h' && *(s + 1) == 'h') || (*s == 'l' && *(s + 1) == 'l'))
				s += 2;
			if (!ft_strchr(FT_PRINTF_FORMATS, *s))
				return (-1);
			else
				s++;
			i++;
		}
		else
		{
			while (*s && *s != '%')
				s++;
			i++;
		}
	}
	return (i);
}

static size_t	size_format(const char *s)
{
	char		*tmp;

	tmp = (char*)s;
	if (*s == '%')
	{
		s++;
		if (*s == '#' || *s == ' ' || *s == '0' || *s == '+' || *s == '-' || *s == '.')
			s++;
		while (*s >= '0' && *s <= '9')
			s++;
		if (*s == 'h' || *s == 'l' || *s == 'q' || *s == 'L' || *s == 'z' || *s == 'j')
			s++;
		else if ((*s == 'h' && *(s + 1) == 'h') || (*s == 'l' && *(s + 1) == 'l'))
			s += 2;
		s++;
	}
	else
	{
		while (*s && *s != '%')
			s++;
	}
	return ((size_t)(s - tmp));
}

static void		load_data(t_printer *p, t_format *f)
{
	if (f->type == 'c')
	{
		f->data.c = va_arg(*p->vlist, int32_t);
		compute_char(f);
	}
	else if (f->type == '%')
	{
		f->data.c = '%';
		compute_char(f);
	}
	else if (f->type == 's')
	{
		f->data.str = va_arg(*p->vlist, char*);
		compute_string(f);
	}
	else if (f->type == 'd' || f->type == 'D' || f->type == 'i' || f->type == 'I')
	{
		if (f->modifier == FORMAT_MODIFIER_LL)
			f->data.snumber = va_arg(*p->vlist, int64_t);
		else if (f->modifier == 'l')
			f->data.snumber = va_arg(*p->vlist, int32_t);
		else if (f->modifier == 'h')
			f->data.snumber = (int16_t)va_arg(*p->vlist, int32_t);
		else if (f->modifier == FORMAT_MODIFIER_HH)
			f->data.snumber = (char)va_arg(*p->vlist, int32_t);
		else
			f->data.snumber = va_arg(*p->vlist, int32_t);
		compute_signednumber(f, BASE_DEC);
	}
	else if (f->type == 'x' || f->type == 'X' || f->type == 'o' || f->type == 'u' || f->type == 'U')
	{
		if (f->modifier == FORMAT_MODIFIER_LL)
			f->data.unumber = va_arg(*p->vlist, uint64_t);
		else if (f->modifier == 'l')
			f->data.unumber = va_arg(*p->vlist, uint32_t);
		else if (f->modifier == 'h')
			f->data.unumber = (uint16_t)va_arg(*p->vlist, uint32_t);
		else if (f->modifier == FORMAT_MODIFIER_HH)
			f->data.unumber = (uint8_t)va_arg(*p->vlist, uint32_t);
		else
			f->data.unumber = va_arg(*p->vlist, uint32_t);

		if (f->type == 'x' || f->type == 'X')
			compute_unsignednumber(f, f->type == 'x' ? BASE_HEX_LOWER : BASE_HEX_UPPER);
		else if (f->type == 'o')
			compute_unsignednumber(f, BASE_OCT);
		else
			compute_unsignednumber(f, BASE_DEC);
	}
	else if (f->type == 'p')
		f->data.addr = va_arg(*p->vlist, uintptr_t);
}

static t_format	load_format(t_printer *p, const char *s, size_t len)
{
	t_format	f;

	ft_bzero(&f, sizeof(t_format));
	f.len = len;
	if (*s == '%')
	{
		s++;
		if (*s == '#' || *s == ' ' || *s == '0' || *s == '-' || *s == '+' || *s == '.')
		{
			f.fill_token = *s;
			s++;
		}
		f.n_token = (size_t)atoi(s);
		while (*s >= '0' && *s <= '9')
			s++;
		if (*s == 'h' || *s == 'l' || *s == 'q' || *s == 'L' || *s == 'z' || *s == 'j')
		{
			f.modifier = *s;
			s++;
		}
		else if ((*s == 'h' && *(s + 1) == 'h') || (*s == 'l' && *(s + 1) == 'l'))
		{
			f.modifier = (*s == 'h') ? FORMAT_MODIFIER_HH : FORMAT_MODIFIER_LL;
			s += 2;
		}
		else
			f.type = *(ft_strchr(FT_PRINTF_FORMATS, *s));
		s++;
	}
	else
	{
		f.output = ft_strsub(s, 0, len);
		f.output_len = len;
		while (*s && *s != '%')
			s++;
	}
	load_data(p, &f);
	return (f);
}

static t_format	*get_formats(const char *s, t_printer *printer)
{
	t_format	*f;
	int			n_formats;
	size_t		i;
	size_t		len;

	i = 0;
	n_formats = count_formats(s);
	if (n_formats == -1)
		return (NULL);
	printer->n_formats = n_formats;
	f = (t_format*)malloc(sizeof(t_format) * n_formats);
	ft_bzero(f, sizeof(t_format) * n_formats);
	while (n_formats--)
	{
		len = size_format(s);
		f[i++] = load_format(printer, s, len);
		s += len;
	}
	return (f);
}

t_printer		printer_init(const char *s, va_list *ap)
{
	t_printer	p;

	ft_bzero(&p, sizeof(t_printer));
	p.vlist = ap;
	p.input = (char*)s;
	p.formats = get_formats(s, &p);
	if (p.formats)
		compute_formats(&p);
	return (p);
}
