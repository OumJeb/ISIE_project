#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "claimsfunctions.h"

    int add_claims(char* filename,Claims cl){
    
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %d %d %d %d %d %d %s\n",cl.id,cl.type[0],cl.type[1],cl.type[2],cl.electoral_list,cl.date.day,cl.date.month,cl.date.year,cl.municipality,cl.text);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modify_claims( char * filename, char id[20],Claims cnew)
{
    int v=0;
    Claims cl;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d %d %d %d %d %s\n",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],&cl.electoral_list,&cl.date.day,&cl.date.month,&cl.date.year,&cl.municipality,cl.text)!=EOF)
        {
            if(strcmp(cl.id,id)==0)
            {
                fprintf(f2,"%s %d %d %d %d %d %d %d %d %s\n",cnew.id,cnew.type[0],cnew.type[1],cnew.type[2],cnew.electoral_list,cnew.date.day,cnew.date.month,cnew.date.year,cnew.municipality,cnew.text);
                v=1;
            }
            else
            {
                fprintf(f2,"%s %d %d %d %d %d %d %d %d %s\n",cl.id,cl.type[0],cl.type[1],cl.type[2],cl.electoral_list,cl.date.day,cl.date.month,cl.date.year,cl.municipality,cl.text);
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
    Claims cl;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("new.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d %d %d %d %d %s\n",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],&cl.electoral_list,&cl.date.day,&cl.date.month,&cl.date.year,&cl.municipality,cl.text)!=EOF)
        {
            if (strcmp(cl.id,id)==0)
                v=1;
            else
                fprintf(f2,"%s %d %d %d %d %d %d %d %d %s\n",cl.id,cl.type[0],cl.type[1],cl.type[2],cl.electoral_list,cl.date.day,cl.date.month,cl.date.year,cl.municipality,cl.text);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;}

Claims search_claims(char * filename, char id[20])
{
    Claims cl;
    int v;
    FILE * f=fopen(filename,"r");
    if(f!=NULL)
    {
        while((fscanf(f,"%s %d %d %d %d %d %d %d %d %s\n",cl.id,&cl.type[0],&cl.type[0],&cl.type[0],&cl.electoral_list,&cl.date.day,&cl.date.month,&cl.date.year,&cl.municipality,cl.text)!=EOF)&& v==0)
        {
              if(strcmp(cl.id,id)==0)
                    v=1;


        }
    }
    fclose(f);
    if(v==0)
        cl.id[0]=-1;
    return cl;
}






