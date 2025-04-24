#ifndef ARBOL_H
#define ARBOL_H
#include "TAD_string.h"

#define STR 1
#define SET 2
#define LIST 3
	struct dataType{
	int nodeType;
	// STR, SET, LIST
	union{
		str Str;
		struct{
			struct dataType* data;
			struct dataType* next;
		};
	};
};
typedef struct dataType* arb;

arb createArb();
arb inicializarLis();
arb inicializarSet();

void mostrarArb(arb);
void cargarNodo(arb*);

arb unionDeTodosLosConjuntos(arb);
arb interseccionSets(arb);
arb diferenciaDeConjuntos(arb);
void Inclusion(arb);
void cardinalidadSet(arb);
void Pertenencia(arb);
void eliminarConjuntoIgual(arb*);

#endif
