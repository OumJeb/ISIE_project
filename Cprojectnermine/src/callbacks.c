#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "functelections.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "claimsfunctions.h"


//////////////////////////////////////OUMAYMA/////////////////////////////////////////////////
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
/*	
if(electype == 1)
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



int confirmdelete=0;
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
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&elecid,-1);//,DATE,&elecdate,MUNICIPALITY,&municip,NUMHAB,&numhab,NUMPS,&numps,ELECTYPE,&msg,-1);
          strcpy(E.elecid,elecid);
          /*E.date=stringtodate(elecdate);
	  strcpy(E.municip,municip);
	  strcpy(E.numhab,numhab);
          strcpy(E.numps,numps);	
          E.electype=reverse_election_type(msg);*/
	  strcpy(id,E.elecid);
	  int n;
	if(confirmdelete==1)
   	  {n=delete_election ("election.txt", E.elecid);
	  //display_election(treeview);
          }	
	}
}




void
on_button_deleteelec_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *treeview;
   treeview=lookup_widget(button,"treeview_displayelecdelete");
   
   if(confirmdelete==1)
   {empty(treeview);
    display_election(treeview);
    confirmdelete=0;}
}







void
on_checkbutton_conelecdelete_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
       {confirmdelete=1;}
}


void
on_button_SIGNIN_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *CIN,*PW;
  CIN=lookup_widget(button,"entry_CINSIGNIN");
  PW=lookup_widget(button,"entry_PWSIGNIN");
  account a;
  int v;
  strcpy(a.CIN,gtk_entry_get_text(GTK_ENTRY(CIN)));
  strcpy(a.PW,gtk_entry_get_text(GTK_ENTRY(PW)));
  v=search_account("admin.txt",a.CIN);
  if (v==1)
  {GtkWidget *window_authentification;
  GtkWidget *window_signinadmin;
  window_authentification = lookup_widget(button, "window_authentification");
  gtk_widget_hide (window_authentification);
  window_signinadmin = create_window_signinadmin();
  gtk_widget_show (window_signinadmin);
  }
 else
 {GtkWidget *window_authentification;
  GtkWidget *window_signinactor;
  window_authentification = lookup_widget(button, "window_authentification");
  gtk_widget_hide (window_authentification);
  window_signinactor = create_window_signinactor();
  gtk_widget_show (window_signinactor);

 }
  
}


void
on_button_backelec_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *window_ADMIN;
  GtkWidget *window_statsoum;
  GtkWidget *notebook_elections;
  window_statsoum = lookup_widget(button, "window_statsoum");
  gtk_widget_hide (window_statsoum);
  window_ADMIN = create_window_ADMIN();
  gtk_widget_show (window_ADMIN);
}

int criteria[3]={0,0,0};
void
on_button_searchelec_clicked           (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *ID,*DAY,*MONTH,*YEAR,*MUN;
	GtkWidget *treeview;
	treeview=lookup_widget(button,"treeview_displayelec");
        ID=lookup_widget(button,"entry_displayelecid");
        DAY=lookup_widget(button,"spinbutton_searchday");
   	MONTH=lookup_widget(button,"spinbutton_searchmonth");
   	YEAR=lookup_widget(button,"spinbutton_searchyear");
        MUN=lookup_widget(button,"combobox_displaymun");
	char id[20]="";date da;char mun[20]="";da.d=0;da.m=0;da.y=0;

	if(criteria[0]==1 )
	{strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));criteria[0]=0;}

	if(criteria[1]==1 )
      	{da.d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DAY));
      	 da.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MONTH));
      	 da.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(YEAR));criteria[1]=0;}

	if(criteria[2]==1 )
	{strcpy(mun,gtk_combo_box_get_active_text(GTK_COMBO_BOX(MUN)));;criteria[2]=0;}

        

	search_display(treeview,id,da,mun);
        

}


void
on_checkbutton_idsearch_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if(gtk_toggle_button_get_active(togglebutton))
       {criteria[0]=1;}
}


void
on_checkbutton_datesearch_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if(gtk_toggle_button_get_active(togglebutton))
       {criteria[1]=1;}
}


void
on_checkbutton_munsearch_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if(gtk_toggle_button_get_active(togglebutton))
       {criteria[2]=1;}
}




void
on_button_adminmanagment_clicked       (GtkWidget      *button,
                                        gpointer         user_data)
{
  GtkWidget *window_ADMIN;
  GtkWidget *window_signinadmin;
  window_signinadmin = lookup_widget(button, "window_signinadmin");
  gtk_widget_hide (window_signinadmin);
  window_ADMIN = create_window_ADMIN();
  gtk_widget_show (window_ADMIN);
}


void
on_button_claimsmanagment_clicked      (GtkWidget      *button,
                                        gpointer         user_data)
{
  GtkWidget *window_claim;
  GtkWidget *window_signinadmin;
  window_signinadmin = lookup_widget(button, "window_signinadmin");
  gtk_widget_hide (window_signinadmin);
  window_claim = create_window_claim();
  gtk_widget_show (window_claim);

}


