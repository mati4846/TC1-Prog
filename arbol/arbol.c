#include "arbol.h"
#include <stdlib.h>
#include <stdio.h>
arb inicializarRaiz(){
	arb A=NULL;// int opc;
	A=(struct dataType*)malloc(sizeof(struct dataType));
	A->Str=NULL;
	A->data=NULL;
	A->next=NULL;
	//printf("ingrese tipo de dato: [2]SET  [3]LIST:");
	//scanf("%d",&opc);
	//A->nodeType=opc;// set o list
	return A;
}
arb inicializarLis(){
	arb A=NULL;
	A=inicializarRaiz();
	A->nodeType=LIST;
	return A;
}
arb inicializarSet(){
	arb B=NULL;
	B=inicializarRaiz();
	B->nodeType=SET;
	return B;
}
	
//crea nodo para un STR
arb createArb(){
	arb A=NULL;int opc;
	A=(struct dataType*)malloc(sizeof(struct dataType));
	A->Str=NULL;
	A->data=NULL;
	//printf("ingrese tipo de dato: [1]STR  [2]SET  [3]LIST:");
	//scanf("%d",&opc);
	A->nodeType=STR;
	A->next=NULL;
	return A;
}
//crea un nodo para un SET o LIST (Raiz)

//carga un STR
void cargarNodoStr(arb *A){
	//printf("En cargarNodoStr, *A = %p\n", (void*)(*A));
	
	arb B,aux; 
	B=createArb();
	printf("ingrese elemento:");
	B->Str=load();
	//printf("B->nodeType:%d\n",B->nodeType);
	
	if(*A==NULL)
		*A=B;
	else{
		aux=(*A);
		
		while(aux->next!=NULL)
			aux=aux->next;
		aux->next=B;
		//printf("nodoInSet:\n");
		//showStr(B->Str);
		
	}
}
void cargarNodo(arb *conj){
	int opc;
	printf("ingrese tipo de dato: [1]STR  [2]SET  [3]LIST:");
	scanf("%d",&opc);
	cargarArbol(conj,opc);
}
void cargarArbol(arb *A,int opc){//carga bien parece
	arb B,C=NULL,aux; int op;
	
	
	//printf("raiz->nodeType:%d\n",(*A)->nodeType);
	switch(opc){
	case STR:
		B=createArb();
		//printf("nodetype al crear:%d\n",B->nodeType);
		printf("ingrese elemento:");
		B->Str=load();
		
		if((*A)->data==NULL){
			(*A)->data=B;
			/*if((B->nodeType==SET ||B->nodeType==LIST){
				//pedir cargar nodo que tenga nodetype=1
				cargaNodoStr(&C);
			}*/
			//printf("nodo1:\n");
			showStr(B->Str);}
		else{
			//*A=(*A)->data;
			aux=(*A)->data; //*A;el primero elemento
			//printf("aux->nodeType:%d\n",aux->nodeType);
			while(aux->next!=NULL)
				aux=aux->next;
			aux->next=B;
			//printf("nodo2:\n");
			showStr(B->Str);
		}
		break;
	case SET:
		
		B=inicializarRaiz();
		B->nodeType=SET;// set o list
		//printf("nodetype al crear:%d\n",B->nodeType);
		
		if((*A)->data==NULL){
			(*A)->data=B;
			do{
				cargarNodoStr(&C);
				
				printf("ingresar otro: [1]si  [2]no:");
				scanf("%d",&op);
			} while(op!=2);
			B->data=C;
		}
		else{
			aux=(*A)->data; //*A;el primero elemento
			//printf("aux->nodeType:%d\n",aux->nodeType);
			while(aux->next!=NULL)
				aux=aux->next;
			aux->next=B;
			//printf("Antes de cargar STRs, C = %p\n", (void*)C);
			
			do{
				cargarNodoStr(&C);
				
				printf("ingresar otro: [1]si  [2]no:");
				scanf("%d",&op);
			} while(op!=2);
			B->data=C;
		}
		break;
		
	case LIST:
		
		B=inicializarRaiz();
		B->nodeType=LIST;// set o list
		
		
		//printf("nodetype al crear:%d\n",B->nodeType);
		
		if((*A)->data==NULL){
			(*A)->data=B;
			do{
				cargarNodoStr(&C);
				
				printf("ingresar otro: [1]si  [2]no:");
				scanf("%d",&op);
			} while(op!=2);
			B->data=C;
		}
		else{
			aux=(*A)->data; //*A;el primero elemento
			//printf("aux->nodeType:%d\n",aux->nodeType);
			while(aux->next!=NULL)
				aux=aux->next;
			aux->next=B;
			//printf("Antes de cargar STRs, C = %p\n", (void*)C);
			
			do{
				cargarNodoStr(&C);
				
				printf("ingresar otro: [1]si  [2]no:");
				scanf("%d",&op);
			} while(op!=2);
			B->data=C;
		}
		break;
	}
}
void mostrarArb(arb A){
	arb aux; int Band=0;
	if(A->data==NULL){
		if(A->nodeType== SET)
			printf("B={}");
		else
			printf("A=[]");
	}else{
		printf("---Arbol----\n");	
		//printf("raiz->nodeType:%d\n",A->nodeType);
		if(A->nodeType==SET){
			Band=1;
			printf("B={");
		}
		else
			printf("A=[");
		
		A=A->data;
		
		while(A!=NULL){
			switch(A->nodeType){
			case STR:
				//printf("A->nodeType:%d\n",A->nodeType);
				//printf("\nnodo:\n");
				showStr(A->Str);
				printf(",");
				break;
			case SET:
				//printf("A->nodeType:%d\n",A->nodeType);
				printf("{");
				aux=A->data;
				//printf("aux->nodeType:%d\n",aux->nodeType);
				while(aux!=NULL){
					//printf("\nnodo:\n");
					showStr(aux->Str);
					printf(",");
					aux=aux->next;
				}	
				
				printf("}");
				break;
			case LIST:
				//printf("A->nodeType:%d\n",A->nodeType);
				printf("[");
				aux=A->data;
				//printf("aux->nodeType:%d\n",aux->nodeType);
				while(aux!=NULL){
					//printf("\nnodo:\n");
					showStr(aux->Str);
					printf(",");
					aux=aux->next;
				}	
				
				printf("]");
			}
			A=A->next;
		}
		if(Band==1)
			printf("}");
		else
			printf("]");
	}
}
//=========OPERACIONES ENTRE CONJUNTOS==========

