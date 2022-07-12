#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct identifierStruct- Struct op
 * @indentifier
 * @printer: The function that prints
 */
typedef struct identifierStruct
{
	char *indentifier;
	int (*printer)(va_list va);
} identifierStruct;

int _putchar(char c);
int _printf(const char *format, ...);
int print_int(va_list arg);
int print_unsigned(va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(void);
void print_binary(unsigned int n, unsigned int *printed);
int print_unsignedToBinary(va_list arg);
int print_hex_base(va_list arg, char _case);
int print_STR(va_list arg);
int print_HEX(va_list arg);
int print_hex(va_list arg);
int print_hex_base(va_list arg, char _case);
int print_oct(va_list arg);
int print_unsignedIntToHex(unsigned int num, char _case);


#endif
