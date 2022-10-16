#include "../include/list.h"
#include "../include/usersList.h"
#include <stdlib.h>
#include <string.h>

// callback
static int compare_user(void * user, void * key){
  char name[50];
  strcpy(name, key); 

  return strcmp(GetUserName(user), name) == 0;
}

// As funções abaixo serão chamadas dentro de outras funções com nomes diferentes para fins didáticos
List * CreateUsersList(){
  return CreateVoidList();
}
List * PushUsersList(List * list, User * user){
  return PushList(list, user);
}
User * UsersListRemove(List * list, char * name){
  return ListRemove(list, compare_user, name);
}
void FreeUsersList(List * list){
  DestructList(list);
}


// Lista de amigos
List * CreateFriendsList(){
  return CreateUsersList();
}
List * PushFriendsList(List * list, User * user){
  return PushUsersList(list, user);
}
User * FriendsListRemove(List * list, char * name){
  return UsersListRemove(list, name);
}
void FreeFriendsList(List * list){
  FreeUsersList(list);
}


// Lista de solicitações
List * CreateFriendsSuggestionList(){
  return CreateUsersList();
}
List * PushFriendsSuggestionList(List * list, User * user){
  return PushUsersList(list, user);
}
User * FriendsSuggestionListRemove(List * list, char * name){
  return UsersListRemove(list, name);
}
void FreeFriendsSuggestionList(List * list){
  FreeUsersList(list);
}
