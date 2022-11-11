#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct {
     int month;
     int day;
     int year;
}Date;
typedef struct user
{
    char name[20];
    char id[20];
    Date date;
    int gen[20];
    int mun[20];
    char pw[20];
    int atype[10];
} user;

int add(char *, user);
int modify( char * filename, char id[20], user neww);
int deleteu(char * filename, char id[20]);
user find_user(char * filename, char id[20]);

#endif // POINT_H_INCLUDED

