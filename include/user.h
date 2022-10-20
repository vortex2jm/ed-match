#ifndef user_h
#define user_h
#include "list.h"
#include "package.h"

typedef struct user User;

// Construtor do tipo usuário
User * UserConstructor(char * name, int age, char * location, List * hobbies);

// Retorna o nome do usuário
char * GetUserName(User * user);

int GetUserAge(User * user);

char * GetUserLocation(User * user);

int GetFriendsAmount(User * user);

void SetFriendsAmount(User * user, int newFriendsAmount);

List * GetHobbiesList(User * user);

void SetHobbiesList(User * user, List * newHobbiesList);

// Imprime os dados do usuário
void PrintFullUser(User * user);

void PrintPartialUser(User * user);

// Libera o espaço de memória alocado para o usuário
void DeleteUser(User * user);

void SetPackage(User * user, Package ** package);

Package ** GetPackage(User * user);

List * GetLikesList(User * user);

List * GetFriendsList(User * user);

List * GetOwnPostsList(User * user);

List * GetFriendsPostsList(User * user);

int ProcessUsersCompatibility(User * user1, User * user2);

List * GetFriendsSuggestionsList(User * user);

#endif
