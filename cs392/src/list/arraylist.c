#include "../../include/my.h"
#include "../../include/list.h"

void  arraylist_add(char*x,struct s_node **head ){
  char *y = (char*)malloc(256);
  my_strncpy(y,x,256);
  append(new_node(y,NULL,NULL),head);
}

void arraylist_print(struct s_node **head){
  if(head==NULL){
    return;
  }
  if(*head == NULL){
    return;
  }
  NODE s = *head;
  while(s!=NULL){
    my_str(s->elem);
    s = s->next;
  }
}
void empty_str(char *x){
  for(int g = 0; g<256;g++){
    free(&x[g]);
  }
}
void arraylist_empty(struct s_node **head){
  if(head ==NULL){
    return;
  }
  while(*head!=NULL){
    empty_str(remove_last(head));
	    }
}
