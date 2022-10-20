#ifndef userslist_h
#define userslist_h
#include "list.h"
#include "user.h"
#include "post.h"

List * CreateUsersList();
List * CreateFriendsList();
List * CreateFriendsSuggestionList();
List * CreateLikesList();

List * PushUsersList(List * list, User * user);
List * PushFriendsList(List * list, User * user);
List * PushFriendsSuggestionList(List * list, User * user);
List * PushLikesList(List * list, User * user);

User * UsersListRemove(List * list, char * name);
User * FriendsListRemove(List * list, char * name);
User * FriendsSuggestionListRemove(List * list, char * name);
User * LikesListRemove(List * list, char * name);

void PrintUsersList(List * list);
void PrintFriendsSuggestionList(List * list);
void PrintFriendsList(List * list);

void FreeUsersList(List * list);
void FreeFriendsList(List * list);
void FreeFriendsSuggestionList(List * list);
void FreeLikesList(List * list);

User * GetUser(List * list, char * name);

void UpdateFriendsPostsList(List * list, Post * post);
void GenerateFriendsSuggestions(List * list, User * user);

#endif
