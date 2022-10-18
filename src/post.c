#include "../include/post.h"
#include <string.h>
#include <stdlib.h>

struct post{
  int reach;
  char * author;
  char * content;
};

Post * PostConstructor(char * author, char * content, int reach){

  Post * post = malloc(sizeof(Post));
  post->author = strdup(author);
  post->content = strdup(content);
  post->reach = reach;

  return post;
}

char * GetPostContent(Post * post){
  return post->content;
}

char * GetPostAuthor(Post * post){
  return post->author;
}

int GetPostReach(Post * post){
  return post->reach;
}

void SetPostReach(Post * post, int value){
  post->reach= value;
}

void FreePost(Post * post){
  if(post){
    if(post->author)
      free(post->author);
    if(post->content)
      free(post->content);
    free(post);
  }
}
