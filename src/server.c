#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/server.h"
#include "../include/user.h"
#include "../include/hobbiesList.h"
#include "../include/hobbie.h"
#include "../include/post.h"
#include "../include/postsList.h"

// Public functions
void StartValidator(int argc);
int PackagesNumber(char ** argv);
List * LoadUsers(char * fileWay);
List * ProcessPackages(List * usersList, char * allUsersFile,
                       char * singleUserFile, int packageNumber);

// Private functions
List * LoadHobbies(char * hobbies);
int LinesNumber(FILE * file);
char ** CreateNamesList(FILE * usersFile, int usersNumber);
void FreeNamesList(char ** list, int amount);
void StorePackages(List * usersList, int usersNumber, char * singleUserFileDir, char ** usersNames, int packageNumber);
void ExecutePackages(List * usersList, char ** usersNames, int packageNumber, int usersNumber);
void LikesProcessor(User * user, List * usersList, char * like);
void UnlikesProcessor(User * user, List * usersList, char * unlike);
void HobbieChangesProcessor(User * user, char * hobbieChange);
void PostProcessor(User * user,List * usersList, char * post);

//=====================================================================================//
void StartValidator(int argc){
  if(argc <= 1){
    printf("Escolha o numero de leituras do package!\n");
    exit(1);
  }
}

//=====================================================================================//
int PackagesNumber(char ** argv){
  int number;
  sscanf(argv[1],"%d",&number);
  return number;
}

//=====================================================================================//
List * LoadUsers(char * fileWay){

  FILE * usersFile = fopen(fileWay, "r");

  int age = 0;
  char name[50], location[50], hobbies[500];

  List * usersList = CreateVoidList();
  User * user=NULL;
  List * hobbiesList=NULL;

  while(!feof(usersFile)){
    fscanf(usersFile,"%[^;];%d;%[^;];%[^\n]\n", name, &age, location, hobbies);

    hobbiesList = LoadHobbies(hobbies);
    user = UserConstructor(name, age, location, hobbiesList);
    PushUsersList(usersList, user);
  }

  fclose(usersFile);

  return usersList;
}

//=====================================================================================//
List * LoadHobbies(char * hobbies){

  List * hobbiesList = CreateHobbiesList();
  Hobbie * hobbie = NULL;

  char * hobbieName = strtok(hobbies, ",");
  while(hobbieName){
    
    hobbie = HobbieConstructor(hobbieName);
    PushHobbiesList(hobbiesList, hobbie);

    hobbieName = strtok(NULL, ",");
  }
  return hobbiesList;
}

//=====================================================================================//
List * ProcessPackages(List * usersList, char * allUsersFile, char * singleUserFileDir, int packageNumber){
  
  FILE * usersFile = fopen(allUsersFile,"r");

  int usersNumber = LinesNumber(usersFile);
  fseek(usersFile,0,SEEK_SET);
  char ** usersNames = CreateNamesList(usersFile, usersNumber);

  fclose(usersFile);

  StorePackages(usersList, usersNumber, singleUserFileDir, usersNames, packageNumber);
  ExecutePackages(usersList, usersNames, packageNumber, usersNumber);

  FreeNamesList(usersNames, usersNumber);  
}

//=====================================================================================//
int LinesNumber(FILE * file){
  int n=0;
  char c;

  while(fread(&c, sizeof(char), 1, file)){
    if(c=='\n')
      n++;
  }
  return n+1; 
}

//=====================================================================================//
char ** CreateNamesList(FILE * usersFile, int usersNumber){

  char name[50];

  char ** usersName = malloc(sizeof(char*) * usersNumber);
  for(int x=0;x<usersNumber;x++){
    usersName[x] = malloc(sizeof(char) * 50);
  }

  int index=0;
  while(!feof(usersFile)){
    fscanf(usersFile,"%[^;]%*[^\n]\n",name);
    usersName[index] = strdup(name);
    index++;
  }

  return usersName;
}

//=====================================================================================//
void FreeNamesList(char ** list, int amount){
  if(!list)return; 

  // liberando memoria do array de nomes
  for(int x=0;x<amount;x++){
    free(list[x]);
  }
  free(list);
}

