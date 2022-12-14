#ifndef FUNCTELECTIONS_H_INCLUDED
#define FUNCTELECTIONS_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct {int d;int m;int y;}date;
typedef struct { char elecid[20];
		 date date;
		 char municip[20];
		 char numhab[50];
		 char numps[50];
		 int electype;
		}election;
typedef struct{
	char CIN[20];
	char PW[20];
}account;
int add_election( char * filename, election e);
int modify_election( char * filename, char id[20], election enew);
int delete_election (char * filename, char id[20]);
election search_election(char * filename, char id[20]);
void election_type(int electype, char msg[20]);
int reverse_election_type( char msg[20]);
int verify_id(char * filename,char id[20]);
date stringtodate(char elecdate[20]);
void display_election(GtkWidget *list);
void empty(GtkWidget *list);
void search_display(GtkWidget *list,char id[20],date da,char mun[20]);
int search_account(char * filename, char CIN[20]);
#endif // FUNCTELECTIONS_H_INCLUDED


