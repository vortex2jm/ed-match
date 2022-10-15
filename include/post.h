#ifndef post_h
#define post_h

typedef struct post Post;

Post * PostConstructor(char * author, char * content, int reach);

char * GetPostContent(Post * post);

int GetPostReach(Post * post);

void FreePost(Post * post);

#endif
