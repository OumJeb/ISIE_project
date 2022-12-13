#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "functelections.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int electype=1;

void
on_button_elecadd_clicked              (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *ID;
GtkWidget *DAY;
GtkWidget *MONTH;
GtkWidget *YEAR;
GtkWidget *MUN;
GtkWidget *NUMHAB;
GtkWidget *NUMPS;
GtkWidget *ERR;


ID=lookup_widget(button,"entry_elecid");
DAY=lookup_widget(button,"spinbutton_DAY");
MONTH=lookup_widget(button,"spinbutton_MONTH");
YEAR=lookup_widget(button,"spinbutton_YEAR");
MUN=lookup_widget(button,"combobox_munelec");
NUMHAB=lookup_widget(button,"combobox_numhabelec");
NUMPS=lookup_widget(button,"combobox_numpselec");
ERR=lookup_widget(button,"errlabel_elec");

election E;
char msg[20]="";
int n,v;
strcpy(E.elecid,gtk_entry_get_text(GTK_ENTRY(ID)));

E.date.d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DAY));	
E.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MONTH));
E.date.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YEAR));


strcpy(E.municip,gtk_combo_box_get_active_text(GTK_COMBO_BOX(MUN)));

strcpy(E.numhab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(NUMHAB)));

strcpy(E.numps,gtk_combo_box_get_active_text(GTK_COMBO_BOX(NUMPS)));
	
/*if(electype == 1)
	strcpy(msg,"municipal");
else
	strcpy(msg,"legistive");
E.electype= atoi(msg);
*/
E.electype=electype;


v=verify_id("election.txt",E.elecid);
 
if(v==1)
   {
     gtk_label_set_text(GTK_LABEL(ERR),"id already exists");
   }
else
   {
     n=add_election( "election.txt", E);
     if(n==1)
     {  gtk_label_set_text(GTK_LABEL(ERR),"election added successfully");}
     else
     {  gtk_label_set_text(GTK_LABEL(ERR),"error adding election");}
   }


}


void
on_radiobutton_electype1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		electype=1;
}


void
on_radiobutton_electype2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		electype=2;
}




void
on_button_stats_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_ADMIN;
  GtkWidget *window_statsoum;
  window_ADMIN = lookup_widget(button, "window_ADMIN");
  gtk_widget_hide (window_ADMIN);
  window_statsoum = create_window_statsoum ();
  gtk_widget_show (window_statsoum);
}


int confirm=0;
int electypemodif=1;
void
on_button_modify_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *ID,*DAY,*MONTH,*YEAR,*MUN,*NUMHAB,*NUMPS,*ERR,*CHECK;
   ID=lookup_widget(button,"entry_modifelecid");
   DAY=lookup_widget(button,"spinbutton_modif_d");
   MONTH=lookup_widget(button,"spinbutton_modif_m");
   YEAR=lookup_widget(button,"spinbutton_modif_y");
   MUN=lookup_widget(button,"combobox_modifmunic");
   NUMHAB=lookup_widget(button,"combobox_modifnumhab");
   NUMPS=lookup_widget(button,"combobox_modifnumps");
   ERR=lookup_widget(button,"errlabel_modifyelection");
   //CHECK=lookup_widget(button,"checkbutton_confirm");
   election E;
   int v,n;
   strcpy(E.elecid,gtk_entry_get_text(GTK_ENTRY(ID)));
   v=verify_id("election.txt",E.elecid);
   if(confirm==1 && v==1)
   {E.date.d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DAY));	
    E.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MONTH));
    E.date.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YEAR));


    strcpy(E.municip,gtk_combo_box_get_active_text(GTK_COMBO_BOX(MUN)));

    strcpy(E.numhab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(NUMHAB)));

    strcpy(E.numps,gtk_combo_box_get_active_text(GTK_COMBO_BOX(NUMPS)));
    E.electype=electypemodif;
    n=modify_election("election.txt",E.elecid,E);
       if(n==1)
           {gtk_label_set_text(GTK_LABEL(ERR),"election modified successfully!");confirm=0;}
       else{gtk_label_set_text(GTK_LABEL(ERR),"error modifying election!");}
    }
    else
    {gtk_label_set_text(GTK_LABEL(ERR),"try again");}
}


