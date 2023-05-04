#ifndef _HELPERSH
#define _HELPERSH
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *parse_filepath(int argc, char *argv[]);

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

#endif