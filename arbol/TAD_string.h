#ifndef TAD_STRING_H
#define TAD_STRING_H

typedef struct nodoSTR{
	char dato;
	struct nodoSTR* sig; 
}TNodoChar;

typedef TNodoChar* str;
	
str beforeToken(str, char);
str afterToken(str, char);
int cmpStr(str, str);
str cpyStr(str);
void clearStr(str *);
void showStr(str);
str load();
str concat(str,str);
void printer();

#endif
