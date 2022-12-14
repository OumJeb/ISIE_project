#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "claimsfunctions.h"
#include "functelections.h"

    int add_claims(char* filename,Claims cl){
    
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %d %s %d %d %d %s %s\n",cl.id,cl.type[0],cl.type[1],cl.type[2],cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modify_claims( char * filename, char id[20],Claims cnew)
{
    int v=0;
    Claims cl;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %d %d %d %s %s",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],cl.electoral_list,&cl.date.d,&cl.date.m,&cl.date.y,cl.municipality,cl.text)!=EOF)
        {
            if(strcmp(cl.id,id)==0)
            {
                fprintf(f2,"%s %d %d %d %s %d %d %d %s %s\n",cnew.id,cnew.type[0],cnew.type[1],cnew.type[2],cnew.electoral_list,cnew.date.d,cnew.date.m,cnew.date.y,cnew.municipality,cnew.text);
                v=1;
            }
            else
            {
                fprintf(f2,"%s %d %d %d %s %d %d %d %s %s\n",cl.id,cl.type[0],cl.type[1],cl.type[2],cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text);
            }

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt",filename);
    return v;

}

int delete_claims (char * filename, char id[20])
{
    int v=0;
    Claims cl;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("new.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %d %d %d %s %s",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],cl.electoral_list,&cl.date.d,&cl.date.m,&cl.date.y,cl.municipality,cl.text)!=EOF)
        {
            if (strcmp(cl.id,id)==0)
                v=1;
            else
                fprintf(f2,"%s %d %d %d %s %d %d %d %s %s\n",cl.id,cl.type[0],cl.type[1],cl.type[2],cl.electoral_list,cl.date.d,cl.date.m,cl.date.y,cl.municipality,cl.text);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;}

Claims search_claims(char * filename, char id[20])
{
    Claims cl;
    int v;
    FILE * f=fopen(filename,"r");
    if(f!=NULL)
    {
        while(v==0 &&(fscanf(f,"%s %d %d %d %s %d %d %d %s %s",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],cl.electoral_list,&cl.date.d,&cl.date.m,&cl.date.y,cl.municipality,cl.text)!=EOF) )
        {
              if(strcmp(cl.id,id)==0)
                    v=1;


        }
    }
    fclose(f);
    if(v==0)
        cl.id[0]='0';
    return cl;
}

int verifection(char * filename, char id[20])

{

    Claims cl;

    int v=0;

    FILE * f=fopen(filename,"r");

    if(f!=NULL)

    {

        while((fscanf(f,"%s %d %d %d %s %d %d %d %s %s",cl.id,&cl.type[0],&cl.type[1],&cl.type[2],cl.electoral_list,&cl.date.d,&cl.date.m,&cl.date.y,cl.municipality,cl.text)!=EOF)&& v==0)

        {

              if(strcmp(cl.id,id)==0)

                    v=1;
        }

    }

    fclose(f);
    return v;}

enum
{CLAIMID,
 DATE,
 MUNICIPALITY,
 ELLIST,
 CLAIMTYPE,
 COLUMNS
};

void display_claim(GtkWidget *list)
{
	GtkCellRenderer *renderer;
	
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

 		 		 
	 char id[50];
         int type[3];
         char electoral_list[20];
         date date ;
         char municipality[20];
         char text[200];
	 store=NULL;
         char msg[20];
         char datec[20];
	FILE *f;

	store=gtk_tree_view_get_model(&list);
        
	if(store==NULL)
	{	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Claim Id",renderer, "text",CLAIMID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Municipality",renderer, "text",MUNICIPALITY,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Electoral list",renderer, "text",ELLIST,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

	

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Claim type",renderer, "text",CLAIMTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("claimsfile.txt","r");
	
	if(f==NULL)
	{
		return;
	}
	else
	{	f=fopen("claimsfile.txt","a+");
			while(fscanf(f,"%s %d %d %d %s %d %d %d %s %s\n",id,&type[0],&type[1],&type[2],electoral_list,&date.d,&date.m,&date.y,municipality,text)!=EOF)
			{
        gtk_list_store_append(store,&iter);
        sprintf(datec,"%d/%d/%d",date.d,date.m,date.y);
        claim_type(type,msg);
        gtk_list_store_set(store,&iter,CLAIMID,id,DATE,date,MUNICIPALITY,municipality,ELLIST,electoral_list,CLAIMTYPE,msg,-1);
			}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
 
}}

void claim_type(int type[3],char msg[20])
{
 	
	
	if(type[0]==1 )
          	{strcpy(msg,"stuff");}
  

  	if(type[1]==1 )
   		{strcpy(msg,"system");}
  	if(type[2]==1 )
   		{strcpy(msg,"other ");}
   	
 }        


