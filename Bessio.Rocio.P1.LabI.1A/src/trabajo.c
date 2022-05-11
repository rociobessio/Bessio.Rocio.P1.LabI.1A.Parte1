
#include "eMascota.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include"eFecha.h"
#include "eColor.h"
#include "tipo.h"

#include "trabajo.h"
#include "servicio.h"




int inicializarEstructuraTrabajo(eTrabajo listaTrabajo[],int tamTrabajo)
{
	int todoOk = -1;

	if(listaTrabajo!=NULL && tamTrabajo>0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			listaTrabajo[i].isEmpty = 1;

			todoOk = 1;
		}
	}
	return todoOk;
}


int buscarLibreTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex)
{
	int todoOk = -1;

	if(listaTrabajo!=NULL && tamTrabajo>0 && pIndex!=NULL)
	{
		*pIndex= -1;
		for(int i=0;i<tamTrabajo;i++)
		{
			if(listaTrabajo[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int buscarReferenciaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIndex,int id)
{
	int todoOk = -1;

	if(listaTrabajo!=NULL && tamTrabajo>0 && pIndex!=NULL && id>0)
	{
		*pIndex= -1;
		for(int i=0;i<tamTrabajo;i++)
		{
			if(!listaTrabajo[i].isEmpty && listaTrabajo[i].idTrabajo == id)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int altaTrabajo(eTrabajo listaTrabajo[],int tamTrabajo,int* pIdAlmuerzo,eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo,eServicio listaServicio[],int tamServ)
{
	int todoOk = -1;

	int indice;
	int status;

	eFecha fecha;

	eTrabajo trabajoAux;

	//SE CREA UNA VARIABLE AUXILIAR

	if(listaTrabajo!=NULL && tamTrabajo>0 && pIdAlmuerzo!=NULL)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               ALTA   TRABAJO MASCOTA                       |\n");
		printf("____________________________________________________________|\n");
		if(buscarLibreTrabajo(listaTrabajo, tamTrabajo, &indice))
		{
			if(indice==-1)
			{
				showMessage("\nNO HAY MAS ESPACIO EN EL SISTEMA!");
			}
			else
			{
				//ENTRO Y CARGO
				listar(lista, tam, colorMascota, tamColor, tipoLista, tamTipo);

				getValidInt("\nINGRESE ID DE LA MASCOTA: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 1, 500000, &trabajoAux.idMascota);
				buscarReferencia(lista, tam, &indice, trabajoAux.idMascota);

				while(indice ==-1)
				{
					getValidInt("\nID INVALIDO REINGRESE: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 1, 500000, &trabajoAux.idMascota);
					buscarReferencia(lista, tam, &indice, trabajoAux.idMascota);
				}

		         printf("\nINGRESE FECHA DE SERVICIO: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
		         scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);

		         status = isValidDate(&fecha);
		         while(status!=1)
		         {
			         printf("\nERROR REINGRESE FECHA DE SERVICIO VALIDA: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
			         scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);
			         status = isValidDate(&fecha);
		         }
		         trabajoAux.fechaTrabajo = fecha;

		        listarServicio(listaServicio, tamServ);
				getValidInt("\nINGRESE ID DE SERVICIO: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 1, 3, &trabajoAux.idServicio);
				while(!validarServicio(listaServicio, tamServ, trabajoAux.idServicio))
				{
					getValidInt("\nINGRESE ID DE SERVICIO: ", "\nVALOR INVALIDO, REINTENTE: ", "\nINGRESE UNICAMENTE NUMEROS", 1, 3, &trabajoAux.idServicio);

				}




				//CAMBIO EL VALOR DE IS EMPTY
				listaTrabajo[indice].isEmpty = 0;

				//AUMENTO SU ID:
				trabajoAux.idTrabajo = *pIdAlmuerzo;
				*pIdAlmuerzo = *pIdAlmuerzo+1;

				//ACA VOY A COPIAR TODO LO DEL AUXILIR EN LA ORIGINAL
				listaTrabajo[indice] = trabajoAux;

				todoOk = 0;
			}
		}
		else
		{
			showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!");
		}
	}
	return todoOk;
}



int listarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo)
{
	int todoOk = -1;

	int bandera =0;

	if(listaTrabajo!=NULL && tamTrabajo>0)
	{

		//MUESTRO UN ENCABEZADO
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("						  ***LISTADO DE TRABAJOS***                                                      | ");
		showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID TRABAJO |	 ID SERVICIO    |	 ID MASCOTA        |  FECHA SERVIVICIO  |");
		printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
		for(int i = 0;i<tamTrabajo;i++)
		{
			if(!listaTrabajo[i].isEmpty)
			{
				printf(" %4d           %4d        %4d        %02d/%02d/%02d\n",listaTrabajo[i].idTrabajo,
																				listaTrabajo[i].idServicio,
																				listaTrabajo[i].idMascota,
																				listaTrabajo[i].fechaTrabajo.dia,
																				listaTrabajo[i].fechaTrabajo.mes,
																				listaTrabajo[i].fechaTrabajo.anio);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("\nNO HAY TRABAJOS CARGADOS EN EL SISTEMA!");
		}
		todoOk = 0;
		system("Pause");
	}
	return todoOk;
}


int hardcodeoTrabajo(eTrabajo listaTrabajo[],int tamTrab,int* pIdTrab,int cant)
{
	int todoOk = -1;

	eTrabajo auxHarcodeo [] = {
			{2000,1,000,{5,1,2005},0},
			{2001,2,000,{7,10,2004},0},
			{2003,3,000,{6,12,2020},0},
			{2004,3,00,{8,5,1998},0}


	};


	if(listaTrabajo!=NULL && tamTrab>0 && pIdTrab!=NULL && cant>0 && cant<=tamTrab )
	{
		for(int i=0;i<cant;i++)
		{
			listaTrabajo[i] = auxHarcodeo[i];
			listaTrabajo[i].idTrabajo = *pIdTrab;
			*pIdTrab = *pIdTrab+1;
		}
		todoOk = 0;
	}


	return todoOk;
}
