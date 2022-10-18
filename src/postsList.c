#include <stdlib.h>
#include <string.h>
#include "../include/postsList.h"

// callback
static int compare_author_name(void * post, void * key){
  char name[50];
  strcpy(name, key); 

  return strcmp(GetPostAuthor(post), name) == 0;
}


List * CreatePostsList(){
  return CreateVoidList();
}

List * PushPostsList(List * list, Post * post){
  return PushList(list, post);
}

Post * PostsListRemove(List * list, char * author){
  return ListRemove(list, compare_author_name, author);
}

void FreePostsList(List * list){
  DestructList(list);
}
