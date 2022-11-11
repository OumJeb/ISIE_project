#include "electolist_1.h"
#include<stdio.h>


int main()
{
    int a,b,c;
    int n;
    char new_id[100],id[100];

    electoral E;
    printf("name of the list?\n");
    scanf("%c",E.id_liste);
    printf("id head of the list");
    scanf("%c",E.id_HOL);
    printf("id of the head of the list");
    scanf("%c",E.id1);
    printf("number of members");
    scanf("%d",&n);
    a=addlist("electoral.txt",E);
    b=modifylist("electoral.txt",id,new_id);
    c=deletelist("electoral.txt",id);
    printf("%d",a);
    printf("%d",b);
    printf("%d",c);
    return 0;
}
}


