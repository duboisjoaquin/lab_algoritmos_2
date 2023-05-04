#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "array_helpers.h"
#include "weather_utils.h"

int min(int x, int y){
    int r;

    if (x > y){
        r = y;
    }
    else{
        r = x;
    }

    return r;
}

int max (int x, int y){
    int r;
    if(x > y){
        r = x;
    }
    else{
        r = y;
    }
    return r;
}

/*  Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba 
    según los datos del arreglo.    */

int min_temp (WeatherTable array, int max_year, int max_month, int max_day){

    int res = INT_MAX;

    for (int years = 0; years < max_year; ++years){
        for (int months = 0; months < max_month; ++months){
            for (int days = 0; days < max_day; ++days){
                res = min(res, array[years][months][days]._min_temp);
            }
        }
    }

    return res;
}

/*  Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura máxima registrada
    durante ese año                 */


void max_temp_pyear (WeatherTable array, int max_year, int max_month, int max_day, int res[]){
    
    int max_temp;

    for (int years = 0; years < max_year; ++years){
        max_temp = INT_MIN;

        for (int months = 0; months < max_month; ++months){
            for (int days = 0; days < max_day; ++days){
                max_temp = max(max_temp, array[years][months][days]._max_temp);
            }
        }
        res[years] = max_temp;
    }

}

/*  Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en
    que se registró la mayor cantidad mensual de precipitaciones.   */

void max_rain_month_pyear(WeatherTable array, unsigned int res[], int max_year, int max_months, int max_day){
    
    month_t max_month;
    unsigned int rain_pmonth = 0u;
    unsigned int max_rain = 0u;

    for (int years = 0; years < max_year; ++years){
        max_rain = 0u ;                                                      

        for (int months = 0; months < max_months; ++months){      
            rain_pmonth = 0;                                               
            
            for (int days = 0; days < max_day; ++days){
                rain_pmonth = rain_pmonth + array[years][months][days]._rainfall;     
            }

            if (rain_pmonth > max_rain){                                   
                max_month = months;
            }
        }
        res[years] = max_month;                                      
    }
}

