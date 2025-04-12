#include <stdio.h>
#include <stdlib.h>
#include "TAD_set.h"

int menu();

int main() {
	int resp, opc;
	set C1=NULL, C2=NULL, C3=NULL, C4=NULL;
	str cad=NULL;
	
	do{
		resp=menu();
		switch(resp){
		case 1:
			printf("Elija el conjunto: [1]C1 - [2]C2\n");
			scanf("%d", &opc);
			switch(opc){
			case 1: clearSet(&C1); break;
			case 2: clearSet(&C2); break;
			default: printf("\nOpcion invalida");
			}
			printf("\nProceso finalizado\n");
			break;
		case 2:
			clearStr(&cad);
			cad=load();
			printf("Elija a cual conjunto agregarlo: [1]C1 - [2]C2\n");
			scanf("%d", &opc);
			switch(opc){
			case 1: addStr(&C1, cad); break;
			case 2: addStr(&C2, cad); break;
			default: printf("\nOpcion invalida");
			}
			printf("\nProceso finalizado\n");
			break;
		case 3:
			printf("C1: {");
			showSet(C1);
			printf("}\n");
			printf("C2: {");
			showSet(C2);
			printf("}\n");
			printf("C3: {");
			showSet(C3);
			printf("}\n");
			printf("\nProceso finalizado\n");
			break;
		case 4:
			clearSet(&C3);
			clearStr(&cad);
			cad=load2("Lorem,ipsum,dolor,sit,amet,consectetur,adipiscing,elit,Lorem,dolor");
			//cad=load2("1,2,1,2");
			C3=strToSetToken(cad, ',');
			printf("Cadena: "); showStr(cad);
			printf("\nC3: {");
			showSet(C3);
			printf("}");
			printf("\nProceso finalizado\n");
			break;
		case 5:
			clearSet(&C4);
			C4=unionSets(C1, C2);
			printf("Union: {");
			showSet(C4);
			printf("}\n");
			break;
		case 6:
			clearSet(&C4);
			C4=intersectionSets(C1, C2);
			printf("Interseccion: {");
			showSet(C4);
			printf("}\n");
			break;
		case 7:
			clearSet(&C4);
			C4=differenceSets(C1, C2);
			printf("Diferencia: {");
			showSet(C4);
			printf("}\n");
			break;
		case 8:
			if(searchSet(C2, C1)) printf("\nEl conjunto C1 si esta contenido en C2\n");
			else printf("\nEl conjunto C1 no esta contenido en C2\n");
			break;
		case 0:
			printf("\nFin del programa");
			break;
		default:
			system("cls");
			printf("\nOpcion invalida\n");
		}
	} while(resp!=0);
	
	return 0;
}

int menu(){
	int opc;
	printf("\n --MENU DE OPCIONES--\n");
	printf("1-Borrar todos los elementos de un conjunto\n");
	printf("2-Aniadir una cadena a un conjunto\n");
	printf("3-Mostrar los conjuntos\n");
	printf("4-Convertir str a set\n");
	printf("5-Union entre dos conjuntos\n");
	printf("6-Interseccion entre dos conjuntos\n");
	printf("7-Diferencia entre dos conjuntos\n");
	printf("8-Determinar si el conjunto C1 esta contenido en C2\n");
	printf("0-Salir del programa\n");
	printf("Elija una opcion: ");
	scanf("%d", &opc); printf("\n");
	return opc;
}


