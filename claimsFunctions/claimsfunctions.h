#ifndef HEADERPROJECT_H_INCLUDED
#define HEADERPROJECT_H_INCLUDED
typedef struct {
     int month;
     int day;
     int year;
}Date;
typedef struct{
    char id[50];
    int type[3];
    char electoral_list[20];
    Date date ;
    int municipality;
    char text[200];
}Claims;


int add_claims(char* filename,Claims cl);
int modify_claims( char * filename, char id[20],Claims cnew);
int delete_claims (char * filename, char id[20]);
Claims  search_claims(char * filename, char id[20]);
#endif // HEADERPROJECT_H_INCLUDED
