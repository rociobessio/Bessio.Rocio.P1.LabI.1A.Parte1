
#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

	int idTipo;

	char descripcion[20];


}eTipo;

#endif /* TIPO_H_ */
int validarTipo(eTipo vec[], int tam, int id);

int cargarTipoMascota(eTipo vec[],int tam,int id, char descripcion[]);

int buscarIndiceTipo(eTipo vec[],int tam,int id, int* pIndex);

int listarTipoMascota(eTipo vec[],int tam);
