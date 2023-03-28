#include "main.h"

/**
 * handle_char - Handles %c specifier
 * @args: Argument list
 * @count: Pointer to the character count
 */
void handle_char(va_list args, int *count)
{
	char c = (char)va_arg(args, int);
	*count += _putchar(c);
}

/**
 * handle_string - Handles %s specifier
 * @args: Argument list
 * @count: Pointer to the character count
 */
void handle_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		*count += _putchar(*s);
		s++;
	}
}

/**
 * handle_percent - Handles %% specifier
 * @count: Pointer to the character count
 */
void handle_percent(int *count)
{
	*count += _putchar('%');
}

/**
 * _printf - Custom printf function that handles %c, %s, and %% format
 * specifiers
 * @format: Format string containing conversion specifiers and text to print
 * Return: Number of characters printed (excluding null byte for strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					handle_char(args, &count);
					break;
				case 's':
					handle_string(args, &count);
					break;
				case '%':
					handle_percent(&count);
					break;
				default:
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (count);
}
