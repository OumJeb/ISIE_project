
#include <stdio.h>

#include <stdlib.h>

#include <string.h>
#include "claimsfunctions.h"


#include "users.h"



float average( char* usersfile)
{    int s=0, k=0;
 user u;
     float av;
    FILE * f=fopen(usersfile, "r");

    if (f!=NULL )
    {
        while(fscanf(f,"%s %s %d %d %d %s %d %s %d %s\n",u.name,u.id,&u.date.day,&u.date.month,&u.date.year,u.pw,&u.gen,u.mun,u.atype,u.vote	)!=EOF)
        {
            if(strcmp(u.vote,"NA")!=0)
          {
              s=s+ (2022-u.date.year);
           k++;

          }

        }
        av = (float) s/k;
    }
    fclose(f);
   return av;


}

int nbrclaims( char * claimsfile, char *  electorallist)
{
FILE * f=fopen(claimsfile, "r");
Claims cl;
int k=0;
    if (f!=NULL )	
    {
        while(fscanf(f,"%s %d %d %d %s %d %d %d %d %s\n",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],cl.electoral_list,&cl.date.day,&cl.date.month,&cl.date.year,&cl.municipality,cl.text)!=EOF)
        {
          if (!strcmp(electorallist,cl.electoral_list))
          {
            k++;
          }
        }

    }
    fclose(f);

return k;

}
