#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"psfunctions.h"
int main()
{Pollingstation p1={{8,00},{17,00},"123",4,200};
Pollingstation p2={{9,00},{17,00},"104",3,180};
Pollingstation p3={{8,00},{14,00},"002",6,500};
Pollingstation p4={{6,02},{19,00},"012",7,400};

int x=add("Pollingstation.txt",p1);
int y=add("Pollingstation.txt",p2);
int z=add("Pollingstation.txt",p3);
if(x==1)
    printf("\n Pollingstation added succesfully");
else printf("\n error in adding the polling station");
x=modifyps("Pollingstation.txt","123",p4);
if (x==1)
 printf("\n Modification done succesfcully !");
else printf("\n Modification failed  !");
p3=search("Pollingstation.txt","104");
if (strcmp(p1.id,"123")!=0)
    printf("\n ID not found");
else
printf("ID found !");
Delete("Pollingstation.txt","002");
return 0;

}

