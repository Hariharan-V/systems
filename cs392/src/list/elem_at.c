#include "../../include/list.h"

void* elem_at(struct s_node* head, int n){
	n= (n<0)?0:n;
	if(head ==NULL){
	  return NULL;
	}
	NODE s = node_at(head,n);
	return s->elem;

}
