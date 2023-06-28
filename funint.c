#include "main.h"

/**
* get_print - finds the right printing function
* based on _printf's conversion specifier
*`s`: the conversion specifier
* Description:
* The function loops through the `func_arr` array of structures
* for a match to the input character `s`.
* If a match is found, the function returns a pointer to the printing function.
*  Otherwise, the function returns NULL
*Return: a pointer to the matching printing function
or NULL if no match is found
*/

int (*get_print(char character))(va_list, flags_t *)
{
	printing_f func_arr[] = {
		{'i', print_int};
		{'s', print_string};
		{'c', print_char};
		{'d', print_int};
		{'%', print_percent};
	};
	int flags = 14;
	int i = 0;
	
	while (i < flags)
	{
		if (func_arr[i].character == s)
		{
			return (func_arr[i].function);
		}
		i++;
	}
	return (NULL);
}
