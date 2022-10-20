#include "../include/list.h"
#include "../include/usersList.h"
#include "../include/hobbiesList.h"
#include "../include/post.h"
#include "../include/postsList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// callback
static int compare_user(void * user, void * key){
  char name[50];
  strcpy(name, key); 

  return strcmp(GetUserName(user), name) == 0;
}
//=====================================//
static void print_user(void * user){
  PrintFullUser(user);
}
//=====================================//
static void update_post(void * user, void * post){
  PushPostsList(GetFriendsPostsList(user),post);
}
//=====================================//
static void print_partial_user(void * user){
  PrintPartialUser(user);
}

//=================================================================//

// Usada em todos os tipos de lista
User * GetUser(List * list, char * name){
  return GetElement(list, compare_user, name);
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
void PrintUsersList(List * list){
  PrintList(list, print_user);
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
void UpdateFriendsPostsList(List * list, Post * post){
  GoThroughList(list,update_post ,post);
}
void PrintFriendsList(List * list){
  PrintList(list,print_partial_user);
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
void PrintFriendsSuggestionList(List * list){
  PrintList(list,print_partial_user);
}


// Lista de likes
List * CreateLikesList(){
  return CreateUsersList();
}
List * PushLikesList(List * list, User * user){
  return PushUsersList(list, user);
}
User * LikesListRemove(List * list, char * name){
  return UsersListRemove(list, name);
}
void FreeLikesList(List * list){
  FreeUsersList(list);
}
