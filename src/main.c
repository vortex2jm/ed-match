#include <stdio.h>
#include <stdlib.h>
#include "../include/server.h"

int main(int argc, char ** argv){

  StartValidator(argc);
  int packagesNumber = PackagesNumber(argv);
  
  // caminhos relativos para os arquivos
  char allUsersFile[50] = "./tests/in/users.txt";
  char userFile[50] = "../tests/in/";

  List * users = LoadUsers(allUsersFile);

  PrintUsersList(users);

  return 0;
}
