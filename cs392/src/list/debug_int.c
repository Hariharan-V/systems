#include "../../include/list.h"
void debug_int(struct s_node* head){
	NODE s = head;
	while(s!=NULL){
		my_str("(");
		if(s->prev ==NULL||s->prev->elem==NULL){
			my_str("NULL");
		}else{
			my_int(*(int*)(s->prev->elem));
		}
		my_str("<-");
		if(s->elem ==NULL){
		  my_str("NULL");
		}else{
		my_int(*(int*)(s->elem));
		}
		my_str("->");
	 if(s->next ==NULL||s->next->elem==NULL){
			my_str("NULL");
		}else{
			my_int(*(int*)(s->next->elem));
		}
	 my_str(") ");
	 s = s->next;
	}

}
