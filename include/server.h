#ifndef server_h
#define server_h
#include "usersList.h"

void StartValidator(int argc);

int PackagesNumber(char ** argv);

List * LoadUsers(char * fileWay);

List * ProcessPackages(List * usersList, char * filesWay);

void GenerateReports(List * usersList);

#endif
