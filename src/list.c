#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

typedef struct cell Cell;

struct list{
    Cell * first;
    Cell * last;
};

struct cell{
    Cell * next;
    void * element; 
};

//=================================================================//
List * CreateVoidList(){

    List * list = malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;

    return list;
}

//=================================================================//
List * PushList(List * list, void * element){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->element = element;
    newCell->next = NULL;

    if(!list->first){
        list->first = newCell;
        list->last = newCell;
    }
    else{
        list->last->next = newCell;
        list->last = newCell;
    }
    return list;
}

//=================================================================//
void PrintList(List * list, print_list print_callback){

    if(!list) return;

    Cell * current = list->first;

    while(current){
        print_callback(current->element);
        current = current->next;
    }
}

//=================================================================//
void * ListRemove(List * list, list_compare remove_callback, void * key){

    if(!list) return NULL;

    Cell * current = list->first;
    Cell * next = NULL;
    Cell * previous = NULL;

    void * element = NULL;

    while(current){
        
        next = current->next;

        if(remove_callback(current->element, key)){
            
            if(current == list->first){
                list->first = list->first->next;
            }
            else if(current == list->last){
                list->last = previous;
                previous->next = NULL;
            }
            else{
                previous->next = current->next;
            }

            element = current->element;
            free(current);
        }
        previous = current;
        current = next;
    }
    return element;
}

//=================================================================//
void DestructList(List * list){

    Cell * current = list->first;
    Cell * aux;

    if(list){
        while(current){
            aux = current->next;
            free(current);
            current = aux;
        }
        free(list);
    }
}

//=================================================================//
void * GetElement(List * list, list_compare get_callback, void * key){
    if(!list){
        printf("Lista nula!\n");
        return NULL;
    } 

    Cell * current = list->first;
    while(current){

        if(get_callback(current->element, key)){
            return current->element;
        }
        current = current->next;
    }
    return NULL;
}