//======== union ====================
arb unionDeTodosLosConjuntos(arb raiz) {
	if (raiz == NULL || raiz->data == NULL) return NULL;
	
	arb resultado = NULL;  // conjunto resultado
	resultado=inicializarRaiz();
	resultado->nodeType=SET;// set 
	
	arb nodo = raiz->data;
	
	while (nodo != NULL) {
		if (nodo->nodeType == SET) {
			arb elementos = nodo->data;
			
			while (elementos != NULL) {
				cpyArb(&resultado, elementos->Str);
				elementos = elementos->next;
			}
		}
		nodo = nodo->next;
	}
	
	return resultado;
}
void cpyArb(arb *set, str rama) {
	if ((*set)->data == NULL) {
		arb nuevoSet = inicializarRaiz();
		nuevoSet->nodeType = SET;
		(*set)->data = nuevoSet;
	}
	
	agregarSiNoExiste(&((*set)->data), rama);
}

//======= cardinalidad  ================
void cardinalidadSet(arb raiz){
	int cant=0,i=0;
	if (raiz == NULL || raiz->data == NULL) 
		return NULL;
	arb nodo = raiz->data;
	while (nodo != NULL) {
		if (nodo->nodeType == SET) {
			i++;
			arb elementos = nodo->data;
			while (elementos != NULL) {
				cant++;
				elementos = elementos->next;
			}
			
			printf("|set[%d]|:%d\n",i,cant);
			cant=0;
		}
		nodo = nodo->next;
	}
	
}

//=========  interseccion  ===============
	arb interseccionSets(arb raiz){
		arb resultado = NULL, set1 = NULL, nodo = NULL, elem = NULL;
		
		if (raiz != NULL && raiz->data != NULL) {
			resultado = inicializarRaiz();
			resultado->nodeType = SET;
			
			nodo = raiz->data;
			
			// Busca el  primer conjunto SET 
			int encontrado = 0;
			while (nodo != NULL && encontrado == 0) {
				if (nodo->nodeType == SET) {
					set1 = nodo->data;
					encontrado = 1;
				}
				nodo = nodo->next;
			}
			
			if (encontrado == 1) {
				nodo = raiz->data;
				while (nodo != NULL) {
					if (nodo->nodeType == SET && nodo->data != set1) {
						elem = nodo->data;
						while (elem != NULL) {
							if (existeEnSet(set1, elem->Str) == 1) {
								agregarSiNoExiste(&resultado, elem->Str);
							}
							elem = elem->next;
						}
					}
					nodo = nodo->next;
				}
			}
		}
		return resultado;
	}
		
