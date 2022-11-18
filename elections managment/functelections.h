#ifndef FUNCTELECTIONS_H_INCLUDED
#define FUNCTELECTIONS_H_INCLUDED
#include <stdio.h>
typedef struct {int d;int m;int y;}date;
typedef struct { char elecid[20];
		 date date;
		 int municip;
		 int numhab;
		 int numps;
		 int electype;
		}election;
int add_election( char * filename, election e);
int modify_election( char * filename, char id[20], election enew);
int delete_election (char * filename, char id[20]);
election search_election(char * filename, char id[20]);
#endif // FUNCTELECTIONS_H_INCLUDED


