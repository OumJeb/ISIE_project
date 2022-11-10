#include "functelections.h"
#include <string.h>
int add_election( char * filename, election e)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d/%d/%d %d %d %d %d %d\n",e.elecid,e.date.d,e.date.m,e.date.y,e.municip,e.numhab,e.numps,e.municipal,e.legislative);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modify_election( char * filename, char id[20], election enew)
{
    int v=0;int i;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d/%d/%d %d %d %d %d %d\n",e.elecid,&e.date.d,&e.date.m,&e.date.y,&e.municip,&e.numhab,&e.numps,&e.municipal,&e.legislative)!=EOF)
        {
                if(strcmp(e.elecid,id)==0)
                {
                    fprintf(f2,"%s %d/%d/%d %d %d %d %d %d\n",enew.elecid,enew.date.d,enew.date.m,enew.date.y,enew.municip,enew.numhab,enew.numps,enew.municipal,enew.legislative);
                    v=1;
                }
                else
                {
                    fprintf(f2,"%s %d/%d/%d %d %d %d %d %d\n",e.elecid,e.date.d,e.date.m,e.date.y,e.municip,e.numhab,e.numps,e.municipal,e.legislative);
                }



        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt",filename);
    return v;

}
int delete_election (char * filename, char id[20])
{
    int v=0;int i;
    election e;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("new.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d/%d/%d %d %d %d %d %d\n",e.elecid,&e.date.d,&e.date.m,&e.date.y,&e.municip,&e.numhab,&e.numps,&e.municipal,&e.legislative)!=EOF)
        {


                if(strcmp(e.elecid,id)==0)
                {
                    v=1;
                }
                else
                {
                    fprintf(f2,"%s %d/%d/%d %d %d %d %d %d\n",e.elecid,e.date.d,e.date.m,e.date.y,e.municip,e.numhab,e.numps,e.municipal,e.legislative);
                }


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;
}
election search_election(char * filename, char id[20])
{
    election e;
    int v;int i;
    FILE * f=fopen(filename,"r");
    if(f!=NULL)
    {
        while((fscanf(f,"%s %d/%d/%d %d %d %d %d %d\n",e.elecid,&e.date.d,&e.date.m,&e.date.y,&e.municip,&e.numhab,&e.numps,&e.municipal,&e.legislative)!=EOF)&& v==0)
        {
              if(strcmp(e.elecid,id)==0)
                    v=1;


        }
    }
    fclose(f);
    if(v==0)
        e.elecid[0]='N';
    return e;
}
