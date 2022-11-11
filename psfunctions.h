#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include"functions.h"
typedef struct{
int hours ;
int mins; }time;
typedef struct
{time opt,ct;
char id[15]  ;
int MUNICIPALITYPS ;
int Nrooms;
int capacity ;

}Pollingstation;
int add(char *filename, Pollingstation p);
int modify( char *filename, char id[15], Pollingstation p );
int Deleteps(char *filename, char id[15] );
Pollingstation search(char *filename, char id[15]);



#endif // FUNCTIONS_H_INCLUDED
