#include "../../include/list.h"                                                                                       
void debug_char(struct s_node* head){                                                                                  
  NODE s = head;                                                                                                      
  while(s!=NULL){                                                                                                     
    my_str("(");                                                                                                      
    if(s->prev ==NULL||s->prev->elem==NULL){                                                                                               
      my_str("NULL");                                                                                                 
    }else{                                                                                                            
      my_char(*(char*)(s->prev->elem));                                                                                 
    }                                                                                                                 
    my_str("<-");                                                                   if(s->elem==NULL){
      my_str("NULL");
    }else{                                  
      my_char(*(char*)(s->elem));                                                                             }            
    my_str("->");                                                                                                     
		if(s->next ==NULL||s->next->elem==NULL){                                                                                                
      my_str("NULL");                                                                                                 
    }else{                                                                                                            
      my_char(*(char*)(s->next->elem));                                                                                 
    }                                                                                                                 
		my_str(") ");                                                                                                      
		s = s->next;                                                                                                       
  }                                                                                                                   
                                                                                                                      
}               
