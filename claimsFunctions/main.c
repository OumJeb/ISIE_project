#include <stdio.h>
#include <string.h>
#include"claimsfunctions.h"

int main()
{
    Claims u1= {"zaineb",1,0,1,5151,{2,3,2000},"fff"},u2= {"zaineb",1,0,1,5151,{2,3,2000},"fff"},u3={"zaineb",1,0,1,5151,{2,3,2000},"fff"};
    int x=add_claims("new.txt", u1);
    if(x==1)
        printf("\claim added successfully");
    else printf("\nadding error");

    x=modify_claims("filename.txt",1,u2 );

    if(x==1)
        printf("\nsuccessfull modification");
    else printf("\nerror with Modification");
    x=delete_claims("filename.txt",1);
    if(x==1)
        printf("\nsuccessfull delete");
    else printf("\nerror with deleting");
    u3=search_claims("filename.txt",3 );
    if(u3.id[0]=-1)
        printf("Not Found");
    return 0;
}

