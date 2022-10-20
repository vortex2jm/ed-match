#ifndef package_h
#define package_h

typedef struct package Package;

Package * PackageConstructor();

char * GetLike(Package * package);

char * GetUnlik(Package * package);

char * GetHobbieChange(Package* package);

char * GetPost(Package * package);

void FreePackage(Package * package);

void PrintPackage(Package * package);

#endif
