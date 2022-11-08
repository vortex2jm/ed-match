#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  StartValidator(argc);
  int packagesNumber = PackagesNumber(argv);

  // caminhos relativos para os arquivos
  char allUsersFile[50] = "./tests/test3/input/users.txt";
  char userFile[50] = "./tests/test3/input/";
  char logsFile[50] = "./tests/test3/output/logs.txt";

  List *users = LoadUsers(allUsersFile, packagesNumber);

  ProcessPackages(users, allUsersFile, userFile, logsFile, packagesNumber);
  PrintUsersList(users);
  FreeUsersList(users);

  return 0;
}
