#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
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
int modify (char * filename ,int id , Pollingstation nouv)
{


    int tr=0;
    Pollingstation p;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("nouv.txt","w");
    if (f!=NULL && f2!=NULL)
    {
         while(fscanf(f,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity)!=EOF)
           {
            if(p.id== id)
            {
                fprintf(f2,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity);
                tr=1;
            }
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
int Delete(char * filename, int id)
{
    int tr=0;
    Pollingstation p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity)!=EOF)
        {
            if(p.id== id)
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
Pollingstation search(char * filename, int id)
{
    Pollingstation p;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %d %d %d %d %d %d %d \n",p.id,p.MUNICIPALITYPS,p.opt.hours,p.opt.mins,p.ct.hours,p.ct.mins,p.Nrooms,p.capacity)!=EOF)
        {
            if(p.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        p.id[0]="-1";
    return p;

}
