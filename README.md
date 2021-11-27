# my_printf

my_printf (or print function in C) takes a formatting string and a format variable as input and outputs strings to console while converting input variables to strings.
My_printf takes multiple arguments and these functions are called variable length argument functions or vararg functions. 
The user supplies a string and input arguments. 
My_printf creates an internal buffer for constructing the output string. 
My_printf then iterates through each characters of the user string, counts the character, and copies the character to the output string. 
My_printf only stops at "%". 
"%" means that there is an argument to format. 

DETAILS ON FORMATTING

To sum, my_printf operates by scanning the format string from left to right.  
Each character from the format string is appended to the result string unless it is a percent sign.  
If the character is a % then it is not copied to the result string.  
Instead, the characters following the % character are treated as a conversion specifier.  
The conversion specifier controls the conversion of the next successive arg to a particular format and the result is appended to the result string in place of the conversion specifier. 
The conversion specifier simply determines what kind of conversion to perform. 
The following conversion characters are supported by this program:
- Integer arguments are converted to signed decimal (d), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x).
- Character argument (c): individual characters are directly copied to output.
- String argument (s): character arrays are written up to (but not including) a terminating NUL character.
- Pointer argument (p): the pointer argument is printed in hexadecimal.
- All characters and arguments are counted, and that is the return value of my_printf.


Variadic types & macros (a brief overview)
Type Defined in header file <stdarg.h>

va_list (type) 
holds the information needed by macros va_start, va_arg, va_end, and va_copy

va_start (macro)
start of iterations in the variadic function arguments

va_arg (macro)
get the next variadic function argument

va_copy (macro)
makes a copy of the variadic function arguments
(Available only in C99)
 
va_end (macro)
ends of iteration in the variadic function arguments
_________________________________
To test this program you can run: 

make print
----------------------------------------------------
