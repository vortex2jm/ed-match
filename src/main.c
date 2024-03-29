#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  StartValidator(argc);
  int packagesNumber = PackagesNumber(argv);

  // caminhos relativos para os arquivos
  char allUsersFile[50] = "./tests/test5/input/users.txt";
  char userFile[50] = "./tests/test5/input/";
  char logsFile[50] = "./tests/test5/output/logs.txt";

  List *users = LoadUsers(allUsersFile, packagesNumber);

  ProcessPackages(users, allUsersFile, userFile, logsFile, packagesNumber);
  PrintUsersList(users);
  FreeUsersList(users);

  return 0;
}
