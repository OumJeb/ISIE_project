#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>

    int add_claims(char* file name,claims cl){
    {
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %d/%d/%d %d %s\n",cl.ID,cl.type,cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modify_claims( char * filename, char id[20],claims cnew)
{
    int v=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d/%d/%d %d %s\n",cl.id,cl.type,cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text)!=EOF)
        {
            if(strcmp(cl.id,id)==0)
            {
                fprintf(f2,"%s %d %d %d/%d/%d %d %s\n",cnew.id,cl.type,cnew.electoral_list,cnew.date.d,cnew.date.m,cnew.date.y,cnew.municipality,cnew.text);
                v=1;
            }
            else
            {
                fprintf(f2,"%s %d %d %d/%d/%d %d %s\n",cl.ID,cl.type,cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text);
            }

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt",filename);
    return v;

}

int delete_claims (char * filename, char id[20])
{
    int v=0;
    claims cl;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("new.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d/%d/%d %d %s\n",cl.id,cl.type,cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text)!=EOF)
        {
            if (strcmp(cl.id,id)==0)
                v=1;
            else
                fprintf(f2,"%s %d %d %d/%d/%d %d %s\n",cl.ID,cl.type,cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;}

election search_claims(char * filename, char id[20])
{
    claims cl;
    int v;int i;
    FILE * f=fopen(filename,"r");
    if(f!=NULL)
    {
        while((fscanf(f,"%s %d %d %d/%d/%d %d %s\n",cl.id,cl.type,cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text)!=EOF)&& v==0)
        {
              if(strcmp(cl.id,id)==0)
                    v=1;


        }
    }
    fclose(f);
    if(v==0)
        cl.id[0]=-1;
    return e;
}






