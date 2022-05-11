



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "utn.h"
#include "servicio.h"

int listarServicio(eServicio vecServicio[],int tam)
{
	int todoOk =-1;

	if(vecServicio!=NULL && tam>0)
	{
		//ACA SE PUEDE HACER UNA TABLITA O LISTA
		printf("\n------------------  |");
		printf("\n                    |\n");
		printf("------------------  |\n");
		printf("ID |  DESCRIPCION  |  PRECIO  |");
		printf("\n------------------  |\n");
		for(int i=0;i<tam;i++)
		{
			printf(" %d |  %10s  %.2f |\n",vecServicio[i].idServicio, vecServicio[i].descripcion,vecServicio[i].precio);
		}
		printf("\n------------------|\n");
		todoOk = 0;
		system("Pause");
	}
	return todoOk;
}

int buscarIndiceServicio(eServicio vecServicio[],int tam,int id, int* pIndex)
{
	int todoOk = -1;

	if(vecServicio!=NULL && tam>0 && pIndex !=NULL)
	{
		*pIndex = -1;

		for(int i=0;i<tam;i++)
		{
			if(vecServicio[i].idServicio == id)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk=0;
	}

	return todoOk;
}


int cargarServicio(eServicio vecServicio[],int tam,int id, char descripcion[])
{
	int todoOk =-1;

	int indice;
	//ACA SE LLAMA A BUSCAR: Y SE PASA EL INDICE
	buscarIndiceServicio(vecServicio, tam, id, &indice);

	if(vecServicio!=NULL && tam>0 && descripcion!=NULL && indice!=-1)
	{
		for(int i=0;i<tam;i++)
		{
			strcpy(descripcion,vecServicio[indice].descripcion);
			todoOk =0;
		}
	}
	return todoOk;
}


int validarServicio(eServicio vec[], int tam, int id)
{
	int indice;
	int esValido=0;

	buscarIndiceServicio(vec, tam, id, &indice);

	if(indice != -1) //SE FIJA SI ES VALIDO
	{
		esValido = 1;
	}

	return esValido;
}
