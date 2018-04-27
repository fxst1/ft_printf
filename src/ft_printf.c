#include  "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printer	p;

	if (format)
	{
		va_start(ap, format);
		p = printer_init(format, &ap);
		write(STDOUT_FILENO, p.output, p.output_len);
		va_end(ap);
		return (p.output_len);
	}
	return (0);
}
