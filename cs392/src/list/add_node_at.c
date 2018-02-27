#include "../../include/list.h"

void add_node_at(struct s_node* node, struct s_node** head, int n){
	if(node==NULL||head==NULL){

		return;
	}
	if(n<=0||(*head)==NULL){
		add_node(node,head);
		return;
	}
	NODE prev = *head;

	for(int x = 1; x<n; x++){
		if(prev->next==NULL){
			break;
		}
		prev = prev->next;
		
	}
	
	NODE next = prev->next;
	node->prev = prev;
	prev->next = node;
	if(next!=NULL){
	node->next = next;
	next->prev = node;
	}

} 

