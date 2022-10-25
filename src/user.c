#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "../include/user.h"
#include "../include/usersList.h"
#include "../include/postsList.h"
#include "../include/hobbiesList.h"

struct user {
  int age;
  int friendsAmount;
  int packagesAmount;
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

User * UserConstructor(char * name, int age, char * location, int packagesAmount, List * hobbies){

  User * user = malloc(sizeof(User));
  user->age = age;
  user->package = NULL;
  user->packagesAmount = packagesAmount;
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

List * GetFriendsSuggestionsList(User * user){
  return user->friendsSuggestionList;
}

void PrintFullUser(User * user){
  printf("====================\n");
  printf("%s\n%d anos\n%s\n%d amigos\n\n", user->name, user->age, user->location, user->friendsAmount);

  printf("HOBBIES\n");
  PrintHobbiesList(user->hobbiesList);
  printf("\n");
  
  printf("POSTS PUBLICADOS\n");
  PrintPostsList(user->ownPostsList);
  printf("\n");
  
  printf("POSTS DO FEED\n");
  PrintPostsList2(user->friendsPostsList);
  printf("\n");

  printf("MATCHES\n");
  PrintFriendsList(user->friendsList);
  printf("\n");

  printf("SUGESTOES DE AMIZADE\n");
  PrintFriendsSuggestionList(user->friendsSuggestionList);
  printf("\n");
}

// precisei fazer esta função para evitar recursão infinita
void PrintPartialUser(User * user){
  printf("%s\n",user->name);
}

int ProcessUsersCompatibility(User * user1, User * user2){
  
  int ageDiff = abs(user1->age - user2->age);
  int sameLocation = !strcmp(user1->location, user2->location);

  return (ageDiff<=5 && sameLocation);
}

void FreeUser(User * user){
  // Nesta função,liberaremos apenas a memória alocada dentro da construção do próprio usuário
  if(user){
    if(user->name)free(user->name);
    if(user->package)FreePackages(user->package,user->packagesAmount);
    if(user->location)free(user->location);
    if(user->hobbiesList)FreeHobbiesList(user->hobbiesList);
    if(user->ownPostsList)FreePostsList(user->ownPostsList);
    if(user->likesList)DestructList(user->likesList);
    if(user->friendsList)DestructList(user->friendsList);
    if(user->friendsPostsList)DestructList(user->friendsPostsList);
    if(user->friendsSuggestionList)DestructList(user->friendsSuggestionList);
    free(user);
  }
}
