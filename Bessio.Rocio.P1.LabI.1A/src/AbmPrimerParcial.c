/*
 ============================================================================
 Name        : AbmPrimerParcial.c
 Author      : Bessio Rocio
 Division    : 1-A
 Fecha       : 11/05/22
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "eMascota.h"//RECORDAR CAMBIAR UNA VEZ ARRANCADO EL PARCIAL
#include  "utn.h"
#include "eFecha.h"
#include "eColor.h"
#include "tipo.h"

#include "trabajo.h"
#include "servicio.h"


int menu();

#define TAM 10

#define TAM_COLOR 5

#define TAM_TIPO 5

#define TAM_TRAB 10

#define TAM_SERV 3

int main(void) {
	setbuf(stdout,NULL);

	char salir = 'n';

	eMascota lista[TAM]; //RECORDAR CAMBIAR NOMBRE

	eColor colorLista[TAM_COLOR] = {
			{5000,"NEGRO"},
			{5001,"BLANCO"},
			{5002,"ROJO"},
			{5003,"GRIS"},
			{5004,"AZUL"}
	};

	eTipo tipoLista[TAM_TIPO] ={
			{1000,"AVE"},
			{1001,"PERRO"},
			{1002,"ROEDOR"},
			{1003,"GATO"},
			{1004,"PEZ"},
	};

	eServicio servicioLista[TAM_SERV] = {
			{3000,"CORTE",450},
			{3001,"DESPARACITADO",800},
			{3002,"CASTRADO",600},

	};

	eTrabajo trabajoLista[TAM_TRAB];

	int idInicial = 1;//CAMBIA DEPENDIENDO LA CONSIGNA

	int idTrabajoRandom = 2000;

	int bandera =1;

	//ACA VA LA INICIALIZACION
	inicializarEstructura(lista, TAM);
	inicializarEstructuraTrabajo(trabajoLista, TAM_TRAB);

	//ACA VA EL HARCODEO LA CANTIDAD QUE LE PASAMOS DEBE SER MENOR A TAM RECORDAR AGREGAR EL HARDCODEO
	hardcodeo(lista, TAM, &idInicial, 4);

	hardcodeoTrabajo(trabajoLista, TAM_TRAB, &idTrabajoRandom, 3);


	do
	{
		switch(menu())
		{
			case 1:
				//ALTA
				if(alta(lista, TAM,&idInicial, colorLista,TAM_COLOR,tipoLista,TAM_TIPO))
				{
					showMessage("\nALTA EXITOSA!");
					bandera=0;

				}
				else
				{
					showMessage("\nOCURRIO UN PROBLEMA CON EL SISTEMA!");
				}
			break;
			case 2:
				//BAJA
				if(bandera==1)
				{
					printf("NO HAY NINGUNA MASCOTA DENTRO DEL SISTEMA!");
				}
				else
				{
					baja(lista, TAM, &idInicial, colorLista,TAM_COLOR,tipoLista,TAM_TIPO);
				}

			break;
			case 3:
				//MODIFICACION
				if(bandera==1)
				{
					printf("NO HAY NINGUNA MASCOTA DENTRO DEL SISTEMA!");
				}
				else
				{
					modificacion(lista, TAM, &idInicial, colorLista,TAM_COLOR,tipoLista,TAM_TIPO);
				}

			break;
			case 4:
				//ORDENAMIENTO
				sortByTipoYNombre(lista, TAM, &idInicial, colorLista, TAM_COLOR, tipoLista, TAM_TIPO);
			break;
			case 5:
				listarTipoMascota(tipoLista, TAM_TIPO);
			break;
			case 6:
				listarColor(colorLista, TAM_COLOR);
			break;
			case 7:
				listarTipoMascota(tipoLista, TAM_TIPO);
			break;
			case 8:
				//ALTA  TRABAJO
				altaTrabajo(trabajoLista, TAM_TRAB, &idTrabajoRandom, lista, TAM, colorLista, TAM_COLOR, tipoLista, TAM_TIPO, servicioLista, TAM_SERV);
			break;
			case 9:
				//LISTAR TRABAJO
				listarTrabajos(trabajoLista, TAM_TRAB);

			break;
			case 10:
				getUserConfirmation(&salir, "\nDESEA FINALIZAR EL PROGRAMA (S/N)?", "\nERROR, INGRESE UN VALOR VALIDO (S/N): ");
				if(salir=='s')
				{
					showMessage("\nPROGRAMA FINALIZADO....");
				}
				else
				{
					showMessage("\nFINALIZACION CANCELADA....");
				}
			break;
		}
	}while(salir!='s');




	return EXIT_SUCCESS;
}


int menu()
{
	int opcion;
	printf("\n\n\n\n");
	printf("\n____________________________________________________________");
	printf("\n                                                            |");
	printf("\n                ABM    MASCOTAS                             |\n");
	printf("____________________________________________________________|\n");
	printf("____________________________");
	printf("\n|1)ALTA MASCOTA            |\n|"
			"2)BAJA   MASCOTA          |\n|"
			"3)MODIFICACION  MASCOTA   |\n|"
			"4)MOSTRAR LISTA MASCOTAS  |\n|"
			"5)LISTAR TIPOS            |\n|"
			"6)LISTAR COLORES          |\n|"
			"7)LISTAR SERVICIOS        |\n|"
			"8)ALTA TRABAJO            |\n|"
			"9)LISTAR TRABAJOS         |\n|"
			"10)SALIR                  |\n");
	printf("|__________________________|");
	utn_getNumero(&opcion, "\nINGRESE UN NUMERO: ", "\nERROR, REINGRESE UN NUMERO VALIDO: ", 1, 10, 1000);

	return opcion;
}
