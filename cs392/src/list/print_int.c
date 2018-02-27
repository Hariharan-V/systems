#include "../../include/list.h"

void print_int(struct s_node* node){
	if(node==NULL||node->elem==NULL){
		return;
	}
	my_int(*(int*)(node->elem));
	
}
