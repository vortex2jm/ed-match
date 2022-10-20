#ifndef list_h
#define list_h

typedef struct list List;
typedef void (*print_list)(void * element);
typedef int (*list_compare)(void * element, void * key);
typedef void(*set_something)(void * element, void * value);

List * CreateVoidList();

List * PushList(List * list, void * element);

void PrintList(List * list, print_list print_callback);

void * ListRemove(List * list, list_compare remove_callback, void * key);

void * GetElement(List * list, list_compare get_callback, void * key);

void DestructList(List * list);

void SetAllList(List * list, set_something set_callback, void * value);

#endif
