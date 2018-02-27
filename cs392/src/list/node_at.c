#include "../../include/list.h"

struct s_node* node_at(struct s_node* head, int n){
	n = (n<0)?0:n;
	NODE s = head;
	if(s==NULL){
	  return s; 
	}
	while(s->next!=NULL&&n!=0){
		s= s->next;
		n--;
	}
	return s;
}
