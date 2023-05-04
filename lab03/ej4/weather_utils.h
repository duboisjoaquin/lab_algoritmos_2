#ifndef _WEATHER_UTILSH
#define _WEATHER_UTILSH

#include <stdio.h>

int min_temp (WeatherTable array, int max_year, int max_month, int max_day);

/*  obtiene la menor temperatura mínima histórica */

void max_temp_pyear (WeatherTable array, int max_year, int max_month, int max_day, int res[]);

/* registra para cada año la mayor temperatura máxima registrada durante ese año */

void max_rain_month_pyear(WeatherTable array, unsigned int res[], int max_year, int max_month, int max_day);

/*registra para cada año el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones, lo retorna en el arreglo res[]*/



#endif //_WEATHER_UTILSH