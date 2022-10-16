#ifndef user_h
#define user_h
#include "list.h"

typedef struct user User;

// Construtor do tipo usuário
User * UserConstructor(char * name, int age, char * location, List * hobbies);

// Retorna o nome do usuário
char * GetUserName(User * user);

// Adiciona ou remove um amigo da lista de amigos (A flag indica qual operação será realizada)
User * UpdateUserFriendsList(User * user, User * friend, int addOrRemoveFlag);

// Imprime os dados do usuário
void PrintUser(User * user);

// Libera o espaço de memória alocado para o usuário
void DeleteUser(User * user);

#endif
