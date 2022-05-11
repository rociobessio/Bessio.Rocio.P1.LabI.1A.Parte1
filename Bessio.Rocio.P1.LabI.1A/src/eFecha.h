

#ifndef EFECHA_H_
#define EFECHA_H_

typedef struct //OTRA STRUCT
{
	int dia;
	int mes;
	int anio;
}eFecha;//YA DEBE DE EXISTIR POR ESO VA ANNTES

#endif /* EFECHA_H_ */


int  esAnioBisiesto(int year);

int isValidDate(eFecha *validDate);
