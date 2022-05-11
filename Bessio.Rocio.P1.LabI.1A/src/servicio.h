

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{

	int idServicio;
	char descripcion[20];
	float precio;

}eServicio;

#endif /* SERVICIO_H_ */

int listarServicio(eServicio vecServicio[],int tam);

int buscarIndiceServicio(eServicio vecServicio[],int tam,int id, int* pIndex);

int cargarServicio(eServicio vecServicio[],int tam,int id, char descripcion[]);

int validarServicio(eServicio vec[], int tam, int id);
