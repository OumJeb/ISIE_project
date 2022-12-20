#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<gtk/gtk.h>


typedef struct {
char id_list[20];
char municipality[20];
char orientation[20];
char id_HOL[20];
char id1[20];
char id2[20];
char id3[20];
date da;
int nbvotes;
}electoral;
typedef struct user
{
    char name[20];
    char id[20];
    date date;
    int gen;
    int mun;
    char pw[20];
    int atype;
    char vote[20];
} user;
int nbv(char * fileelectorallist,char id_list[],char*fileusers);
void display_ordered(GtkWidget *list);
int L_order(char*fileelectorallist,electoral t[]);
int add_electoral(char * filename ,electoral e );
int adduser(char * filename, user u);
void display_nbvotes(GtkWidget *list);




int nbv(char * fileelectorallist,char id_list[],char*fileusers)
{
    FILE *f=fopen(fileelectorallist,"r");
    FILE *f2=fopen(fileusers,"r");
    
    electoral t[100];
    electoral E,L;
    user u;
    int i=0;

    
    while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d",E.id_list,E.municipality,E.orientation,E.id_HOL,E.id1,E.id2,E.id3,&E.da.d,&E.da.m,&E.da.y,&E.nbvotes)!= EOF)
    {
        if (strcmp(id_list,E.id_list)==0)
           L=E;
    }
    
    while(fscanf(f2,"%s %s %d %d %d %d %d %s %d %s\n",u.name,u.id,&u.date.d,&u.date.m,&u.date.y,&u.gen,&u.mun,u.pw,&u.atype,u.vote)!=EOF)
    {   
	
        if(strcmp(id_list,u.vote)==0)
        { 
            L.nbvotes++;
        }
    }
    fclose(f2);
    FILE *f3=fopen("new.txt","w");
    if (f!=NULL && f3!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d",E.id_list,E.municipality,E.orientation,E.id_HOL,E.id1,E.id2,E.id3,&E.da.d,&E.da.m,&E.da.y,&E.nbvotes)!=EOF)
        {
                if(strcmp(E.id_list,id_list)==0)
                {
                    fprintf(f3,"%s %s %s %s %s %s %s %d %d %d %d",L.id_list,L.municipality,L.orientation,L.id_HOL,L.id1,L.id2,L.id3,L.da.d,L.da.m,L.da.y,L.nbvotes);
                    
                }
                else
                {
                    fprintf(f3,"%s %s %s %s %s %s %s %d %d %d %d",E.id_list,E.municipality,E.orientation,E.id_HOL,E.id1,E.id2,E.id3,E.da.d,E.da.m,E.da.y,E.nbvotes);
                }



        }
    }
    fclose(f);
    fclose(f3);
    remove(fileelectorallist);
    rename("new.txt",fileelectorallist);
    
  
  return L.nbvotes ;

}


int L_order(char*fileelectorallist,electoral t[])
{
    FILE *f=fopen(fileelectorallist,"r");
    electoral E,buffer;int x,i=0,j,k,max;
    FILE *f2=fopen("orderedelectorallists.txt","w");
    while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d",t[i].id_list,t[i].municipality,t[i].orientation,t[i].id_HOL,t[i].id1,t[i].id2,t[i].id3,&t[i].da.d,&t[i].da.m,&t[i].da.y,&t[i].nbvotes)!= EOF )
    {
        
        i++;
    }
    for (j=0;j<i;j++)
    {   max=j;
        for(k=j+1;k<=i;k++)
        {
            if(t[k].nbvotes>t[max].nbvotes)
                max=k;
        }
        buffer=t[j];
        t[j]=t[max];
        t[max]=buffer;
    }
    for(x=0;x<=i;x++)
    {
        fprintf(f2,"%s %s %s %s %s %s %s %d %d %d %d",t[x].id_list,t[x].municipality,t[x].orientation,t[x].id_HOL,t[x].id1,t[x].id2,t[x].id3,t[x].da.d,t[x].da.m,t[x].da.y,t[x].nbvotes);
    }
    fclose(f);
    fclose(f2);
    return i; 
}




        


