#ifndef postslist_h
#define postslist_h
#include "list.h"
#include "post.h"

List * CreatePostsList();

List * PushPostsList(List * list, Post * post);

Post * PostsListRemove(List * list, char * author);

void FreePostsList(List * list);

void SetAllPostsReach(List * list, int value);

void PrintPostsList(List * list);

#endif
