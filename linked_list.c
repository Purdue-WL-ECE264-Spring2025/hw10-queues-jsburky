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
  
  if(list -> head != NULL)
  {
    struct list_node *end = list -> head;
    while((end -> next) != NULL)
    {
      end = end -> next;
    }
    end -> next = new_node(value);
  } 
  else
  {
    list -> head = new_node(value);
  }
}

size_t remove_from_head(struct linked_list *list) 
{
  if(list -> head != NULL)
  {
    struct list_node *q = list -> head; 
    size_t val = q -> value;
    list -> head = list -> head -> next;
    free(q);
    return val;
  }

  else
  {
    return (size_t)-1;
  }
   
}

size_t remove_from_tail(struct linked_list *list) 
{
  if(list -> head != NULL)
  {
    struct list_node *p = list -> head; 
    if(p -> next != NULL)
    {
      while(p -> next -> next != NULL)
      {
        p = p -> next;
      }
      size_t val = p -> next -> value;
      free(p -> next);
      p -> next = NULL;
      return val; 
    }
    else
    {
      size_t val = p -> value;
      list -> head = NULL;
      free(p);
      return val;
    }
  }

  else
  {
    return (size_t)-1;
  }






  // struct list_node *p = list -> head;  
  // if((p -> next) != NULL)
  // {
  //   struct list_node *q = p -> next;
  //   while((q -> next) != NULL)
  //   {
  //     q = q -> next;
  //     p = p -> next;
  //   }
  //   p -> next = NULL;
  //   size_t value = q -> value;
  //   free(q); 
  //   printf("Remove: Q %ld\n", value);
  //  return value;
  // }
  // else
  // {
    
  //   size_t value = p -> value;
  //   list -> head = NULL;
  //   printf("Remove: P %ld\n", value);
  //   free(p);
  //   return(value);
  // } 
}

void free_list(struct linked_list list) 
{
  while(list.head != NULL)
  {
    struct list_node *p = list.head -> next;
    free(list.head);
    list.head = p;
  }
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
