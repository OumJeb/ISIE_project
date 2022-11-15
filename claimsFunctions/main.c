#include <stdio.h>
#include <string.h>
#include"claimsfunctions.h"

int main()
{
    Claims u1= {"zqinb1425",{1,0,1},25,{2,3,2000},14,"fff"},u2= {"zqibit425",{0,0,1},25,{2,23,2000},14,"fhellof"},u3={"nimab15",{1,0,1},25,{2,3,2006},14,"kattouii"};
    int x=add_claims("filename.txt", u1);
    if(x==1)
        printf("\nclaim added successfully");
    else printf("\nadding error");

    x=modify_claims("filename.txt","zqinb1425",u2 );

    if(x==1)
        printf("\nsuccessfull modification");
    else printf("\nerror with Modification");
    x=delete_claims("filename.txt","zqinb1425");
    if(x==1)
        printf("\nsuccessfull delete");
    else printf("\nerror with deleting");
    u3=search_claims("filename.txt","zqinb1425");
    if(u3.id[0]==-1)
        printf("Not Found");
    return 0;
}

