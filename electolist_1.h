#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED


typedef struct {
int d;
int m;
int y;
}date;
typedef struct {
char id_liste;
int municipality;
char orientation;
char id_HOL;
char id1;
char id2;
char id3;
date da;
}electoral;
int add_electoral(electoral e, char * liselect );
int modify_electoral(int id_HOL, electoral new_e, char * liselect);
int delete_electoral(int id_liste, char * liselect);
electoral search_eletoral(int id_liste, char * liselect);
#endif // HEADERS_H_INCLUDED
