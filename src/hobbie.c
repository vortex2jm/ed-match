#include "../include/hobbie.h"
#include <stdlib.h>
#include <string.h>

struct hobbie {
  char * name;
};

Hobbie * HobbieConstructor(char * name){

  Hobbie * hobbie = malloc(sizeof(Hobbie));
  hobbie->name = strdup(name);

  return hobbie;
}

char * Gethobbie(Hobbie * hobbie){
  return hobbie->name;
}

void SetHobbie(Hobbie * hobbie, char * hobbieName){
  if(hobbie->name)
    free(hobbie->name);
  hobbie->name = strdup(hobbieName);
}

void FreeHobbie(Hobbie * hobbie){
  if(hobbie){
    if(hobbie->name)
      free(hobbie->name);
    free(hobbie);
  }
}
