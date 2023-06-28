#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>

/**
 * struct printHandler - struct to choose the right function depending
 * the format specifier _printf
 * @c: format specifier
 * @f: pointer to the correct printing function
*/

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* Functions to print numbers */
int print_int(va_list parameters, char otp_buffer[],
		int flags, int width, int precision, int size);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char character))(va_list, flags_t *);

/* Funtions to print chars and strings */
int print_string(va_list ap, params_t *params);
int print_char(va_list ap, params_t *params);


/* write_funcs */
int _putchar(char c);

/* print_percent */
int print_percent(va_list ap, params_t *params);

/* get_specifier*/
int (*get_specifier(char *s))(va_list ap, params_t *params);

/* get_flag */
int get_flag(char *s, params_t *params);



#endif

