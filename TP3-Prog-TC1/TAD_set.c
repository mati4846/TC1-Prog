#include "TAD_set.h"
#include <stdio.h>
#include <stdlib.h>

set createNodoSet(){
	set nvo=(set)malloc(sizeof(TNodoStr));
	nvo->string=NULL; nvo->sig=NULL;
	return nvo;
}
	
void deleteRep(set set1){
	set aux=NULL, ant=NULL;
	while(set1!=NULL){
		ant=set1;
		aux=set1->sig;
		while(aux!=NULL){
			if(cmpStr(set1->string, aux->string)==0){
				ant->sig=aux->sig;
				clearStr(&aux->string);
				aux->sig=NULL;
				free(aux);
				aux=ant->sig;
			}
			else{
				ant=aux;
				aux=aux->sig;
			}
		}
		set1=set1->sig;
	}
}

void cpySet(set *set1, set set2){
	if(set2!=NULL){
		*set1=createNodoSet();
		(*set1)->string=cpyStr(set2->string);
		cpySet(&(*set1)->sig, set2->sig);
	}
}

//Modulos publicos

int searchStr(set set1, str STR){
	if(set1!=NULL && cmpStr(set1->string, STR)!=0){
		return searchStr(set1->sig, STR);
	}
	else{
		if(set1==NULL) return 0;
		else return 1;
	}
}

set unionSets(set set1, set set2){
	set unionS=NULL, aux=NULL;
	cpySet(&unionS, set1);
	aux=unionS;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	cpySet(&aux->sig, set2);
	deleteRep(unionS);
	return unionS;
}

set intersectionSets(set set1, set set2){
	set intersection=NULL;
	while(set1!=NULL){
		if(searchStr(set2, set1->string)==1){
			addStr(&intersection, set1->string);
		}
		set1=set1->sig;
	}
	return intersection;
}

set differenceSets(set set1, set set2){
	set difference=NULL, act=NULL, ant=NULL;
	cpySet(&difference, set1);
	while(set2!=NULL){
		ant=NULL; act=difference;
		while(act!=NULL){
			if(ant==NULL && cmpStr(act->string, set2->string)==0){
				difference=act->sig;
				clearStr(&act->string);
				act->sig=NULL;
				free(act);
				act=difference;
			}
			else if(cmpStr(act->string, set2->string)==0){
				ant->sig=act->sig;
				clearStr(&act->string);
				act->sig=NULL;
				free(act);
				act=ant->sig;
			}
			else{
				ant=act; act=act->sig;
			}
		}
		set2=set2->sig;
	}
	return difference;
}
	
set strToSetToken(str cad, char tok){
	set nue=NULL; str aux=beforeToken(cad, tok);
	if(aux!=NULL){
		nue=createNodoSet();
		nue->string = cpyStr(aux);
		nue->sig=strToSetToken(afterToken(cad, tok), tok);
	}
	if(afterToken(cad, tok)!=NULL) deleteRep(nue);
	return nue;
}

int searchSet(set set1, set subset){
	if(subset!=NULL && searchStr(set1, subset->string)) return searchSet(set1, subset->sig);
	else{
		if(subset==NULL) return 1;
		else return 0;
	}
}

void clearSet(set* set1){
	if(*set1!=NULL){
		clearSet(&(*set1)->sig);
		clearStr(&(*set1)->string);
		(*set1)->sig=NULL; free(*set1); (*set1)=NULL;
	}
}

void addStr(set* set1, str cad){
	set aux=NULL;
	if(*set1==NULL){
		*set1 = createNodoSet();
		*set1 = strToSetToken(cad, ' ');
	}
	else{
		aux=*set1;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig = createNodoSet();
		aux->sig = strToSetToken(cad, ' ');
	}
	deleteRep(*set1);
}

void showSet(set set1){
	if(set1!=NULL){
		showStr(set1->string);
		if(set1->sig!=NULL) printf(", ");
		showSet(set1->sig);
	}
}




