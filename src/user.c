#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/user.h"
#include "../include/usersList.h"
#include "../include/postsList.h"
#include "../include/hobbiesList.h"

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

  User * user = malloc(sizeof(User));
  user->age = age;
  user->package = NULL;
  user->friendsAmount = 0;
  user->name = strdup(name);
  user->hobbiesList = hobbies;
  user->location = strdup(location);
  user->likesList = CreateLikesList();
  user->friendsList = CreateFriendsList();
  user->ownPostsList = CreatePostsList();
  user->friendsPostsList = CreatePostsList();
  user->friendsSuggestionList = CreateFriendsSuggestionList(); 

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

int GetFriendsAmount(User * user){
  return user->friendsAmount;
}

void SetFriendsAmount(User * user, int plusAmount){
  user->friendsAmount += plusAmount;
}

List * GetHobbiesList(User * user){
  return user->hobbiesList;
}

void SetHobbiesList(User * user, List * newHobbiesList){
  user->hobbiesList = newHobbiesList;
}

Package ** GetPackage(User * user){
  return user->package;
}

void SetPackage(User * user, Package ** package){
  user->package = package;
}

List * GetLikesList(User * user){
  return user->likesList;
}

List * GetFriendsList(User * user){
  return user->friendsList;
}

List * GetOwnPostsList(User * user){
  return user->ownPostsList;
}

List * GetFriendsPostsList(User * user){
  return user->friendsPostsList;
}

void PrintFullUser(User * user){
  printf("\n====USUÁRIO=====================================//\n");
  printf("%s\n%d\n%s\n", user->name, user->age, user->location);
  
  printf("%d amigos\n", user->friendsAmount);

  printf("===HOBBIES===\n");
  PrintHobbiesList(user->hobbiesList);
  
  printf("===POSTS PUBLICADOS===\n");
  PrintPostsList(user->ownPostsList);
  
  printf("===POSTS DO FEED===\n");
  PrintPostsList(user->friendsPostsList);

  printf("===MATCHES===\n");
  PrintFriendsList(user->friendsList);
}

// precisei fazer esta função para evitar recursão infinita
void PrintPartialUser(User * user){
  printf("%s\n",user->name);
}
