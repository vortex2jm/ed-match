#ifndef hobbies_list
#define hobbies_list
#include "list.h"
#include "hobbie.h"

List * CreateHobbiesList();

List * PushHobbiesList(List * list, Hobbie * hobbie);

Hobbie * HobbiesListRemove(List * list, char * name);

void FreeHobbiesList(List * list);

#endif
