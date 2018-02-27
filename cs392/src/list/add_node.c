#include "../../include/list.h"                                                                                       
//typedef struct s_node* node; 

void add_node(struct s_node* node, struct s_node** head){
	if(node==NULL||node->elem ==NULL||head==NULL){
		return;
	}

	node->prev = NULL;
	node->next = (*head);
	if(node->next!=NULL){
	node->next->prev = node;
	}
	(*head) = node;
	
}
