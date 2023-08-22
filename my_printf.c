#include "main.h"

int _printf(const char *format, ...) {
	int char_count = 0;
	va_list args;
	va_start(args, format);
	
	while (*format) {
		if (*format == '%') {
			format++; /* Move to the character after '%'*/
			if (*format == '\0') {
				break; /* Format string ends with '%'*/
			}
			if (*format == 'c') {
				/*Handle character specifier*/
				char c = va_arg(args, int);
				putchar(c);
				char_count++;
			} else if (*format == 's') {
                /*Handle string specifier*/
				char *str = va_arg(args, char *);
				while (*str) {
					putchar(*str);
					str++;
					char_count++;
				}
			} else if (*format == '%') {
                /* Handle '%' specifier */
				putchar('%');
				char_count++;
			} else {
                /*Invalid specifier, ignore it */
			}
		} else {
			putchar(*format);
			char_count++;
		}
		format++;
	}
	
	va_end(args);
	return char_count;
}
