#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/hobbiesList.h"

// callback
static int compare_hobbie(void * hobbie, void * key){
  char name[50];
  strcpy(name, key); 

  return strcmp(GetHobbie(hobbie), name) == 0;
}
static void print_hobbie(void * hobbie){
  PrintHobbie(hobbie);
}
static void print_hobbie_into_file(void * hobbie, void * file){
  PrintHobbieF(hobbie, file);
} 

//========================================================//
List * CreateHobbiesList(){
  return CreateVoidList();
}

List * PushHobbiesList(List * list, Hobbie * hobbie){
  return PushList(list, hobbie);
}

Hobbie * HobbiesListRemove(List * list, char * name){
  return ListRemove(list, compare_hobbie, name);
}

void PrintHobbiesList(List * list){
  PrintList(list, print_hobbie);
}

void PrintHobbiesListIntoFile(List * list, FILE * file){
  GoThroughList(list, print_hobbie_into_file, file);
}

void FreeHobbiesList(List * list){
  DestructList(list);
}
