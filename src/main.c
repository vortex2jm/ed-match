#include <stdio.h>
#include <stdlib.h>
#include "../include/server.h"

int main(int argc, char ** argv){

  StartValidator(argc);
  int packagesNumber = PackagesNumber(argv);
  
  // caminhos relativos para os arquivos
  char allUsersFile[50] = "./tests/in/users.txt";
  char userFile[50] = "./tests/in/";
  char logsFile[50] = "./tests/out/logs.txt";

  List * users = LoadUsers(allUsersFile);
  ProcessPackages(users,allUsersFile,userFile,logsFile,packagesNumber);
  
  PrintUsersList(users);
  
  return 0;
}
