#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"psfunctions.h"
int add(char * filename,Pollingstation p)
{
     FILE * f=fopen(filename,"a");
     if(f!=NULL)
        {
            fprintf(f,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity);
            fclose(f);
            return 1;
        }
            else return 0 ;

}
int modifyps (char * filename ,char id[15] , Pollingstation nouv)
{


    int tr=0;
    Pollingstation p;
    FILE *f=fopen(filename,"r");
    FILE *f2=fopen("nouv.txt","w");
    if (f!=NULL && f2!=NULL)
    {
         while(fscanf(f,"%s %d %d %d %d %d %d %d \n",p.id,&p.MUNICIPALITYPS,&p.opt.hours,&p.opt.mins,&p.ct.hours,&p.ct.mins,&p.Nrooms,&p.capacity)!=EOF)
           {
            if(strcmp(p.id,id)==0)
            {
                fprintf(f2,"%s %d %d %d %d %d %d %d \n",nouv.id,nouv.MUNICIPALITYPS,nouv.opt.hours,nouv.opt.mins,nouv.ct.hours,nouv.ct.mins,nouv.Nrooms,nouv.capacity);
                tr=1;
            }
            else
                fprintf(f2,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity);

        }

fclose(f);
fclose(f2);
remove(filename);
rename("new.txt",filename);
    }
else
printf("file opening probl\n");

    
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

int Delete(char * filename, char id[15])
{
    int tr=0;
    Pollingstation p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d %d %d %d \n",p.id,&p.MUNICIPALITYPS,&p.opt.hours,&p.opt.mins,&p.ct.hours,&p.ct.mins,&p.Nrooms,&p.capacity)!=EOF)
        {
            if(strcmp(p.id,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
Pollingstation search(char * filename, char id[15])
{
    Pollingstation p;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %d %d %d %d %d %d %d \n",p.id,&p.MUNICIPALITYPS,&p.opt.hours,&p.opt.mins,&p.ct.hours,&p.ct.mins,&p.Nrooms,&p.capacity)!=EOF)
        {
            if(strcmp(p.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        p.id[0]=-1;
    return p;

}

