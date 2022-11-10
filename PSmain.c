#include <stdio.h>
#include"functions.h"
int main()
{Pollingstation p1={{8,00},{17,00},"123",4,200};
Pollingstation p2={{9,00},{17,00},"104",3,180};
Pollingstation p3={{8,00},{14,00},"002",6,800};;

int x=add("pollingstation.txt",p1);
if(x==1)
    printf("\n Pollingstation added succesfully");
else printf("\n error in adding the polling station");
x=modify("Pollingstation.txt","1",p1);
if (x==1)
 printf("\n Modification done succesfcully !");
else printf("\ Delete failed !");
p3=search("pollingstation.txt","123");
if (p3.id==-1)
    printf("not found");
return 0;

}

