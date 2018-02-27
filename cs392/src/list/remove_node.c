#include "../../include/list.h"


void* remove_node(struct s_node** node){
  if(node ==NULL){
    return NULL;
  }
	NODE n = *node;
	if(n==NULL){
	  return NULL;
	}
	NODE prev = n->prev;
	NODE next = n->next;
	
	if(prev!=NULL){
	prev->next = next;
	}
	if(next!= NULL){
	next->prev = prev;
	}
	if(prev==NULL){
		(*node) = next;
	}
	void* l = n->elem;
	free(n);
	(n)=NULL;
	
	return l;



}
