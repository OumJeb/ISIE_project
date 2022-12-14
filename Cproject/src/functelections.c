#include "functelections.h"
#include <string.h>
#include <gtk/gtk.h>
int add_election( char * filename, election e)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %d %s %s %s %d\n",e.elecid,e.date.d,e.date.m,e.date.y,e.municip,e.numhab,e.numps,e.electype);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modify_election( char * filename, char id[20], election enew)
{
    int v=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s %d",e.elecid,&e.date.d,&e.date.m,&e.date.y,e.municip,e.numhab,e.numps,&e.electype)!=EOF)
        {
                if(strcmp(e.elecid,id)==0)
                {
                    fprintf(f2,"%s %d %d %d %s %s %s %d\n",enew.elecid,enew.date.d,enew.date.m,enew.date.y,enew.municip,enew.numhab,enew.numps,enew.electype);
                    v=1;
                }
                else
                {
                    fprintf(f2,"%s %d %d %d %s %s %s %d\n",e.elecid,e.date.d,e.date.m,e.date.y,e.municip,e.numhab,e.numps,e.electype);
                }



        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt",filename);
    return v;

}
int delete_election (char * filename, char id[20])
{
    int v=0;
    election e;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("new.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s %d",e.elecid,&e.date.d,&e.date.m,&e.date.y,e.municip,e.numhab,e.numps,&e.electype)!=EOF)
        {


                if(strcmp(e.elecid,id)==0)
                {
                    v=1;
                }
                else
                {
                    fprintf(f2,"%s %d %d %d %s %s %s %d\n",e.elecid,e.date.d,e.date.m,e.date.y,e.municip,e.numhab,e.numps,e.electype);
                }


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return v;
}
election search_election(char * filename, char id[20])
{
    election e;
    int v=0;
    FILE * f=fopen(filename,"r");
    if(f!=NULL)
    {
        while(v==0 && (fscanf(f,"%s %d %d %d %s %s %s %d",e.elecid,&e.date.d,&e.date.m,&e.date.y,e.municip,e.numhab,e.numps,&e.electype)!=EOF))
        {
              if(strcmp(e.elecid,id)==0)
                    v=1;


        }
    }
    fclose(f);
    if(v==0)
        e.elecid[0]='N';
    return e;
}

void election_type(int electype,char msg[])
{
if(electype == 1)
	strcpy(msg,"municipal");
else
	strcpy(msg,"legislative");
}

int verify_id(char * filename,char id[20])
{
  election e;
  int v=0;
  FILE * f=fopen(filename,"r");
   if(f!=NULL)
    {
        while(v==0 && (fscanf(f,"%s %d %d %d %s %s %s %d",e.elecid,&e.date.d,&e.date.m,&e.date.y,e.municip,e.numhab,e.numps,&e.electype)!=EOF))
        {
              if(strcmp(e.elecid,id)==0)
                    v=1;
	}
    }
   
   return v;
}

date stringtodate(char elecdate[20])
{
   int i=0;int j=0;char d[2];char m[2];char y[4];date date;
    for(i=0;i<2;i++){if (elecdate[i]!='/'){d[j]=elecdate[i];j++;}}
      date.d=atoi(d);


     j=0;
     for(i=2;i<5;i++){if (elecdate[i]!='/'){m[j]=elecdate[i];j++;}}
      m[j]='n';
      date.m=atoi(m);


      j=0;
     for(i=5;i<10;i++){if (elecdate[i]!='/'){y[j]=elecdate[i];j++;}}
      y[j]='n';
      date.y=atoi(y);
	return date;



}
int reverse_election_type( char msg[20])
{
	if(strcmp(msg,"municipal")==0)
	return 1;
else
	return 2;
}
enum
{
	ELECID,
	DATE,
	MUNICIPALITY,
	NUMHAB,
	NUMPS,
	ELECTYPE,
	COLUMNS
};

void display_election(GtkWidget *list)
{
	GtkCellRenderer *renderer;
	
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

 		 		 
	char elecid[20];
	date date;
	char elecdate[20];
	char municip[20];
	char numhab[50];
	char numps[50];
	int electype;
	char msg[20];
	store=NULL;
      
	FILE *f;

	store=gtk_tree_view_get_model(&list);
        
	if(store==NULL)
	{	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Election Id",renderer, "text",ELECID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Municipality",renderer, "text",MUNICIPALITY,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Number of habitants",renderer, "text",NUMHAB,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("number of PS",renderer, "text",NUMPS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Election Type",renderer, "text",ELECTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("election.txt","r");
	
	if(f==NULL)
	{
		return;
	}
	else
	{	f=fopen("election.txt","a+");
			while(fscanf(f,"%s %d %d %d %s %s %s %d",elecid,&date.d,&date.m,&date.y,municip,numhab,numps,&electype)!=EOF)
			{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",date.d,date.m,date.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
			}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}
}


void empty(GtkWidget *list)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char elecid[20];
	date date;
	char elecdate[20];
	char municip[20];
	char numhab[50];
	char numps[50];
	int electype;
	char msg[20];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(&list);
	if(store==NULL)
	{	renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Election Id",renderer, "text",ELECID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Municipality",renderer, "text",MUNICIPALITY,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Number of habitants",renderer, "text",NUMHAB,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("number of PS",renderer, "text",NUMPS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Election Type",renderer, "text",ELECTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}
		
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
}


void search_display(GtkWidget *list,char id[20],date da,char mun[20])
{
	GtkCellRenderer *renderer;
	
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;
        
 		 		 
	char elecid[20];
	date daelec;
	
	char elecdate[20];
	char municip[20];
	char numhab[50];
	char numps[50];
	int electype;
	char msg[20];
	store=NULL;
        
	FILE *f;

	store=gtk_tree_view_get_model(&list);
        
	if(store==NULL)
	{	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Election Id",renderer, "text",ELECID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Municipality",renderer, "text",MUNICIPALITY,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Number of habitants",renderer, "text",NUMHAB,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("number of PS",renderer, "text",NUMPS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Election Type",renderer, "text",ELECTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}
		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("election.txt","r");
if(f==NULL)
{
	return;
}
else
{
	f=fopen("election.txt","a+");
	while(fscanf(f,"%s %d %d %d %s %s %s %d",elecid,&daelec.d,&daelec.m,&daelec.y,municip,numhab,numps,&electype)!=EOF)
	{  
	
        if(strlen(id)!=0 && strcmp(elecid,id)==0 && da.d!=0 && da.m!=0 && da.y!=0 && da.d==daelec.d && da.m==daelec.m && da.y==daelec.y && strlen(mun)!=0 && strcmp(municip,mun)==0)
	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}

        if(da.d!=0 && da.m!=0 && da.y!=0 && da.d==daelec.d && da.m==daelec.m && da.y==daelec.y && strlen(mun)!=0 && strcmp(municip,mun)==0 && strlen(id)==0)
 	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}
	if(strlen(id)!=0 && strcmp(elecid,id)==0 && da.d!=0 && da.m!=0 && da.y!=0 && da.d==daelec.d && da.m==daelec.m && da.y==daelec.y && strlen(mun)==0)
	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}

        if(strlen(id)!=0 && strcmp(elecid,id)==0 && strlen(mun)!=0 && strcmp(municip,mun)==0 && da.d==0 && da.m==0 && da.y==0 )
	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}
	if(strlen(mun)!=0 && strcmp(municip,mun)==0 && da.d==0 && da.m==0 && da.y==0 && strlen(id)==0)
	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}
	if(da.d!=0 && da.m!=0 && da.y!=0 && da.d==daelec.d && da.m==daelec.m && da.y==daelec.y && strlen(id)==0 && strlen(mun)==0)
	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}
	if(strlen(id)!=0 && strcmp(elecid,id)==0 && da.d==0 && da.m==0 && da.y==0 && strlen(mun)==0)
	{
gtk_list_store_append(store,&iter);
sprintf(elecdate,"%d/%d/%d",daelec.d,daelec.m,daelec.y);
election_type(electype,msg);
gtk_list_store_set(store,&iter,ELECID,elecid,DATE,elecdate,MUNICIPALITY,municip,NUMHAB,numhab,NUMPS,numps,ELECTYPE,msg,-1);
	}


	
}
        







	
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

