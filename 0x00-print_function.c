#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format directives.
 * @...: Variadic arguments corresponding to the format directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == ')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
				{
					write(1, "(null)", 6);
					count += 6;
				}
				else
				{
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
				}
			}
			else if (*format == ' % ')
			{
				write(1, "%" , 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
