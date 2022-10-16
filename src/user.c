#include "../include/user.h"
#include <stdlib.h>
#include <string.h>

struct user {
  int age;
  int friendsAmount;
  char * name;
  List * friendsPostsList;
  List * ownPostsList;
  List * hobbiesList; 
  List * friendsList;
  List * friendsSuggestionList;
};

User * UserConstructor(char * name, int age, char * location, List * hobbies){

  User * user = calloc(1,sizeof(User));
  user->name = strdup(name);
  user->age = age;
  user->hobbiesList = hobbies;

  return user;
}

char * GetUserName(User * user){
  return user->name;
}
