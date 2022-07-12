#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  printIdentifiers - prints special characters
 *  @next: character after the %
 *  @arg: argument for the indentifier
 *  Return: the number of characters printed
 *  (excluding the null byte used to end output to strings)
 */

int printIdentifiers(char next, va_list arg)
{
	int functsIndex;

	identifierStruct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].indentifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}

/**
 *  _printf - mimic printf from stdio
 *  Description: produces output according to a format
 *  write output to stdout, the standard output stream
 *  @format: character string composed of zero or more directives
 *  Return: the number of characters printed
 *  (excluding the null byte used to end output to strings)
 *  return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int identifierPrinted = 0, charPrinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			charPrinted++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		identifierPrinted = printIdentifiers(format[i + 1], arg);
		if (identifierPrinted == -1 || identifierPrinted != 0)
			i++;
		if (identifierPrinted > 0)
			charPrinted += identifierPrinted;

		if (identifierPrinted == 0)
		{
			_putchar('%');
			charPrinted++;
		}
	}
	va_end(arg);
	return (charPrinted);
}

/**
 *  print_char - writes the character c to stdout
 *  @arg: argument
 *  Return: On success 1.
 *  On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 *  print_str - prints a string with a `s` (lower case) specifier
 *  @arg: argument
 *  Return: number of character printed
 */

int print_str(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 *  _putchar - writes the character c to stdout
 *  @c: the character to print
 *  Return: 0 on success and -1 error and errno is set appropiately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
