#ifndef FUNCTELECTIONS_H_INCLUDED
#define FUNCTELECTIONS_H_INCLUDED
#include <stdio.h>
typedef struct {int d;int m;int y;}date;
typedef struct { char elecid[20];
		 date Date;
		 int municip;
		 int numhab;
		 int numps;
		 int municipal;
		 int legislative;
		}election;
#endif // FUNCTELECTIONS_H_INCLUDED


