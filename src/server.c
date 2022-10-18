#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/server.h"
#include "../include/user.h"
#include "../include/hobbiesList.h"
#include "../include/hobbie.h"

// Public functions
void StartValidator(int argc);
int PackagesNumber(char ** argv);
List * LoadUsers(char * fileWay);

// Private functions
List * LoadHobbies(char * hobbies);

// ======================================================================== //
void StartValidator(int argc){
  if(argc <= 1){
    printf("Escolha o numero de leituras do package!\n");
    exit(1);
  }
}

int PackagesNumber(char ** argv){
  int number;
  sscanf(argv[1],"%d",&number);
  return number;
}

List * LoadUsers(char * fileWay){

  FILE * usersFile = fopen(fileWay, "w");

  int age;
  char name[50], location[50], hobbies[500];

  List * usersList = CreateVoidList();
  User * user=NULL;
  List * hobbiesList=NULL;

  while(!feof(usersFile)){
    fscanf(usersFile,"%[^;];%d;%[^;];%[^\n]\n", name, &age, location, hobbies);
    
    hobbiesList = LoadHobbies(hobbies);
    user = UserConstructor(name, age, location, hobbiesList);
    PushUsersList(usersList, user);
  }

  return usersList;
}

List * LoadHobbies(char * hobbies){

  List * hobbiesList = CreateHobbiesList();
  Hobbie * hobbie = NULL;

  char * hobbieName = strtok(hobbies, ",");
  while(hobbieName){
    
    hobbie = HobbieConstructor(hobbieName);
    PushHobbiesList(hobbiesList, hobbie);

    hobbieName = strtok(NULL, ",");
  }
  return hobbiesList;
}
