
#include "eMascota.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include"eFecha.h"
#include "eColor.h"
#include "tipo.h"




int mostrarUnico(eMascota lista,int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo)
{
	int todoOk =-1;

	char descripcionColor[50];
	char descripcionTipo[50];

	if(tam>0)
	{
		cargarVectorMascota(colorMascota, tamColor, lista.idColor, descripcionColor);
		cargarTipoMascota(tipoLista, tamTipo, lista.idTipo, descripcionTipo);

		//EN CASO DE TENER OTRAS ENTIDAD SE DEBE DE HACER SU CARGA!
		printf("%4d  %10s   %10s	%10s	         %c            %2d    %02d/%02d/%02d \n",lista.id,
																		lista.nombre,
																		descripcionTipo,
																		descripcionColor,
																		lista.vacunado,
																		lista.edad,
																		lista.fecha.dia,
																		lista.fecha.mes,
																		lista.fecha.anio);
		todoOk = 1;
	}

	return todoOk;
}


int listar(eMascota lista[],int tam,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo)
{
	int todoOk = -1;

	int bandera =0;

	if(lista!=NULL && tam>0)
	{
		showMessage("----------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("						  ***LISTADO DE MASCOTAS***                                                      | ");
		showMessage("|---------------------------------------------------------------------------------------------------------------------------------|");
		showMessage("|  ID |	 NOMBRE    |	TIPO        |   COLOR  |      VACUNADO   | EDAD   |   FECHA  |");
		printf("|---------------------------------------------------------------------------------------------------------------------------------|\n");
		//MUESTRO UN ENCABEZADO O PONERLO EN LA FUNCION A LA CUAL LLAMAMOS

		for(int i = 0;i<tam;i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarUnico(lista[i], tam,colorMascota,tamColor,tipoLista,tamTipo);
				bandera=1;
			}
		}
		if(bandera==0)
		{
			showMessage("\nNO HAY MASCOTAS EN EL SISTEMA!");
		}
		system("Pause");

		todoOk = 0;
	}
	return todoOk;
}



int inicializarEstructura(eMascota lista[],int tam)
{
	int todoOk = -1;

	if(lista!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			lista[i].isEmpty = 1;

			todoOk = 1;
		}
	}
	return todoOk;
}


