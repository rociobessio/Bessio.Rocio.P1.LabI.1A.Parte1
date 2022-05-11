
#include "eFecha.h"

#define MAX_YR  2025 //MAXIMO DE AÑO
#define MIN_YR  1900 //MINIMO DE AÑO

int  esAnioBisiesto(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}


// returns 1 if given date is valid.
int isValidDate(eFecha *validDate)
{
    //check range of year,month and day
    if (validDate->anio > MAX_YR ||
            validDate->anio < MIN_YR)
        return 0;
    if (validDate->mes < 1 || validDate->mes > 12)
        return 0;
    if (validDate->dia < 1 || validDate->dia > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mes == 2)
    {
        if (esAnioBisiesto(validDate->anio))
            return (validDate->dia <= 29);
        else
            return (validDate->dia <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mes == 4 || validDate->mes == 6 ||
            validDate->mes== 9 || validDate->mes == 11)
        return (validDate->dia <= 30);
    return 1;
}