//=====================================================================================//
void StorePackages(List * usersList, int usersNumber, char * singleUserFileDir, char ** usersNames, int packageNumber){

  FILE * singleUserfile;
  char like[50], unlike[50], hobbieChange[100], post[500], singleUserFileWay[50];
  User * user;
  Package * package, **packageArray;
  
  // Lendo e armazenando pacotes
  for(int x=0;x<usersNumber;x++){

    sprintf(singleUserFileWay,"%s%s.package.txt", singleUserFileDir, usersNames[x]);
    packageArray = malloc(sizeof(Package*)*packageNumber);


    singleUserfile = fopen(singleUserFileWay,"r");
    for(int y=0;y<packageNumber;y++){
      fscanf(singleUserfile,"%[^;];%[^;];%[^;];%[^\n]\n",like, unlike, hobbieChange, post);
      package = PackageConstructor(like, unlike, hobbieChange, post);
      packageArray[y] = package;  
    }
    fclose(singleUserfile);

    user = GetUser(usersList, usersNames[x]);  
    SetPackage(user, packageArray);
  }
}

//=====================================================================================//
void ExecutePackages(List * usersList, char ** usersNames, int packageNumber, int usersNumber){

  User * user;
  Package ** packageArray, *package;
  user = GetUser(usersList, "Joao");

  for(int x=0; x<packageNumber;x++){
    for(int y=0;y<usersNumber;y++){

      user = GetUser(usersList, usersNames[y]);
      printf("user = %s\n", GetUserName(user));

      packageArray = GetPackage(user);
      package = packageArray[x];

      LikesProcessor(user, usersList, GetLike(package));
      UnlikesProcessor(user, usersList,GetUnlike(package));
      HobbieChangesProcessor(user, GetHobbieChange(package));
      PostProcessor(user, usersList, GetPost(package));
    }
  }

  // Processar as sugestões de amizade...
}

//=====================================================================================//
void LikesProcessor(User * user, List * usersList, char * like){

  if(!strcmp(like,"."))
    return;
  printf("LIKE = %s\n", like);

  // Caso o outro usuario já o tenha curtido (viram amigos)
  if(GetUser(GetLikesList(user),like)){
    User * likedUser = GetUser(usersList, like);
    
    PushFriendsList(GetFriendsList(likedUser), user);
    SetFriendsAmount(likedUser,1);
    // SetAllPostsReach(GetOwnPostsList(likedUser), 1); 

    PushFriendsList(GetFriendsList(user), likedUser);
    SetFriendsAmount(user,1);
    // SetAllPostsReach(GetOwnPostsList(user), 1); 

    return;
  }

  // Caso nao tenha curtido(Adiciona na lista de likes)
  User * likedUser = GetUser(usersList, like);
  PushLikesList(GetLikesList(likedUser), user);
}

//=====================================================================================//
void UnlikesProcessor(User * user, List * usersList, char * unlike){

  if(!strcmp(unlike,"."))
    return;

  User * unlikedUser = GetUser(usersList, unlike);
  // caso sejam amigos, retira da lista de amigos
  if(GetUser(GetFriendsList(user), unlike)){

    FriendsListRemove(GetFriendsList(user), unlike);
    SetFriendsAmount(user, -1);
    // SetAllPostsReach(GetOwnPostsList(user), -1);

    FriendsListRemove(GetFriendsList(unlikedUser), GetUserName(user));
    SetFriendsAmount(unlikedUser, -1);
    // SetAllPostsReach(GetOwnPostsList(unlikedUser), -1);
  }
  // retira o usuario da lista de likes do unlikedUser
  LikesListRemove(GetLikesList(unlikedUser), GetUserName(user));
}

//=====================================================================================//
void HobbieChangesProcessor(User * user, char * hobbieChange){

  if(!strcmp(hobbieChange,"."))
    return;

  List * oldHobbiesList = GetHobbiesList(user);
  FreeHobbiesList(oldHobbiesList);

  List * newHobbiesList = LoadHobbies(hobbieChange);
  SetHobbiesList(user, newHobbiesList);
}

//=====================================================================================//
void PostProcessor(User * user,List * usersList, char * post){

  if(!strcmp(post,"."))
    return;
  
  // Adicionando o post na propria lista de posts
  Post * newPost = PostConstructor(GetUserName(user), post, GetFriendsAmount(user));
  PushPostsList(GetOwnPostsList(user), newPost);
  UpdateFriendsPostsList(GetFriendsList(user), newPost);
}

//=====================================================================================//
void ProcessFriendsSuggestions(List * usersList){

}

//=====================================================================================//
void GenerateReports(List * usersList){


}
