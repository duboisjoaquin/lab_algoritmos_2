#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


size_t string_length(const char *str);
//calcula la longitud de la cadena apuntada por str, y la función

char *string_filter(const char *str, char c);
//devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del caracter c.


#endif