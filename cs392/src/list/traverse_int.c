#include "../../include/list.h"
//#include "../../include/my.h"
void traverse_int(struct s_node* head){
	NODE s = head;
	while( s!=NULL){
	  if(s->elem!=NULL){
	    my_int(*(int*)(s->elem));}else{
	    my_str("NULL");
	  }
		my_char(' ');
		s = s->next;
	}


}
