# ft_printf
**Implementation printf function**

Format string refers to a control parameter used by a class of functions in the input/output libraries of C
Formatting takes place via placeholders within the format string.

**Syntax of fomat placeholder:**
```
	%[flags][width][.precision][length]type
```
**Flags:**

`-  (minus)`	Left-align the output of this placeholder. (The default is to right-align the output.)

`+  (plus)`		Prepends a plus for positive signed-numeric types. positive = +, negative = -.
			(The default doesn't prepend anything in front of positive numbers.)

`' '(space)`	Prepends a space for positive signed-numeric types. positive =  , negative = -. This flag is ignored
			if the + flag exists. (The default doesn't prepend anything in front of positive numbers.)

`0  (zero)`		When the 'width' option is specified, prepends zeros for numeric types. (The default prepends spaces.)

`#  (hash)`		For f type, the output always contains a decimal point.
			For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.

**Width field:**

The Width field specifies a minimum number of characters to output.
The width field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk `*`.

**Precision field:**

The Precision field specifies a maximum limit on the output, depending on the particular formatting type. For floating point numeric types, it specifies the number of digits to the right of the decimal point that the output should be rounded. For the string type, it limits the number of characters that should be output, after which the string is truncated.
The precision field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk `*`.

**Length field:**

`hh`	For integer types, causes printf to expect an int-sized integer argument which was promoted from a *char.*

`h`	For integer types, causes printf to expect an int-sized integer argument which was promoted from a *short.*

`l`	For integer types, causes printf to expect a *long*-sized integer argument.

`ll`	For integer types, causes printf to expect a *long long*-sized integer argument.

`L`	For floating point types, causes printf to expect a *long double* argument.

`z`	For integer types, causes printf to expect a *size_t*-sized integer argument.

`j`	For integer types, causes printf to expect a *intmax_t*-sized integer argument.


**Type field**

`%`	Prints a literal % character.

`d, i`	*int* as a signed integer.

`u`	Print decimal *unsigned int*.

`f`	*double* in normal (fixed-point) notation.

`x, X`	*unsigned int* as a hexadecimal number. x uses lower-case letters and X uses upper-case.

`o`	*unsigned int* in octal.

`s`	*null-terminated string*

`c`	*char* (character).

`p`	_void *_ (pointer to void) in an implementation-defined format.

`k`	change the color of output. (string with name color expected as parameter)

`D`	*unix-date* in ISO format (int unix-time expected as parameter).