int existeEnSet(arb set, str palabra) {
	int existe = 0;
	arb aux = set;
	while (aux != NULL && existe == 0) {
		if (cmpStr(aux->Str, palabra) == 0) {
			existe = 1;
		}
		aux = aux->next;
	}
	return existe;
}
void agregarSiNoExiste(arb *conj, str palabra) {
	arb nuevo, aux, ultimo = NULL;
	int existe = 0;
	
	if ((*conj)->data == NULL) {
		nuevo = createArb();
		nuevo->Str = cpyStr(palabra);
		(*conj)->data = nuevo;
	} else {
		aux = (*conj)->data;
		
		while (aux != NULL) {
			if (cmpStr(aux->Str, palabra) == 0)
				existe = 1;
			ultimo = aux;  // guarda siempre el último nodo
			aux = aux->next;
		}
		
		if (!existe) {
			nuevo = createArb();
			nuevo->Str = cpyStr(palabra);
			ultimo->next = nuevo;
		}
	}
}


//=============  diferencia  =================
arb diferenciaDeConjuntos(arb raiz) {
	if (raiz == NULL || raiz->data == NULL) 
		return NULL;
	int band=0;
	arb resultado = NULL;  // conjunto resultado
	resultado=inicializarRaiz();
	resultado->nodeType=SET;// set 
	
	arb nodo = raiz->data;
	while (nodo != NULL) {
		if (nodo->nodeType == SET) {
			arb elementos = nodo->data;
			//printf("Entrando a SET\n");
			
			if (band == 0) {//copia el primer set
				while (elementos != NULL) {
					cpyArb(&resultado, elementos->Str);
					elementos = elementos->next;
				}
				band = 1;
			}
			else {
				//printf("pppp\n");
				while (elementos != NULL) {
					eliminaRep(&(resultado->data->data),elementos->Str);
					elementos = elementos->next;
				}
			}
		}
		nodo = nodo->next;
	}
	
	return resultado;
}

void eliminaRep(arb *set, str palabra) {/*
	printf("Estoy en elimina\n");
	printf("estoy en elimina\n");
	printf("data:%p\n",(*set)->data);
	printf("next:%p\n",(*set)->next);
	printf("nodetype:%d\n",(*set)->nodeType);
	printf("str:%s\n",(*set)->Str);*/
	arb aux = *set;
	arb ant = NULL;
	
	while (aux != NULL && cmpStr(aux->Str, palabra) != 0) {
		ant = aux;
		aux = aux->next;
	}
	
	if (aux != NULL) {
		printf("Eliminando: %s\n", aux->Str);
		if (ant == NULL) {
			*set = aux->next;
		} else {
			ant->next = aux->next;
		}
		clearStr(&(aux->Str));
		free(aux);
	}
}


//=============  pertenencia  =================
void Pertenencia(arb raiz) {
	if (raiz == NULL || raiz->data == NULL) 
		return NULL;
	int band=0,bandFin=0,bandSet=0,opc;
	
	printf("elemento a buscar: [1]un elemento  [2]un conjunto");
	scanf("%d",&opc);
	
	arb pertenencia = NULL;  // conjunto contenedor pert
	pertenencia=inicializarRaiz();
	pertenencia->nodeType=SET;// set 
	
	cargarArbol(&pertenencia,opc);
	mostrarArb(pertenencia);
	if(opc==1)
		band=1;
	arb nodo = raiz->data;
	while (nodo != NULL && bandFin==0) {
		if (nodo->nodeType == SET && band==0) {
			arb elementos = nodo->data;
			arb elementosIngre=pertenencia->data->Str;
			//printf("Entrando a SET\n");

			while (elementos != NULL && elementosIngre!=NULL && bandSet==0) {
				if(cmpStr(elementosIngre->Str,elementos->Str)!=0)
					bandSet=1;
				elementos = elementos->next;
				elementosIngre=elementosIngre->next;
			}
			if(elementos == NULL && elementosIngre==NULL && bandSet==0){
				bandFin=1;
				printf("el conjunto ingresado si pertenece al conjunto");
			}else
			   bandSet=0;
		}
		
		if (nodo->nodeType == STR && band==1) {
			if(cmpStr(nodo->Str,pertenencia->data->Str)==0){
				printf("pertenece\n");
				bandFin=1;
			}
		}
		nodo = nodo->next;
	}
	if(bandFin==0)
		   printf("no pertenece al conjunto\n");
}

