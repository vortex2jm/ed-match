#ifndef hobbie_h
#define hobbie_h

typedef struct hobbie Hobbie;

Hobbie * HobbieConstructor(char * name);

char * Gethobbie(Hobbie * hobbie);

void FreeHobbie(Hobbie * hobbie);

#endif
