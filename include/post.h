#ifndef post_h
#define post_h

typedef struct post Post;

Post * PostConstructor(char * author, char * content, int reach);

char * GetPostAuthor(Post * post);

char * GetPostContent(Post * post);

int GetPostReach(Post * post);

void SetPostReach(Post * post, int value);

void FreePost(Post * post);

#endif
