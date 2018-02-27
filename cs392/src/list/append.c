#include "../../include/list.h"

void append(struct s_node* node, struct s_node** head){
	if(node==NULL||node->elem==NULL||head==NULL){
		return;
	}
	NODE n = *head;
	if(*head==NULL){
			(*head) = node;
			node->next = node->prev = NULL;
			return;
}
	while(n->next!=NULL){
		n = n->next;
	}
	n->next = node;
	node->prev = n;
	node->next = NULL;
	
}
