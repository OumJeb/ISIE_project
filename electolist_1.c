#include"electolist_1.h"
#include<stdio.h>
"include<string>
int add_electoral(char * filename ,electoral e )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %s %s %s %s %s %s %d %d %d \n",e.id_liste,e.municipality,e.orientation,e.id_HOL,e.id1,e.id2,e.id3,e.da.d,e.da.m,e.da.y);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modify_electoral(char * filename, char id1[100],electoral nw )
{
    electoral e;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("liselect.txt", "w");
    if(f==NULL || f2==NULL)
        return 0;
    else
    {
        while(fscanf(f,"%s %d %s %s %s %s %s %s %d %d %d \n",e.id_liste,&e.municipality,e.orientation,e.id_HOL,e.id1,e.id2,e.id3,&e.da.d,&e.da.m,&e.da.y)!=EOF)
        {
            if(e.id_liste==id1)
                fprintf(f2,"%s %d %s %s %s %s %s %s %d %d %d\n",e.id_liste,e.municipality e.orientation,e.id_HOL,e.id1,e.id2,e.id3,e.da.d,e.da.m,e.da.y);
            else

                fprintf(f2,"%s %d %s %s %s %s %s %d %d %d\n",new_e.id_liste,new-e.municipality ,new_e.orientation,new_e.id_HOL,new_e.id1,new_e.id2,new_e.id3,new_e.da.d,new_e.da.m,new_e.da.y);

        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("liselect.txt", liselect);
        return 1;
    }

}

int delete_electoral(char * filename ,char id_liste[100] ,electoral e)
{
    
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("liselect.txt", "w+");
    if(f==NULL || f2==NULL)
        return 0;
    else
    {
        while(fscanf(f,"%s %d %s %s %s %s %s %s %d %d %d\n",e.id_liste,&e.municipality ,e.orientation,e.id_HOL,e.id1,e.id2,e.id3,&e.da.d,&e.da.m,&e.da.y)!=EOF)

        {
            if(e.id_liste!=id_liste)
                fprintf(f2,"%s %d %s %s %s %s %s %s %d %d %d\n",e.id_liste,e.municipality ,e.orientation,e.id_HOL,e.id1,e.id2,e.id3,e.da.d,e.da.m,e.da.y);

        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("liselect.txt", liselect);
        return 1;
    }
}

electoral search_eletoral(int id_liste, char * liselect)
{
    electoral e;
    int tr=0;
    FILE * f=fopen(liselect, "r");
    if(f!=NULL )
    {
        while(fscanf(f,"%s %d %s %s %s %s %s %s %d %d %d\n",e.id_liste,e.municipality,e.orientation,e.id_HOL,e.id1,e.id2,e.id3,e.da.d,e.da.m,e.da.y)!=EOF && tr==0)
        {
            if(e.id_liste==e.id_liste)
                tr=1;
        }
    }
    if(tr==0)
        e.id_liste=-1;
    return e;

}
