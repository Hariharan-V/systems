#include "../../include/list.h"




void* remove_last(struct s_node** s){
	
        if(s==NULL||(*s)==NULL){
	  return NULL;
	}
	NODE x = (*s);
	while(x->next!=NULL){
		x = x->next;
	}
	if(x->prev!=NULL){
	x->prev->next = NULL;
	} else{
		(*s)=NULL;
	}
	void* elem = x->elem;
	free(x);
	return elem;

}
