#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) 
{
  struct list_node* new = malloc(sizeof(struct list_node));
  new -> next = NULL;
  new -> value = value;
  return new;
}

void insert_at_head(struct linked_list *list, size_t value) 
{
  struct list_node *in = new_node(value);
  in -> next = list -> head;
  list -> head = in;
}

void insert_at_tail(struct linked_list *list, size_t value) 
{
  struct list_node *end = list -> head;
  while((end -> next) != NULL)
  {
    end = end -> next;
  }
  end -> next = new_node(value);
}

size_t remove_from_head(struct linked_list *list) 
{
  struct list_node *q = list -> head; 
  list -> head = list -> head -> next;
  free(q);
  return list -> head -> value; 
}

size_t remove_from_tail(struct linked_list *list) 
{
  struct list_node *p = list -> head;  
  struct list_node *q = p -> next;
  while((q -> next) != NULL)
  {
    q = q -> next;
    p = p -> next;
  }
  p -> next = NULL;
  free(q); 
  return p -> value; 
}

void free_list(struct linked_list list) {}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
