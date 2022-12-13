#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct {
     int month;
     int day;
     int year;
}date;
typedef struct user
{
    char name[20];
    char id[20];
    date date;
    int gen;
    char mun[20];
    char pw[20];
    int atype[10];
    char vote[5];

} user;

int add(char * filename, user neww);
int modify( char * filename, char id[20], user neww);
int deleteu(char * filename, char id[20]);
user find_user(char * filename, char id[20]);
float average( char* usersfile);
int nbrclaims( char * claimsfile, char *  electorallist);

#endif // POINT_H_INCLUDED