int buscarLibre(eMascota lista[],int tam,int* pIndex)
{
	int todoOk = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL)
	{
		*pIndex= -1;
		for(int i=0;i<tam;i++)
		{
			if(lista[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int buscarReferencia(eMascota lista[],int tam,int* pIndex,int id)
{
	int todoOk = -1;

	if(lista!=NULL && tam>0 && pIndex!=NULL && id>0)
	{
		*pIndex= -1;
		for(int i=0;i<tam;i++)
		{
			if(!lista[i].isEmpty && lista[i].id == id)
			{
				*pIndex = i;
				break;
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

int alta(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo)
{
	int todoOk = 0;

	int indice;
	char auxCad[50];
	int auxInt;
	char confirmacion;

	eMascota auxMascota; //PONER BIEN EL NOMBRE

	int status;

	eFecha fecha;

	//SE CREA UNA VARIABLE AUXILIAR

	if(lista!=NULL && tam>0 && pId!=NULL)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               ALTA     MASCOTAS                            |\n");
		printf("____________________________________________________________|\n");
		if(buscarLibre(lista, tam, &indice))
		{
			if(indice==-1)
			{
				showMessage("\nNO HAY MAS ESPACIO EN EL SISTEMA!");
			}
			else
			{
				//ENTRO Y CARGO
				getValidString("\nINGRESE NOMBRE DE LA MASCOTA: ", "\nERROR UNICAMENTE LETRAS: ", "\nINGRESE EN UN RANGO VALIDO: ", auxCad, 2, 20);
				strcpy(auxMascota.nombre,auxCad);

				getValidInt("\nINGRESE EL COLOR QUE QUIERE (1-ROJO,2-BLANCO,3-ROJO,4-GRIS,5-AZUL): ", "\nINGRESE UN NUMERO VALIDO (1-ROJO,2-BLANCO,3-ROJO,4-GRIS,5-AZUL):", "\nINGRESE UN NUMERO: ", 1, 5, &auxInt);
				auxMascota.idColor = auxInt;

				getValidInt("\nINGRESE EL TIPO QUE QUIERE (1-AVE,2-PERRO,3-ROEDOR,4-GATO,5-PEZ): ", "\nINGRESE UN NUMERO VALIDO (1-AVE,2-PERRO,3-ROEDOR,4-GATO,5-PEZ): ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 5, &auxInt);
				auxMascota.idTipo = auxInt;

				getUserConfirmation(&confirmacion, "\nESTA VACUNADO (S/N): ", "\nVALOR INVALIDO,INGRESE (S/N): ");

				getValidInt("\nINGRESE LA EDAD DE LA MASCOTA: ", "\nINGRESE UN VALOR VALIDO ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 20, &auxInt);
				auxMascota.edad = auxInt;

		         printf("\nINGRESE FECHA DE NACIMIENTO: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
		         scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);

		         status = isValidDate(&fecha);
		         while(status!=1)
		         {
			         printf("\nERROR REINGRESE FECHA DE NACIMIENTO VALIDA: dd/mm/aaaa: ");//TOMAMOS TRES VARIABLES JUNTAS
			         scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);
			         status = isValidDate(&fecha);
		         }

				//CAMBIO EL VALOR DE IS EMPTY
				lista[indice].isEmpty = 0;

				//AUMENTO SU ID:
				auxMascota.id = *pId;
				*pId = (*pId)+1;

				//ACA VOY A COPIAR TODO LO DEL AUXILIR EN LA ORIGINAL
				lista[indice] = auxMascota;

				todoOk = 1;
			}
		}
		else
		{
			showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!!");
		}
	}
	return todoOk;
}

int baja(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo)
{
	int todoOk;

	int indice;
	int idBuscada; //LUEGO SACAR EL 0

	char confirmacion;

	if(lista!=NULL && tam>0 && pId!=NULL)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               BAJA         MASCOTAS                        |\n");
		printf("____________________________________________________________|\n");
		//SE MUESTRA LA LISTA
		listar(lista, tam,colorMascota,tamColor,tipoLista,tamTipo);
		// SE PIDE LA ID A BUSCAR
		utn_getNumero(&idBuscada, "\nINGRESE LA ID A BUSCAR: ", "\nINGRESE UN VALOR VALIDO: ", 1, 2000, 200000);

		if(buscarReferencia(lista, tam, &indice, idBuscada))
		{
			if(indice==-1)
			{
				printf("\nNO SE ENCONTRO A NINGUNA MASCOTA CON ID Nº%d",idBuscada);
			}
			else
			{
				//SE MUESTRA A ESA ID
				mostrarUnico(lista[indice], tam,colorMascota,tamColor,tipoLista,tamTipo);
				getUserConfirmation(&confirmacion, "\nDESEA DAR DE BAJA A LA MASCOTA (S/N)? ", "\nINGRESE VALOR VALIDO (S/N)? ");
				if(confirmacion =='s')
				{
					lista[indice].isEmpty = 0;
					printf("\nBAJA REALIZADA CON EXITO!");
				}
				else
				{
					printf("\nBAJA CANCELADA!");
				}
				todoOk=1;
			}
		}
	}
	return todoOk;
}

int modificacion(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo)
{
	int todoOk;

	int indice;
	int idBuscada; //LUEGO SACAR EL 0
	char confirma;
	char opcion;

	if(lista!=NULL && tam>0 && pId!=NULL)
	{
		printf("\n____________________________________________________________");
		printf("\n                                                            |");
		printf("\n               MODIFICACION       MASCOTAS                  |\n");
		printf("____________________________________________________________|\n");
		//SE MUESTRA LA LISTA
		listar(lista, tam,colorMascota,tamColor,tipoLista,tamTipo);
		// SE PIDE LA ID A BUSCAR
		utn_getNumero(&idBuscada, "\nINGRESE LA ID A BUSCAR: ", "\nINGRESE UN VALOR VALIDO: ", 1, 2000, 200000);

		if(buscarReferencia(lista, tam, &indice, idBuscada))
		{
			if(indice==-1)
			{
				printf("\nNO SE ENCONTRO A NINGUNA MASCOTA CON ID Nº%d",idBuscada);
			}
			else
			{
				mostrarUnico(lista[indice], tam,colorMascota,tamColor,tipoLista,tamTipo);
				getUserConfirmation(&confirma, "\nDESEA MODIFICAR A LA MASCOTA (S/N)? ", "\nINGRESE VALOR VALIDO (S/N)? ");
				if(confirma =='s')
				{
					printf("\nINGRESE QUE DESEA MODIFICAR: ");
					printf("\nA)TIPO\nB)VACUNADO\n");
					scanf("%c",&opcion);
					while(opcion!='A' && opcion!='B' && opcion !='a' && opcion!='b')
					{
						printf("\nERROR INGRESE UN VALOR VALIDO A/B: ");
						scanf("%c",&opcion);

					}

					switch(opcion)
					{
						case 'A':
							getValidInt("\nINGRESE EL TIPO QUE QUIERE (1-AVE,2-PERRO,3-ROEDOR,4-GATO,5-PEZ): ", "\nINGRESE UN NUMERO VALIDO (1-AVE,2-PERRO,3-ROEDOR,4-GATO,5-PEZ): ", "\nINGRESE NUMEROS UNICAMENTE: ", 1, 5, &lista->idTipo);


						break;
						case 'B':
							getUserConfirmation(&confirma, "\nESTA VACUNADO (S/N): ", "\nVALOR INVALIDO,INGRESE (S/N): ");
						break;
					}

					printf("\nMODIFICACION REALIZADA CON EXITO!");
				}
				else
				{
					printf("\nMODIFICACION CANCELADA!");
				}
				todoOk=1;
			}
		}
	}
	return todoOk;
}

int hardcodeo(eMascota lista[],int tam,int* pId,int cant)
{
	int todoOk = -1;

	eMascota auxHarcodeo [] = {
			{000,1000,5002,"Salchicha",'s',5,{2,3,2002},0},
			{000,1001,5001,"Michi",'n',11,{5,10,2001},0},
			{000,1002,5000,"Nacho",'s',9,{3,11,2003},0},
			{000,1003,5003,"Lola",'n',7,{8,5,1999},0}


	};


	if(lista!=NULL && tam>0 && pId!=NULL && cant>0 && cant<=tam )
	{
		for(int i=0;i<cant;i++)
		{
			lista[i] = auxHarcodeo[i];
			lista[i].id = *pId;
			*pId = *pId+1;
		}
		todoOk = 0;
	}


	return todoOk;
}

int sortByTipoYNombre(eMascota lista[],int tam,int* pId,eColor colorMascota[],int tamColor,eTipo tipoLista[],int tamTipo)
{
	int todoOk = 0;
	eMascota auxMascota;


	if(lista!=NULL && tam>0)
	{
		for(int i = 0; i<tam;i++)
		{
			for(int j = i;j<tam;j++)
			{
				if(strcmp(lista[i].nombre,lista[j].nombre)>0)//ASC
				{
					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
				else if(strcmp(lista[i].nombre,lista[j].nombre)==0 && lista[i].idTipo>lista[j].idTipo)
				{
					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
			}
		}
	}
	listar(lista, tam, colorMascota, tamColor, tipoLista, tamTipo);

	return todoOk;
}

