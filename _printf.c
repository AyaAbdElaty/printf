#include "main.h"

/**
 * _printf - produces formatted output according to a format string
 *
 * @format: A string containing the characters and the specifiers
 * that will be used to format the output.
 *
 * Description: This function takes a format string
 * and calls the appropriate printing function
 * depending on the conversion specifiers contained in the format string.
 * The length of the formatted output string is returned.
 *
 * Return: The length of the formatted output string, or a negative value if an error occurred.
*/

int _printf(const char *format, ...)
{
	int characters_printed = 0;
	va_list arguments;
	va_start(arguments, format);

	while (*format != '\0') 
{
		if (*format == '%') {
			format++;

			/* Handle the c, s, %, d, and i conversion specifiers.*/

			switch (*format) 
			{
				case 'c': {
					int value = va_arg(arguments, int);
					characters_printed += putchar(value);

					break;
				}
				case 's': {
					char *value = va_arg(arguments, char *);
					characters_printed += printf("%s", value);

					break;
				}
				case '%': {
					characters_printed += putchar('%');
					break;
				}
				case 'd':
				case 'i': {
					int value = va_arg(arguments, int);
					characters_printed += printf("%d", value);

					break;
				}
				default: {
					/* Ignore unknown conversion specifiers. */
					break;
				}
			}
		} else 
		{
			characters_printed += putchar(*format);
		}

		format++;
	}

	va_end(arguments);
	return (characters_printed);
}