//============== inclucion ===================
void Inclusion(arb raiz) {
	if (raiz == NULL || raiz->data == NULL) 
		return NULL;
	int band=0,bandFin=0,bandSet=0;
	

	arb pertenencia = NULL;  // conjunto contenedor pert
	pertenencia=inicializarRaiz();
	pertenencia->nodeType=SET;// set 
	
	cargarArbol(&pertenencia,2);
	mostrarArb(pertenencia);

	
	arb elementosIngre=pertenencia->data->Str;
	while (elementosIngre != NULL && bandSet==0)  {
		bandFin=0;
		/*
		printf("elem====\n");
		printf("data:%p\n",elementosIngre->data);
		printf("next:%p\n",elementosIngre->next);
		printf("nodetype:%d\n",elementosIngre->nodeType);
		printf("str:%s\n",elementosIngre->Str);
		*/
		arb nodo = raiz->data;
		
		while(nodo!=NULL && bandFin==0){/*
			printf("nodo====\n");
			printf("data:%p\n",nodo->data);
			printf("next:%p\n",nodo->next);
			printf("nodetype:%d\n",nodo->nodeType);
			printf("str:%s\n",nodo->Str);
			*/
			
			if (nodo->nodeType == SET) {
				arb elementos = nodo->data;
				/*printf("===yyyy==\n");
				printf("nodetype:%d\n",elementos->nodeType);
				printf("str:%s\n",elementos->Str);*/
				while(elementos!=NULL){
					if(cmpStr(elementos->Str,elementosIngre->Str)==0){//si  esta
						bandFin=1;//printf("===ddd==\n");
					}
					elementos=elementos->next;
				}
				
			}
			if(nodo->nodeType ==STR){/*
				printf(" hhhh====\n");
				printf("data:%p\n",nodo->data);
				printf("next:%p\n",nodo->next);
				printf("nodetype:%d\n",nodo->nodeType);
				printf("str:%s\n",nodo->Str);
				*/
				if(cmpStr(elementosIngre->Str,nodo->Str)==0){
					bandFin=1;//printf("===aaaa==\n");
				}
			}
			//printf("bandFin:%d\n",bandFin);
			nodo=nodo->next;
			
			
		}
		if(bandFin==0)//{//no encontre el elempento en el conj B
			bandSet=1;//printf("===tttt==\n");}//bandSet=1 no encontre el elem en el conj B
		/*else
		   printf("encontrado\n");*/
		elementosIngre=elementosIngre->next;
	}
	if(bandSet==1)
		printf("el conjunto ingresado no esta contenido en el conjunto\n");
	else
		printf("el conjunto ingresado esta contenido\n");
}

//========== eliminar conj ===============
void eliminarConjuntoIgual(arb *raiz) {
	if (*raiz == NULL || (*raiz)->data == NULL)
		return;
	
	arb conjuntoIngresado = inicializarRaiz();
	conjuntoIngresado->nodeType = SET;
	cargarArbol(&conjuntoIngresado, 2); // Carga un SET
	mostrarArb(conjuntoIngresado);
	
	arb actual = (*raiz)->data;
	arb anterior = NULL;
	int eliminado = 0;
	
	while (actual != NULL && eliminado == 0) {
		if (actual->nodeType == SET) {
			arb a = actual->data;
			arb b = conjuntoIngresado->data->Str;
			
			int iguales = 1;//se encontro
			/*printf("==== uuu =====\n");
			printf("nodetype:%d\n",a->nodeType);
			printf("str:%s\n",a->Str);
			showStr(a->Str);
			
			printf("==== vvvv =====\n");
			printf("nodetype:%d\n",b->nodeType);
			printf("str:%s\n",b->Str);
			showStr(b->Str);
			*/
			while (a != NULL && b != NULL && iguales==1) {
				
				if (cmpStr(a->Str, b->Str) != 0)
					iguales = 0;
				a = a->next;
				b = b->next;
				/*printf("a apunta a: %p\n", (void*)a);
				printf("a apunta b: %p\n", (void*)b);
				printf("bad:%d",iguales);*/
			}
			
			if (a != NULL || b != NULL){
				//printf("==== lista dispareja =====\n");
				iguales = 0;
			}/*
			printf("comparacion\n");
			printf("bad:%d\n",iguales);*/
			if (iguales==1) {
				if (anterior == NULL){//es el primer set
					//printf("== iiii ===\n");
					(*raiz)->data = actual->next;
				}else{
					anterior->next = actual->next;
					//printf("==  ooo ===\n");
				}
				
				eliminado = 1;
				printf("Conjunto eliminado correctamente.\n");
			} else {
				anterior = actual;
				actual = actual->next;
			}
			
		}
		else {
			anterior = actual;
			actual = actual->next;
		}
	}
	if (!eliminado)
		printf("El conjunto no se encontró.\n");
}
