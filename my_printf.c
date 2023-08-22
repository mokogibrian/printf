#include "main.h"

int _printf(const char *format, ...)
{
	int char_count = 0;

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
				char c = va_arg(args, int);

				putchar(c);
				char_count++;

			} else if (*format == 's')

				char *str = va_arg(args, char *);

				while (*str)
				{
					putchar(*str);
					str++;
					char_count++;
				}
			} else if (*format == '%')
			{
				putchar('%');
				char_count++;
			} else
			putchar(*format);
			char_count++;
		}
		format++;
	}

	va_end(args);
	return (char_count);
}
