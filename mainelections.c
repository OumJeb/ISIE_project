#include <stdio.h>
#include <stdlib.h>
#include "functelections.h"

int main()
{
    election e1={"1",11,11,2022,1,2,1,1,0},e2={"2",11,10,2022,1,2,1,0,1};
    int x=add_election("elections.txt",e1);
    if(x==1)
        printf("\n add successful");
    else printf("\n error adding ");
    x=modify_election("elections.txt","1",e2);
    if(x==1)
        printf("\n modification successful");
    else printf("\n error modifying");
    x=delete_election("elections.txt","1");
    if(x==1)
        printf("\n delete successful");
    else printf("\n error deleting");
    election e3;
    e3=search_election("elections.txt","3");
    if(e3.elecid[0]=='N')
        printf("\n not found");


    return 0;
}
