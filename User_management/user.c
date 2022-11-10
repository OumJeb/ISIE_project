#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int add(char * filename, user u )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %d\n",u.name,u.id,u.bd,u.gen,u.mun,u.pw,u.atype);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modify( char * filename, int id, user neww )
{
    int tr=0;
    user u;
    FILE * f1=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f1!=NULL && f2!=NULL)
    {
        while(fscanf(f1,"%s %s %d %d %d %d\n",u.name,u.id,u.bd,u.gen,u.mun,u.atype)!=EOF)
        {
            if(u.id== id)
            {
                fprintf(f2,"%s %s %d %d %d %d\n",neww.id,neww.name,neww.bd,neww.gen,neww.mun,neww.atype);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %d %d\n",u.id,u.name,u.bd,u.gen,u.mun,u.atype);

        }
    }
    fclose(f1);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;

}
int deleteu(char * filename, int id)
{
    int tr=0;
    user u;
    FILE * f1=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f1!=NULL && f2!=NULL)
    {
        while(fscanf(f1,"%s %s %d %d %d %d\n",u.name,u.id,u.bd,u.gen,u.mun,u.atype)!=EOF)
        {
            if(u.id== id)
                tr=1;
            else
                fprintf(f2,"%s %s %d %d %d %d\n",u.name,u.id,u.bd,u.gen,u.mun,u.atype);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
find_user(char * filename, int id)
{
    user u;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %d %d %d\n",u.name,u.id,u.bd,u.gen,u.mun,u.atype)!=EOF)
        {
            if(u.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.id = -1;
    return p;
}
