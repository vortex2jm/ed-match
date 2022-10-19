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
List * ProcessPackages(List * usersList, char * allUsersFile,
                       char * singleUserFile, int packageNumber);

// Private functions
List * LoadHobbies(char * hobbies);
int LinesNumber(FILE * file);


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

  FILE * usersFile = fopen(fileWay, "r");

  int age = 0;
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

  fclose(usersFile);

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

List * ProcessPackages(List * usersList, char * allUsersFile, char * singleUserFileDir, int packageNumber){
         
  char name[50];
  char singleUserFileWay[50];
  FILE * usersFile = fopen(allUsersFile,"r");
  
  // calculando a quantidade de usuarios (que eh igual a quantidade de linhas)
  int linesNumber = LinesNumber(usersFile);
  // movendo o ponteiro para o inicio do arquivo
  fseek(usersFile,0,SEEK_SET);

  // alocando memoria para os nomes
  char ** usersName = malloc(sizeof(char*) * linesNumber);
  for(int x=0;x<linesNumber;x++){
    usersName[x] = malloc(sizeof(char) * 50);
  }

  int index=0;
  while(!feof(usersFile)){
    fscanf(usersFile,"%[^;]%*[^\n]\n",name);
    usersName[index] = strdup(name);
    index++;
  }


  FILE * singleUserfile;
  for(int x=0;x<packageNumber;x++){
    for(int y=0;y<linesNumber;y++){
      sprintf(singleUserFileWay,"%s%s.package.txt", singleUserFileDir, usersName[y]);
      singleUserfile = fopen(singleUserFileWay,"a");
      fprintf(singleUserfile,"oi");
    }
  }


  // liberando memoria do array de nomes
  for(int x=0;x<linesNumber;x++){
    free(usersName[x]);
  }
  free(usersName);

  fclose(usersFile);  
}

int LinesNumber(FILE * file){
  int n=0;
  char c;

  while(fread(&c, sizeof(char), 1, file)){
    if(c=='\n')
      n++;
  }
  return n+1; 
}
