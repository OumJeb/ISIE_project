#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct {
     int day;
     int month;
     int year;
}date;
typedef struct user
{
    char name[20];
    char id[20];
    date date;
    int gen;
    int mun;
    char pw[20];
    int atype;
} user;

int add(char * filename, user u );
int modify( char * filename, char id[20], user neww);
int deleteu(char * filename, char id[20]);
user find_user(char * filename, char id[20]);

#endif // POINT_H_INCLUDED

