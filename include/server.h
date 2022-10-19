#ifndef server_h
#define server_h
#include "usersList.h"

void StartValidator(int argc);

int PackagesNumber(char ** argv);

List * LoadUsers(char * fileWay);

List * ProcessPackages(List * usersList, char * allUsersFile,
   char * singleUserFile, int packageNumber);

void GenerateReports(List * usersList);

#endif
