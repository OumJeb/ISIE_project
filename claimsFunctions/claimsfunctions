#ifndef HEADERPROJECT_H_INCLUDED
#define HEADERPROJECT_H_INCLUDED
typedef struct {
     int month;
     int day;
     int year;
}Date;
typedef struct{
    int id;
    int type[3];
    int electoral_list;
    Date date ;
    int municipality;
    char text[200];
}Claims;


int add_claims(char* file name,claims cl);
int modify_claims( char * filename, char id[20],claims cnew);
int delete_claims (char * filename, char id[20]);
election search_claims(char * filename, char id[20]);
#endif // HEADERPROJECT_H_INCLUDED