void
on_button_listmanagment_clicked        (GtkWidget      *button,
                                        gpointer         user_data)
{
  GtkWidget *window_electorallist;
  GtkWidget *window_signinadmin;
  window_signinadmin = lookup_widget(button, "window_signinadmin");
  gtk_widget_hide (window_signinadmin);
  window_electorallist = create_window_electorallist();
  gtk_widget_show (window_electorallist);
}


void
on_button_clmactor_clicked             (GtkWidget      *button,
                                        gpointer         user_data)
{
  GtkWidget *window_claim;
  GtkWidget *window_signinactor;
  window_signinactor = lookup_widget(button, "window_signinactor");
  gtk_widget_hide (window_signinactor);
  window_claim = create_window_claim();
  gtk_widget_show (window_claim);
}


void
on_button_listactor_clicked            (GtkWidget      *button,
                                        gpointer         user_data)
{
  GtkWidget *window_electorallist;
  GtkWidget *window_signinactor;
  window_signinactor = lookup_widget(button, "window_signinactor");
  gtk_widget_hide (window_signinactor);
  window_electorallist = create_window_electorallist();
  gtk_widget_show (window_electorallist);
}


void
on_button_VOTE_clicked                 (GtkWidget      *button,
                                        gpointer         user_data)
{

}

void
on_button_backsigninadmin_clicked      (GtkWidget      *button,
                                        gpointer         user_data)
{
  GtkWidget *window_ADMIN;
  GtkWidget *window_signinadmin;
  window_ADMIN = lookup_widget(button, "window_ADMIN");
  gtk_widget_hide (window_ADMIN);
  window_signinadmin = create_window_signinadmin();
  gtk_widget_show (window_signinadmin);
}


void
on_button_backto_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

}


/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////NERMINE/////////////////////////////////////////////////

int type[3]={0,0,0};
int typemod[3]={0,0,0};

void
on_stuff_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
    type[0]=1;
}


void
on_system_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
type[1]=1;
}

void
on_other_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
type[2]=1;
}


void
on_button_submitclaim_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Claims c;

GtkWidget *identry;
GtkWidget *ellistentry;
GtkWidget *dateday;
GtkWidget *datemonth;
GtkWidget *dateyear;
GtkWidget *municipalityentry;
GtkWidget *testentry;
GtkWidget *exit;


exit=lookup_widget(objet_graphique,"exit");
identry=lookup_widget(objet_graphique,"identry");
ellistentry=lookup_widget(objet_graphique,"ellistentry");
dateday=lookup_widget(objet_graphique,"dateday");
datemonth=lookup_widget(objet_graphique,"datemonth");
dateyear=lookup_widget(objet_graphique,"dateyear");
municipalityentry=lookup_widget(objet_graphique,"municipalityentry");
testentry=lookup_widget(objet_graphique,"testentry");
int v=0;

c.date.d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateday));
c.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(datemonth));
c.date.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateyear));

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(identry)));
c.type[0]=type[0];
c.type[1]=type[1];
c.type[2]=type[2];
strcpy(c.electoral_list,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ellistentry)));
strcpy(c.municipality,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalityentry)));
strcpy(c.text,gtk_entry_get_text(GTK_ENTRY(testentry)));
v= verifection("claimsfile.txt", c.id);
int n;
if(v==1)
{gtk_label_set_text(GTK_LABEL(exit),"id exists already");}
else
{
n=add_claims("claimsfile.txt",c);
gtk_label_set_text(GTK_LABEL(exit),"claim added successfully");}

}

void
on_verifymodifclaim_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Claims c;

GtkWidget *identrymod;
GtkWidget *ellistentrymod;
GtkWidget *datedaymod;
GtkWidget *datemonthmod;
GtkWidget *dateyearmod;
GtkWidget *municipalityentrymod;
GtkWidget *testentrymod;
GtkWidget *ERR,*check1,*check2,*check3;
ERR=lookup_widget(objet_graphique,"errclaim");
identrymod=lookup_widget(objet_graphique,"identrymod");
ellistentrymod=lookup_widget(objet_graphique,"ellistentrymod");
datedaymod=lookup_widget(objet_graphique,"datedaymod");
datemonthmod=lookup_widget(objet_graphique,"datemonthmod");
dateyearmod=lookup_widget(objet_graphique,"dateyearmod");
municipalityentrymod=lookup_widget(objet_graphique,"municipalityentrymod");
testentrymod=lookup_widget(objet_graphique,"testentrymod");
check1=lookup_widget(objet_graphique,"stuffmod");
check2=lookup_widget(objet_graphique,"systemmod");
check2=lookup_widget(objet_graphique,"othermod");


strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(identrymod)));
int a=verifection("claimsfile.txt",c.id);
//v=search_claims("claimsfile.txt", c.id);
  char M[6][20]={"Ben_Arous","Tunis","Ariana","Manouba","Nabeul","Beja"};
  
   char EL[3][20]={"a","b","c"};
   int m=0;int el=0;
