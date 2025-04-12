#include "TAD_string.h"
#include <stdio.h>
#include <stdlib.h>

str create(){
	str nod;
	nod=(str)malloc(sizeof(TNodoChar));
	nod->sig=NULL;
	return nod;
}	

void Vaciar(){
	char c;
	if((c=getchar())!=EOF && c !='\n'){
		Vaciar();
	}
}
	
void agregaFin(str *s1,str nue){
	str aux;
	if(*s1==NULL)*s1=nue;
	else{
		aux=*s1;
		while(aux->sig!=NULL)
		aux=aux->sig;
		aux->sig=nue;
	}
}

str load(){
	char m;
	str s1=NULL, nue=NULL;
	printf("ingrese la cadena: ");
	Vaciar();
	m=getchar();
	//printf("m=%c\n",m);
	while(m!='\n'){
		nue=create();
		nue->dato=m;
		agregaFin(&s1,nue);
		m=getchar();
		//printf("m siclo=%c\n",m);
	}
	return s1;
}

str load2(const char *pal){
	str s1=NULL,nue=NULL;
	int i=0;
	//printf("palabra:%c\n",pal[i]);
	while(pal[i]!='\0'){
		nue=create();
		nue->dato=pal[i];
		agregaFin(&s1,nue);
		i++;
		//printf("palabra:%c\n",pal[i]);
	}
	return s1;
}


str beforeToken(str S1,char c){
	str aux=NULL,s3=NULL,nue=NULL;
	aux=S1;
	while(aux!=NULL  && aux->dato!= c ){
		nue=create();
		nue->dato=aux->dato;
		agregaFin(&s3,nue);
		aux=aux->sig;
	}
	return s3;
}
	
str afterToken(str S1, char c){
	while(S1!=NULL && S1->dato!= c ){
		S1=S1->sig;
	}
	if(S1!=NULL) return cpyStr(S1->sig);
	else return NULL;
}

str concat(str s1,str s2){
	str s3=NULL,nue=NULL;
	str aux1=s1,aux2=s2;
	while(aux1!=NULL){
		nue=create();
		nue->dato=aux1->dato;
		agregaFin(&s3,nue);
		aux1=aux1->sig;
	}
	while(aux2!=NULL){
		nue=create();
		nue->dato=aux2->dato;
		agregaFin(&s3,nue);
		aux2=aux2->sig;
	}
	return s3;
}

void showStr(str p1){
	if(p1!=NULL){
		while(p1!=NULL){
			printf("%c",p1->dato);
			p1=p1->sig;
		}
	}
	else
	printf("vacio\n");
}

void printer(){
	printf("se importo string.h con exito\n");
}

void clearStr(str *S1){
	if(*S1!=NULL){
		clearStr( &((*S1)->sig));
		(*S1)->sig=NULL; free(*S1);
	}
}
	
int cmpStr(str S1, str S2){
	if(S1!=NULL && S2!=NULL && S1->dato==S2->dato) return cmpStr(S1->sig, S2->sig);
	else{
		if(S1==NULL && S2==NULL) return 0;
		else{
			if( S2==NULL || (S1->dato)>(S2->dato) ) return 1;
			else return -1;
		}
	}
}

str cpyStr(str S1){
	str aux=NULL;
	if(S1!=NULL){
		aux=create();
		aux->dato=S1->dato;
		aux->sig = cpyStr(S1->sig);
	}
	return aux;
}






