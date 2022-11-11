#include <stdio.h>
#include <string.h>
#include"functions.h"

int main()
{
    user u1= {},u2= {},u3;
    int x=add("new.txt", u1);
    if(x==1)
        printf("\nuser added successfully");
    else printf("\nadding error");

    x=modify("user.txt",1,u2 );

    if(x==1)
        printf("\nsuccessfull modification");
    else printf("\nerror with Modification");
    x=deleteu("user.txt",1);
    if(x==1)
        printf("\nsuccessfull delete");
    else printf("\nerror with deleting");
    u3=find_user("user.txt",3 );
    if(u3.id[0]=-1)
        printf("Not Found");
    return 0;
}
