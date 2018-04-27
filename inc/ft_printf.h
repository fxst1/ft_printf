#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# define FT_PRINTF_FORMATS "%sSpdDioOuUxXcC"
# define FORMAT_TYPE_NONE 0
# define FORMAT_TYPE_PERCENT 1
# define FORMAT_TYPE_STRING 2
# define FORMAT_TYPE_WSTRING 3
# define FORMAT_TYPE_ADDRESS 4
# define FORMAT_TYPE_INTEGER_D_LOWER 5
# define FORMAT_TYPE_INTEGER_D_UPPER 6
# define FORMAT_TYPE_INTEGER_I_LOWER 7
# define FORMAT_TYPE_INTEGER_O_LOWER 8
# define FORMAT_TYPE_INTEGER_O_UPPER 9
# define FORMAT_TYPE_INTEGER_U_LOWER 10
# define FORMAT_TYPE_INTEGER_U_UPPER 11
# define FORMAT_TYPE_INTEGER_X_LOWER 12
# define FORMAT_TYPE_INTEGER_X_UPPER 13
# define FORMAT_TYPE_CHAR 14
# define FORMAT_TYPE_WCHAR 15
# define FORMAT_MODIFIER_NONE 0
# define FORMAT_MODIFIER_HH 1
# define FORMAT_MODIFIER_LL 2
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define BASE_DEC "0123456789"
# define BASE_OCT "01234567"

typedef union		u_format_data
{
	int64_t			snumber;
	uint64_t		unumber;
	char			c;
	char			*str;
	uintptr_t		addr;
	double			d;
}					t_format_data;

typedef struct		s_format
{
	char			fill_token;
	size_t			n_token;
	int				modifier;
	char			type;
	t_format_data	data;
	size_t			len;
	char			*output;
	size_t			output_len;
}					t_format;

typedef struct		s_printer
{
	va_list			*vlist;
	int				n_args;
	int				n_formats;
	t_format		*formats;
	char			*input;
	char			*output;
	size_t			output_len;
}					t_printer;

void				compute_signednumber(t_format *f, char *base);
void				compute_unsignednumber(t_format *f, char *base);
void				compute_string(t_format *f);
void				compute_char(t_format *f);
void				compute_formats(t_printer *p);

t_printer			printer_init(const char *format, va_list *ap);

int					ft_printf(const char *format, ...);

#endif
