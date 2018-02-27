#include "../../include/list.h"


void* remove_node_at(struct s_node** head, int n){
  if(head ==NULL){
    return NULL;
  }
	NODE node = (*head);
	if(node==NULL){
	  return NULL;
	}
	if(n<=0){
		return remove_node(head);
	}
	for(int x = 0; x<n&&node->next!=NULL;x++){
		node  = node->next;
	}
	NODE prev = node->prev;
	NODE next = node->next;
	if(prev!=NULL){
	prev->next = next;
	}
	if(next!=NULL){
		next->prev = prev;
	}
	void * elem = node->elem;
	if((*head)==node){
	  (*head)=NULL;
	}
	free(node);
	node = NULL;
	return elem;

}
