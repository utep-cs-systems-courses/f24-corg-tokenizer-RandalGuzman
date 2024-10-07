#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {  //initialize the linked list to keep the history
  List *list = (List *)malloc(sizeof(List));  //allocates memory for history list
  list->root = NULL;  //root is null
  return list;  //returns the initialized list
}

void add_history(List *list, char *str) {  //adds a history item to the end of the list
  Item *new_item = (Item *)malloc(sizeof(Item));  //allocccates memory for new item
  new_item->str = str;  //stores the input string
  new_item->next = NULL;  //last item, next will be null

  if (list->root == NULL) {  //if the list if empty, set the new item as root
    new_item->id = 1;  //first item has id 1
    list->root = new_item;  //sets the root to new item
  } else {
    Item *current = list->root;  //traverses to end of the list
    while (current->next != NULL) {
      current = current->next;  //moves to next item
    }
    new_item->id = current->id + 1;  //increments id
    current->next = new_item;  //links the new item
  }
}

char *get_history(List *list, int id) {  //get history by the id
  Item *current = list->root;  
  while (current != NULL) {  //finds the item with specific id
    if (current->id == id) {
      return current->str;  //returns the string if found
    }
    current = current->next;  //moves to the next item
  }
  return NULL;  //returns null if not found
}

void print_history(List *list) {  //prints the entire history
  Item *current = list->root;
  while (current != NULL) {  //traverse the list and prints each item
    printf("%d: %s\n", current->id, current->str);  //prints the id and string
    current = current->next;  //moves to the next item
  }
}

void free_history(List *list) {  //free the history and strings
  Item *current = list->root;  
  while (current != NULL) {  //traverse the list and free items
    Item *temp = current;  //stores the current item
    current = current->next;  //moves to the next item
    free(temp);  //free the current item
  }
  free(list);  //free the list
}
