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

void FreeHobbie(Hobbie * hobbie){
  if(hobbie){
    if(hobbie->name)
      free(hobbie->name);
    free(hobbie);
  }
}
