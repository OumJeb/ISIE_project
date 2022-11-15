#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int add(char * filename, user u)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %d %s %d\n",u.name,u.id,u.date.day,u.date.month,u.date.year,u.gen,u.mun,u.pw,u.atype);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modify( char * filename, char id[20], user neww )
{
    int v=0;
    user u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %d \n",u.name,u.id,&u.date.day,&u.date.month,&u.date.year,&u.gen,&u.mun,u.pw,&u.atype)!=EOF)
        {
            if(strcmp(u.id,id)==0)
            {
                fprintf(f2,"%s %s %d %d %d %d %d %s %d \n",neww.id,neww.name,neww.date.day,neww.date.month,neww.date.year,neww.gen,neww.mun,neww.pw,neww.atype);
                v=1;
            }
            else
                fprintf(f2,"%s %s %d %d %d %d %d %s %d\n",u.id,u.name,u.date.day,u.date.month,u.date.year,u.gen,u.mun,u.pw,u.atype);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;

}
int deleteu(char * filename, char id[20])
{
    int v=0;
    user u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %s %d \n",u.name,u.id,&u.date.day,&u.date.month,&u.date.year,&u.gen,&u.mun,u.pw,&u.atype)!=EOF)
        {
            if(strcmp(u.id,id)==0)
                v=1;
            else
                fprintf(f2,"%s %s %d %d %d %d %d %s %d \n",u.name,u.id,u.date.day,u.date.month,u.date.year,u.gen,u.mun,u.pw,u.atype);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;
}
user find_user(char * filename, char id[20])
{
    user u;
    int v;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(v==0 && fscanf(f,"%s %s %d %d %d %d %d %s %d \n",u.name,u.id,&u.date.day,&u.date.month,&u.date.year,&u.gen,&u.mun,u.pw,&u.atype)!=EOF)
        {
            if(u.id == id)
                v=1;
        }
    }
    fclose(f);
    if(v==0)
        u.id[0] = -1;
    return u;
}