void
on_button_comfirm_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *ID,*DAY,*MONTH,*YEAR,*MUN,*NUMHAB,*NUMPS,*ERR,*RADIO1,*RADIO2;
   ID=lookup_widget(button,"entry_modifelecid");
   DAY=lookup_widget(button,"spinbutton_modif_d");
   MONTH=lookup_widget(button,"spinbutton_modif_m");
   YEAR=lookup_widget(button,"spinbutton_modif_y");
   MUN=lookup_widget(button,"combobox_modifmunic");
   NUMHAB=lookup_widget(button,"combobox_modifnumhab");
   NUMPS=lookup_widget(button,"combobox_modifnumps");
   ERR=lookup_widget(button,"errlabel_confirmmodif");
   RADIO1=lookup_widget(button,"radiobutton_modiftype1");
   RADIO2=lookup_widget(button,"radiobutton_modiftype2");
   election E;
   int v;
   strcpy(E.elecid,gtk_entry_get_text(GTK_ENTRY(ID)));
   v=verify_id("election.txt",E.elecid);
   char M[6][20]={"Ben_Arous","Tunis","Ariana","Manouba","Nabeul","Beja"};
   char H[7][20]={"0==>5000","5001==>10000","10001==>25000","25001==>50000","50001==>100000","100001==>500000","More than 500000"};
   char PS[3][20]={"a","b","c"};
   int m=0;int h=0;int ps=0;
   if (v==1)
   {  gtk_label_set_text(GTK_LABEL(ERR),"id found");
      E=search_election("election.txt", E.elecid);
      gtk_spin_button_set_value(DAY,E.date.d);
      gtk_spin_button_set_value(MONTH,E.date.m);
      gtk_spin_button_set_value(YEAR,E.date.y);
      while(m<6 && strcmp(M[m],E.municip)!=0)
      {m++;}
      gtk_combo_box_set_active(GTK_COMBO_BOX(MUN),m);
      while(h<7 && strcmp(H[h],E.numhab)!=0)
      {h++;}
      gtk_combo_box_set_active(GTK_COMBO_BOX(NUMHAB),h);
      while(ps<3 && strcmp(PS[ps],E.numps)!=0)
      {ps++;}
      gtk_combo_box_set_active(GTK_COMBO_BOX(NUMPS),ps);
      if(E.electype==1)
      {gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RADIO1),TRUE);}
      else {gtk_toggle_button_set_active(GTK_RADIO_BUTTON(RADIO2),TRUE);}
   }
   else
   {  gtk_label_set_text(GTK_LABEL(ERR),"id not found!");}
      
   

}


void
on_radiobutton_modiftype1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		electypemodif=1;
}


void
on_radiobutton_modiftype2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
         if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		electypemodif=2;
}

void
on_checkbutton_confirm_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if(gtk_toggle_button_get_active(togglebutton))
       {confirm=1;}
}


void
on_button_displaydelete_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *treeview;
   treeview=lookup_widget(button,"treeview_displayelecdelete");
   display_election(treeview);
}




char id[20]="";
void
on_treeview_displayelecdelete_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	char *elecid;
	char *elecdate;
        char *municip;
	char *numhab;
	char *numps;
	char *msg;
	election E;	
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&elecid);//,DATE,&elecdate,MUNICIPALITY,&municip,NUMHAB,&numhab,NUMPS,&numps,ELECTYPE,&msg,-1);
          strcpy(E.elecid,elecid);
          /*E.date=stringtodate(elecdate);
	  strcpy(E.municip,municip);
	  strcpy(E.numhab,numhab);
          strcpy(E.numps,numps);	
          E.electype=reverse_election_type(msg);*/
	  strcpy(id,E.elecid);
	  int n;
   	  n=delete_election ("election.txt", E.elecid);
	  display_election(treeview);	
	}
}



confirmdelete=0;
void
on_button_deleteelec_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *treeview;
   treeview=lookup_widget(button,"treeview_displayelecdelete");
   empty(treeview);
   display_election(treeview);
}


void
on_checkbutton_confirmelecdelete_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
       {confirmdelete=1;}
}

