#include "../include/user.h"
#include <stdlib.h>
#include <string.h>

struct user {
  int age;
  int friendsAmount;
  char * name;
  char * location;
  List * likesList;
  List * hobbiesList; 
  List * friendsList;
  List * ownPostsList;
  List * friendsPostsList;
  List * friendsSuggestionList;
  Package ** package;
};

User * UserConstructor(char * name, int age, char * location, List * hobbies){

  User * user = calloc(1,sizeof(User));
  user->name = strdup(name);
  user->location = strdup(location);
  user->age = age;
  user->hobbiesList = hobbies;

  return user;
}

char * GetUserName(User * user){
  return user->name;
}

int GetUserAge(User * user){
  return user->age;
}

char * GetUserLocation(User * user){
  return user->location;
}

List * GetUserHobbiesList(User * user){
  return user->hobbiesList;
}

void SetPackage(User * user, Package ** package){
  user->package = package;
}

Package ** GetPackage(User * user){
  return user->package;
}