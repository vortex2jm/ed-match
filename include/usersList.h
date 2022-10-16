#ifndef userslist_h
#define userslist_h
#include "list.h"
#include "user.h"

List * CreateUsersList();
List * CreateFriendsList();
List * CreateFriendsSuggestionList();

List * PushUsersList(List * list, User * user);
List * PushFriendsList(List * list, User * user);
List * PushFriendsSuggestionList(List * list, User * user);

User * UsersListRemove(List * list, char * name);
User * FriendsListRemove(List * list, char * name);
User * FriendsSuggestionListRemove(List * list, char * name);

void FreeUsersList(List * list);
void FreeFriendsList(List * list);
void FreeFriendsSuggestionList(List * list);

#endif