if (a==1)
  {gtk_label_set_text(GTK_LABEL(ERR),"id found");
   c=search_claims("claimsfile.txt", c.id);
if(c.type[0]==1)
      {gtk_toggle_button_set_active(GTK_CHECK_BUTTON(check1),TRUE);}
if(c.type[1]==1)
      {gtk_toggle_button_set_active(GTK_CHECK_BUTTON(check2),TRUE);}
if(c.type[2]==1)
      {gtk_toggle_button_set_active(GTK_CHECK_BUTTON(check3),TRUE);}  
 while(el<3 && strcmp(EL[el],c.electoral_list)!=0)
      {el++;}
      gtk_combo_box_set_active(GTK_COMBO_BOX(ellistentrymod),el);
	

      gtk_spin_button_set_value(datedaymod,c.date.d);
      gtk_spin_button_set_value(datemonthmod,c.date.m);
      gtk_spin_button_set_value(dateyearmod,c.date.y);
  
while(m<6 && strcmp(M[m],c.municipality)!=0)
      {m++;}
      gtk_combo_box_set_active(GTK_COMBO_BOX(municipalityentrymod),m);
      
      gtk_entry_set_text(GTK_ENTRY(testentrymod),c.text);
     
   }
   else
   {  gtk_label_set_text(GTK_LABEL(ERR),"id not found!");}
}

void
on_stuffmod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
typemod[0]=1;
}

void
on_systemmod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
typemod[1]=1;
}

void
on_othermod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
typemod[2]=1;
}

void
on_modifyclaim_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Claims c;

GtkWidget *identry;
GtkWidget *ellistentry;
GtkWidget *dateday;
GtkWidget *datemonth;
GtkWidget *dateyear;
GtkWidget *municipalityentry;
GtkWidget *testentry;
GtkWidget *exit;
identry=lookup_widget(objet_graphique,"identrymod");
ellistentry=lookup_widget(objet_graphique,"ellistentrymod");
dateday=lookup_widget(objet_graphique,"datedaymod");
datemonth=lookup_widget(objet_graphique,"datemonthmod");
dateyear=lookup_widget(objet_graphique,"dateyearmod");
municipalityentry=lookup_widget(objet_graphique,"municipalityentrymod");
testentry=lookup_widget(objet_graphique,"testentrymod");
exit=lookup_widget(objet_graphique,"errclaim");
c.date.d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateday));
c.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(datemonth));
c.date.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateyear));

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(identry)));
c.type[0]=typemod[0];
c.type[1]=typemod[1];
c.type[2]=typemod[2];
strcpy(c.electoral_list,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ellistentry)));
strcpy(c.municipality,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalityentry)));
strcpy(c.text,gtk_entry_get_text(GTK_ENTRY(testentry)));
int n;
n=modify_claims("claimsfile.txt",c.id,c);
gtk_label_set_text(GTK_LABEL(exit),"claim modified successfully");
}






void
on_button_find_clicked                 (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
Claims c;

GtkWidget *identrydel;
GtkWidget *errlabel_deleteclaim;
GtkWidget *label_municipalitydel;
GtkWidget *label_electorallistdel;


identrydel=lookup_widget(objet_graphique,"identrydel");
errlabel_deleteclaim=lookup_widget(objet_graphique,"errlabel_deleteclaim");
label_municipalitydel=lookup_widget(objet_graphique,"label_municipalitydel");
label_electorallistdel=lookup_widget(objet_graphique,"label_electorallistdel");



strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(identrydel)));
int v;
v=verifection("claimsfile.txt",c.id);
c=search_claims("claimsfile.txt", c.id);
if (v==1){gtk_label_set_text(GTK_LABEL(errlabel_deleteclaim),"id found");
          gtk_label_set_text(GTK_LABEL(label_municipalitydel),c.municipality);
          gtk_label_set_text(GTK_LABEL(label_electorallistdel),c.electoral_list);}
else{gtk_label_set_text(GTK_LABEL(errlabel_deleteclaim),"id not found");}
}


void
on_deletebutton_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Claims c;

GtkWidget *label_DELETE4;
GtkWidget *identrydel;

identrydel=lookup_widget(objet_graphique,"identrydel");
label_DELETE4=lookup_widget(objet_graphique,"errlabel_deleteclaim");



strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(identrydel)));

int v;int n;
v=verifection("claimsfile.txt",c.id);
if(v==1){
         n=delete_claims ("claimsfile.txt",c.id);
         gtk_label_set_text(GTK_LABEL(label_DELETE4),"CLAIM DELETED");}
else {gtk_label_set_text(GTK_LABEL(label_DELETE4),"CLAIM not DELETED");}
}


void
on_viewbuttondisplay_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *treeview;
   treeview=lookup_widget(button,"treeviewdisplayclaim");
   display_claim(treeview);
}

