/*
 * eColor.h
 *
 *  Created on: 11 may. 2022
 *      Author: claudia
 */

#ifndef ECOLOR_H_
#define ECOLOR_H_

typedef struct{
	int idColor;
	char descripcion[20];
}eColor;

#endif /* ECOLOR_H_ */

int listarColor(eColor vec[],int tam);

int buscarIndice(eColor vec[],int tam,int id, int* pIndex);

int cargarVectorMascota(eColor vec[],int tam,int id, char descripcion[]);

int validarColor(eColor vec[], int tam, int id);
