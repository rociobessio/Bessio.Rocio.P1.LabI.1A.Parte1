
#include "servicio.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{

	int idTrabajo;
	int idServicio;
	int idMascota;

	eFecha fechaTrabajo;

	int isEmpty;

}eTrabajo;

#endif /* TRABAJO_H_ */


int inicializarEstructuraTrabajo(eTrabajo listaTrabajo[],int tamTrabajo);

int buscarLibreTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex);

int buscarReferenciaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex,int id);

int altaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIdAlmuerzo,eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eServicio listaServicio[],int tamServ);

int listarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo);

int hardcodeoTrabajo(eTrabajo listaTrabajo[],int tamTrab,int* pIdTrab,int cant);
