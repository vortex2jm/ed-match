#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/package.h"

struct package{
  char * like;
  char * unlike;
  char * hobbieChange;
  char * post;
};

Package * PackageConstructor(char * like, char * unlike, char * hobbieChange, char * post){

  Package * package = malloc(sizeof(Package));
  package->like = strdup(like);
  package->unlike = strdup(unlike);
  package->hobbieChange = strdup(hobbieChange);
  package->post = strdup(post);

  return package;
}

char * GetLike(Package * package){
  return package->like;
}

char * GetUnlik(Package * package){
  return package->unlike;
}

char * GetHobbieChange(Package* package){
  return package->hobbieChange;
}

char * GetPost(Package * package){
  return package->post;
}

void FreePackage(Package * package){
  if(package){
    if(package->like)free(package->like);
    if(package->unlike)free(package->unlike);
    if(package->hobbieChange)free(package->hobbieChange);
    if(package->post)free(package->post);
    free(package);
  }
}
