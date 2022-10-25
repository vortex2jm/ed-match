#ifndef server_h
#define server_h
#include "usersList.h"

void StartValidator(int argc);

int PackagesNumber(char ** argv);

List * LoadUsers(char * fileWay, int packagesAmount);

List * ProcessPackages(List * usersList, char * allUsersFile,
   char * singleUserFile, char * logsFileDir, int packageNumber);

void GenerateReports(List * usersList);

#endif
