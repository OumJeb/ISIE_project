#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functelections.h"

int main()
{
    election e4, e1={"1",11,11,2022,1,2,1,1},e2={"2",11,10,2022,1,2,1,0};
    printf("id?\n");
    scanf("%s",e4.elecid);
    printf("date?\n");
    scanf("%d %d %d",&e4.date.d,&e4.date.m,&e4.date.y);
    printf("municip?\n");
    scanf("%d",&e4.municip);
    printf("numhab?\n");
    scanf("%d",&e4.numhab);
    printf("numps?\n");
    scanf("%d",&e4.numps);
    printf("electype?\n");
    scanf("%d",&e4.electype);

    int x=add_election("elections.txt",e4);
    if(x==1)
        printf("\n add successful");
    else printf("\n error adding ");
    x=add_election("elections.txt",e1);
    if(x==1)
        printf("\n add successful");
    else printf("\n error adding ");
    x=modify_election("elections.txt","1",e2);
    if(x==1)
        printf("\n modification successful");
    else printf("\n error modifying");
    x=delete_election("elections.txt","2");
    if(x==1)
        printf("\n delete successful");
    else printf("\n error deleting");
    election e3;
    e3=search_election("elections.txt","1");
    if(e3.elecid[0]=='N')
        printf("\nnot found\n");
    else printf("\nfound\n");


    return 0;
}
