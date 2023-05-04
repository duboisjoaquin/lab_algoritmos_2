/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"

#include "weather_utils.h"



/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


static void dump_max(int a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%i, ", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

static void dump_rain(unsigned int a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%u, ", a[j]+1);
    }
    printf("\"");
    printf("\n\n");
}


/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array with the type of tclimate */
    WeatherTable array;

    /*Creo las variables para almacenar los resultados de las funciones de weather utils*/

    int historic_min_temp;

    int max_temp[YEARS];

    unsigned int rain_pmonth[YEARS];

    /* parse the file to fill the array and obtain the actual length */
    array_from_file(array, filepath);

    historic_min_temp = min_temp(array, YEARS, MONTHS, DAYS);

    max_temp_pyear(array,YEARS, MONTHS, DAYS, max_temp);

    max_rain_month_pyear(array, rain_pmonth, YEARS, MONTHS, DAYS);

    /* show the ordered array in the screen */
    
    printf("La temperatura minima historica es: %i\n", historic_min_temp);
    printf("La temperatura maxima por año es: ");
    dump_max(max_temp, YEARS);
    printf("Los meses con maximas precipitaciones por año son: ");
    dump_rain(rain_pmonth, YEARS);

    //array_dump(array);

    return (EXIT_SUCCESS);
}
