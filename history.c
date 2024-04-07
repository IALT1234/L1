#ifndef _HISTORY_
#define _HISTORY_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;

typedef struct s_List {

  struct s_Item *root;


} List;


/* Initialize the linked list to keep the history. */

List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  list->root=NULL;

  return list;
			     
		                                  
}


/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/
void add_history(List *list, char *str){
  Item *newItem = (Item*)malloc(sizeof(Item));
  if(newItem != NULL){
    newItem->id = list->root==NULL ? 1 : list->root->id+1;
    newItem->str = strdup(str);
    newItem->next = NULL;
  }
  if(list->root==NULL){
    list->root = newItem;
    
  }else{
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newItem;
  }
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *temp = list->root;

  while(temp != NULL){
    if(temp->id==id){
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;

}


/*Print the entire contents of the list. */

void print_history(List *list){
  Item *temp = list->root;

  while(temp != NULL){
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}


/*Free the history list and the strings it references. */

void free_history(List *list){
  Item *current = list->root;

  while(current != NULL){
    Item *temp = current;
    current = current->next;
    free(temp->str);
    free(temp);
  }
  free(list);
}


#endif
