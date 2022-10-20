#ifndef hobbie_h
#define hobbie_h
#include <stdio.h>

typedef struct hobbie Hobbie;

Hobbie * HobbieConstructor(char * name);

void SetHobbie(Hobbie * hobbie, char * hobbieName);

char * GetHobbie(Hobbie * hobbie);

void PrintHobbie(Hobbie * hobbie);

void PrintHobbieF(Hobbie * hobbie, FILE * file);

void FreeHobbie(Hobbie * hobbie);

#endif
