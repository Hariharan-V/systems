#include "../../include/list.h"

void traverse_char(struct s_node* head){
	NODE s = head;
	while(s!=NULL){
	  if(s->elem!=NULL){
		my_char(*(char*)s->elem);
	  }else{
	    my_str("NULL");
	  }
		my_char(' ');
		s = s->next;
	}


}
