#include "../../include/list.h"

int count_s_nodes(struct s_node* head){
	int x = 0;
	
	for(NODE n = head; n!=NULL; n=n->next){

		x++;
	}
 
	return x;			


}
