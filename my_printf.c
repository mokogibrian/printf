#include "main.h"

int _printf(const char *format, ...)
{
	int char_count = 0;
	int x = 0;
	char *str;
	char c;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				c = va_arg(args, int);

				putchar(c);
				char_count++;

			}

			if (*format == 's')
			{
				str = va_arg(args, char *);

				while (str[x] != '\0')
				{
					putchar(*str);
					str++;
					char_count++;
				}
			}
			else
			{
				putchar('%');
				char_count++;
			}
		}
		else
		{
			putchar(*format);
			char_count++;
		}

		format++;
	}

	va_end(args);
	return (char_count);
}
