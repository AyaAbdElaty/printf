/**
 * print_int - Print an integer
 * @ parameters: List of arguments passed to the function
 * @ otp_buffer: Buffer array to store the printed characters
 * @flags: Active flags that affect the printing
 * @width: Width of the printed integer
 * @precision: Precision of the printed integer
 * @size: Size specifier for the integer
 *
 * Returns the number of characters printed
 */



int print_int(va_list parameters, char otp_buffer [],
		int flags, int width, int precision, int size) 
{
	/* Index of the last character in the buffer */
	int i = BUFF_SIZE - 2;

	int is_negative = 0;
	long int n = va_arg(parameters, long int);
	unsigned long int integer;

/* Convert the integer to the specified size */
	num = convert_size_number(num, size);

/* If the integer is 0, print a leading 0 */
	if (num == 0) {
		otp_buffer [i--] = '0';
	}
	
	otp_buffer [BUFF_SIZE - 1] = '\0';
	integer = (unsigned long int)n;

	if (num < 0) {
		integer = (unsigned long int)((-1) * num);
		is_negative = 1;
	}

	while (integer > 0) {
		otp_buffer [i--] = (integer % 10) + '0';
		integer /= 10;
	}

/* Increment the index to account for the leading 0*/
	i++;

/* Return the number of characters printed */
	return write_number(is_negative, i, otp_buffer, flags, width, precision, size);
}
