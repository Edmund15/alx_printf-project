#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>
/**
 * _printf - Custom printf function
 * @format: Format string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	char c;
	char *s;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			switch (*(++ptr))
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
					{
						fputs("(nil)", stdout);
						count += 5;
					}
					else
					{
						fputs(s, stdout);
						count += strlen(s);
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*ptr);
					count += 2;
			}
	}
	else
	{
		putchar(*ptr);
		count++;
	}
	}
	va_end(args);
	return (count);
}
