#include "../../include/list.h"

void print_char(struct s_node* node){
  if(node==NULL||node->elem==NULL){
    return;
  }
	my_char(*(char*)(node->elem));

}
