#include <stdio.h>
#include <stdarg.h> // variable arguments
#include <stdlib.h> // malloc
#include <unistd.h> // write
#include "hfile.h"

// print all characters in a string with their proper formats
int my_printf(const char* format, ...) {
	// format types
	char character;
	char* string;
	int decimal, octal;
	unsigned int unsigned_decimal, unsigned_hexadecimal, void_pointer;
	// working variables
	char parse;
	int char_counter = 0;

	va_list ap;
	va_start(ap, format); 
	
	parse = *format;

	while(parse != '\0'){
		if(parse == '%'){
			format++; 
			parse = *format;
			
			switch(parse){
			case 'c': 
				character = va_arg(ap, int); 
				char* one_char;
				one_char = &character;
				write(1, one_char, 1);
				char_counter++;
				break;

			case 'd':
				decimal = va_arg(ap, int); 
                if(decimal < 0) {                    
                    decimal = -decimal;
                    char sign = '-'; 
                    char* one_sign;
                    one_sign = &sign;
                    write(1, one_sign, 1);
                    char_counter++;
                } 			 
				char* temp_decimal = converter(decimal, 10);	
				write(1, temp_decimal, my_strlen(temp_decimal));
				char_counter += my_strlen(temp_decimal); 
                free(temp_decimal);
				break;

            case 'u':
				unsigned_decimal = va_arg(ap, unsigned int); 
				char* temp_u_decimal = converter(unsigned_decimal, 10);				 
				write(1, temp_u_decimal, my_strlen(temp_u_decimal));
				char_counter += my_strlen(temp_u_decimal); 
                free(temp_u_decimal);
				break;    

			case 'x':
				unsigned_hexadecimal = va_arg(ap, unsigned int); 
				char* temp_hex = converter(unsigned_hexadecimal, 16);				 
				write(1, temp_hex, my_strlen(temp_hex));
				char_counter += my_strlen(temp_hex); 
                free(temp_hex);
				break;

            case 'p':
				void_pointer = va_arg(ap, unsigned int); 
				char* temp_vptr = converter(void_pointer, 16);	
                char prefix_zero = '0';
                char* hex_prefix_z; 
                hex_prefix_z = &prefix_zero;
                write(1, hex_prefix_z, 1);
                char_counter += 1;			 
                char prefix_x = 'x';
                char* hex_prefix_x; 
                hex_prefix_x = &prefix_x;
                write(1, hex_prefix_x, 1);
                char_counter += 1;	
				write(1, temp_vptr, my_strlen(temp_vptr));
				char_counter += my_strlen(temp_vptr); 
                free(temp_vptr);
				break;

            case 'o':
				octal = va_arg(ap, unsigned int); 
				char* temp_octal = converter(octal, 8);				 
				write(1, temp_octal, my_strlen(temp_octal));
				char_counter += my_strlen(temp_octal); 
                free(temp_octal);
				break;    

			case 's': 
				string = va_arg(ap, char *);
				write(1, string, my_strlen(string));
				char_counter += my_strlen(string);
				break;				
			}

		} else {	
			write(1, format, 1);
			char_counter++;
		}		
		format++; 
		parse = *format;
	}
	
	va_end(ap); 

	return char_counter; 
}

/* Convert numbers to string depending on base */
char* converter(unsigned int number, int base) {
	int counter = 0;
	int local_num = number;
	do {
		local_num /= 10;
		counter++;
	} while (local_num != 0);	
	char* buffer = malloc(sizeof(char) * counter + 1); // add 1 for the NULL terminator
	
	char* number_representation= "0123456789abcdef";
	int index = 0;
	do{ 
		buffer[index++] = number_representation[number%base];
		number /= base; 
	}while(number != 0); 
    buffer[index] = '\0';
    
    int flip = my_strlen(buffer) - 1; // -1 because index starts at zero
    int flop = 0;
    char* reverse_string = malloc(sizeof(char) * flip + 2); // +2 to make up for -1 and to give space for NULL
    while (buffer[flop] != '\0') {
        reverse_string[flop] = buffer[flip];
        flop++;
        flip--;
    }
    reverse_string[flop] = '\0';
    free(buffer);

	return reverse_string; 
}

/* String Length */
size_t my_strlen(char *param_1) {
    size_t length = 0;
    if(param_1 != NULL) {
        while(*param_1 != '\0') {
            length++;
            param_1++; 
        }
    }
    return length;
}

/* String Copier */
char* my_strcpy(char* param_1, char* param_2) {
    int i = 0;
    while (param_2[i] != '\0') {
        param_1[i] = param_2[i];
        i++;
    }
    return param_1;
}
