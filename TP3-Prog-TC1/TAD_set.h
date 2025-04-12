#ifndef TAD_SET_H
#define TAD_SET_H
#include "TAD_string.h"

typedef struct nodo{
	str string;
	struct nodo *sig;
}TNodoStr;

typedef TNodoStr* set;

set strToSetToken(str, char);
set unionSets(set, set);
set intersectionSets(set, set);
set differenceSets(set, set);
int searchSet(set, set);
int searchStr(set, str);
void cpySet(set *, set);
void clearSet(set*);
void addStr(set *, str);
void showSet(set);

#endif
