#ifndef server_h
#define server_h
#include "usersList.h"

void StartValidator(int argc);

int PackagesNumber(char ** argv);

List * LoadUsers(char * fileWay);

#endif
