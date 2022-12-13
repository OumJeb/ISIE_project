#include <stdio.h>
#include <string.h>
#include"functions.h"

int main()
{
    user u1= {"zaineb","0648126",1,2,2000,2,1,"zvfs",1};
    user u2= {"zhgyeb","0648126", 1,2,2000,2,1,"zvfs",1};
    user u3={"ojhgheb","0648126", 1,2,2000,2,1,"zvfs",1};
    int x=add("user.txt", u1);
    if(x==1)
        printf("\n user added successfully");
    else printf("\n adding error");


    x=modify("user.txt","zaineb",u2 );
    if(x==1)
        printf("\n successfull modification");
    else printf("\n error with Modification \n");

    x=deleteu("user.txt","ojhgheb");
    if(x==1)
        printf("\n successfull delete");
    else printf("\n error with deleting \n");

    u3=find_user("user.txt","ojhgheb");
    if(u3.id[0]==-1)
        printf("Not Found");
    return 0;
}
