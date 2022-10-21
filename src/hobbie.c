#include "../include/hobbie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct hobbie {
  char * name;
};

Hobbie * HobbieConstructor(char * name){

  Hobbie * hobbie = malloc(sizeof(Hobbie));
  hobbie->name = strdup(name);

  return hobbie;
}

char * GetHobbie(Hobbie * hobbie){
  return hobbie->name;
}

void SetHobbie(Hobbie * hobbie, char * hobbieName){
  if(hobbie->name)
    free(hobbie->name);
  hobbie->name = strdup(hobbieName);
}

void PrintHobbie(Hobbie * hobbie){
  printf("%s\n", hobbie->name);
}

void PrintHobbieF(Hobbie * hobbie, FILE * file){
  if(!hobbie){
    printf("Hobbie vazio!\n");
    return;
  }
  fprintf(file, "~ %s\n", hobbie->name);
}

void FreeHobbie(Hobbie * hobbie){
  if(hobbie){
    if(hobbie->name)
      free(hobbie->name);
    free(hobbie);
  }
}
