
#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>




int menu();


int main(){
	int bandL=0,bandS=0, opcOp;
	printer();
	arb A=NULL,B=NULL,C=NULL;int resp;

	
	do{
		
		resp=menu();
		switch(resp){
		case 1:
			printf("====Inicializada la Lista====\n");
			A=inicializarLis();
			bandL=1;
			break;
		case 2:
			if(bandL==1){
				printf("====cargar List====\n");
				cargarNodo(&A);
			}else
			   printf("inicialize la lista primero\n");
			
			break;
		case 3:
			if(bandL==1){
				printf("====Mostrar Lista====\n");
				mostrarArb(A);
			}else
			   printf("inicialize la lista primero\n");
			break;
		case 4:
			printf("====Inicializado el Set====\n");
			bandS=1;
			B=inicializarSet();
			break;
		case 5:
			if(bandS==1){
				printf("====cargar Set====\n");
				cargarNodo(&B);
			}else
			   printf("inicialize la Set primero\n");
			
			break;
		case 6:
			if(bandS==1){
				printf("====Mostrar Set====\n");
				mostrarArb(B);
				if(C==NULL)
					printf("C={}");
				else
					mostrarArb(C);
			}else
			   printf("inicialize Set primero\n");
			
			
			break;
		case 7:
			
			printf("===Operaciones con conjuntos===\n");
			printf("1-Union entre dos conjuntos\n");
			printf("2-Interseccion entre dos conjuntos\n");
			printf("3-Diferencia entre dos conjuntos\n");
			printf("4-inclucion de conjuntos\n");
			printf("5-Cardinalidad\n");
			printf("6-Pertenencia\n");
			printf("7-Eliminar conjunto\n");
			printf("Elija una opcion: ");
			scanf("%d", &opcOp);
			switch(opcOp){
			case 1:
				C=NULL;
				C=unionDeTodosLosConjuntos(B);
				printf("se completo\n");
				mostrarArb(C);
				break;
			case 2: 
				C=NULL;
				C=interseccionSets(B);
				printf("se completo\n");
				mostrarArb(C);
				break;
			case 3: 
				C=NULL;
				C=diferenciaDeConjuntos(B);
				printf("se completo\n");
				mostrarArb(C);
				break;
			case 4: 
				Inclusion(B);
				
				break;
			case 5: 
				cardinalidadSet(B);
				break;
			case 6: 
				
				Pertenencia(B);
				break;
			case 7: 
				eliminarConjuntoIgual(&B);
				break;
			default: printf("\nOpcion invalida");
			}
		case 0:
			printf("\nFin del programa");
			break;
		default:
			printf("\nOpcion invalida\n");
		}
	} while(resp!=0);
	
	
	
	return 0;
}

int menu(){
	int opc;
	printf("\n --MENU DE OPCIONES--\n");
	printf("1-inicializar Lista\n");
	printf("2-cargar una lista\n");
	printf("3-Mostrar una lista\n");
	
	printf("4-Crear conjunto vacio\n");
	printf("5-Cargar conjuntos\n");
	printf("6-mostrar conjunto conjuntos\n");
	
	printf("7-Operaciones con conjuntos\n");
	
	printf("Elija una opcion: ");
	scanf("%d", &opc); 
	return opc;
}	
	
