#include <stdlib.h>
#include <string.h>
#include "../include/hobbiesList.h"

// callback
static int compare_hobbie(void * hobbie, void * key){
  char name[50];
  strcpy(name, key); 

  return strcmp(Gethobbie(hobbie), name) == 0;
}


List * CreateHobbiesList(){
  return CreateVoidList();
}

List * PushHobbiesList(List * list, Hobbie * hobbie){
  return PushList(list, hobbie);
}

Hobbie * HobbiesListRemove(List * list, char * name){
  return ListRemove(list, compare_hobbie, name);
}

void FreeHobbiesList(List * list){
  DestructList(list);
}