#include <stdio.h>
#include <stdarg.h> // variable arguments
#include <stdlib.h> // malloc
#include <unistd.h> // write
#include "hfile.h"

int main(void) {
    printf("\n-----------------------------------------------------------------\n");
	char character = 'X';
    printf("Characters are displayed properly: %c\n\n", character);
	int decimal_number = 123456789;
    my_printf("the decimal number is represented as: [%d]\n\n", decimal_number);
    int octal_number = 123456789;
    my_printf("the octal number is represented as: [%o]\n\n", octal_number);
    int hex_number = 123456789;
    my_printf("the hex number is represented as: [%x]\n\n", hex_number);
	char* string = "Hello World!";	
    my_printf("Strings are displayed properly: [%s]\n\n", string); 
	int pointer_test = 987;
    int* pointer_address = &pointer_test;
    my_printf("Pointer size depends on the size of the address on the machine in which the C program is being compiled: %p\n\n", pointer_address);
    my_printf("-------------------------------------------------------------------------\n\n");
    my_printf("[%d]\n\n", my_printf("My_printf also counts the number of characters of the input string.\nThis is the character count of this string: "));
    my_printf("-------------------------------------------------------------------------\n");

	return 0;
}