int adduser(char * filename, user u)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %d %s %d %s\n",u.name,u.id,u.date.d,u.date.m,u.date.y,u.gen,u.mun,u.pw,u.atype,u.vote);
        fclose(f);
        return 1;
    }
    else return 0;
}
int add_electoral(char * filename ,electoral e )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %d %d %d %d \n",e.id_list,e.municipality,e.orientation,e.id_HOL,e.id1,e.id2,e.id3,e.da.d,e.da.m,e.da.y,e.nbvotes);
        fclose(f);
        return 1;
    }
    else return 0;
}

enum{
IDLIST,
MUN,
ORIENTATION,
IDHOL,
ID1,
ID2,
ID3,
DATE,
NBVOTES,
COLUMNS1
};
void display_ordered(GtkWidget *list)
{
	GtkCellRenderer *renderer;
	
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

 		 		 
	char id_list[20];
	char municipality[20];
	char orientation[20];
	char id_HOL[20];
	char id1[20];
	char id2[20];
	char id3[20];
	date da;
	int nbvotes;
        char elecdate[20];
	char nb[20];
	store=NULL;
      
	FILE *f;

	store=gtk_tree_view_get_model(&list);
        
	if(store==NULL)
	{	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Id electoral list",renderer, "text",IDLIST,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Municipality",renderer, "text",MUN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Orientation",renderer, "text",ORIENTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("idHOL",renderer, "text",IDHOL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("id1",renderer, "text",ID1,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("id2",renderer, "text",ID2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("id3",renderer, "text",ID3,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("date",renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("nb votes",renderer, "text",NBVOTES,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	

		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("orderedlectorallists.txt","r");
	
	if(f==NULL)
	{
		return;
	}
	else
	{	f=fopen("orderedlectorallists.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d",id_list,municipality,orientation,id_HOL,id1,id2,id3,da.d,da.m,da.y,&nbvotes)!= EOF)
			{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",da.d,da.m,da.y);
sprintf(nb,"%d",nbvotes);
gtk_list_store_set(store,&iter,IDLIST,id_list,MUN,municipality,ORIENTATION,orientation,IDHOL,id_HOL,ID1,id1,ID2,id2,ID3,id3,DATE,elecdate,NBVOTES,nb,-1);
			}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}
}

enum{
ID_LIST,
NB_VOTES,
COLUMNS2
};

void display_nbvotes(GtkWidget *list)
{
	GtkCellRenderer *renderer;
	
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

 		 		 
	char id_list[20];
	char municipality[20];
	char orientation[20];
	char id_HOL[20];
	char id1[20];
	char id2[20];
	char id3[20];
	date da;
	int nbvotes;
        char elecdate[20];
	char nb[20];
	store=NULL;
      
	FILE *f;

	store=gtk_tree_view_get_model(&list);
        
	if(store==NULL)
	{	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Id electoral list",renderer, "text",ID_LIST,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("nb votes",renderer, "text",NB_VOTES,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	

		store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("orderedlectorallists.txt","r");
	
	if(f==NULL)
	{
		return;
	}
	else
	{	f=fopen("orderedlectorallists.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d",id_list,municipality,orientation,id_HOL,id1,id2,id3,da.d,da.m,da.y,&nbvotes)!= EOF)
			{
gtk_list_store_append(store,&iter);

sprintf(nb,"%d",nbvotes);
gtk_list_store_set(store,&iter,ID_LIST,id_list,NB_VOTES,nb,-1);
			}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}
}































/*int main()
{

  user u1= {"zaineb","0648126",1,2,2000,2,1,"zvfs",1,"1"};
  user u2= {"zhgyeb","0648126", 1,2,2000,2,1,"zvfs",1,"2"};
  user u3={"ojhgheb","0648126", 1,2,2000,2,1,"zvfs",1,"0"};
  electoral e1={"1",2,"1","2","4","3","5",1,2,2022,0};
  electoral e2={"2",2,"1","6","7","8","9",1,2,2022,0};
  
  int x=adduser("user.txt",u1);
  x=adduser("user.txt",u2);
  x=adduser("user.txt",u3);
  
  x=add_electoral("electo.txt",e1);
  x=add_electoral("electo.txt",e2);
  int nb=nbv("electo.txt","2","user.txt");
  printf("%d\n",nb);
  electoral t[100];
  int i;
  int j=L_order("electo.txt",t);
  printf("%d\n",j);

  


}*/


