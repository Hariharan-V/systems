#include "../../include/list.h"
//typedef struct s_node* node;
struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
	NODE L = (NODE)malloc(sizeof(struct s_node));
	L->next = next;
	L->prev = previous;
	if(L->prev!= NULL){
	L->prev->next = L;
	}
	if(L->next!=NULL){
	L->next->prev = L;
	}
	L->elem = elem;
	return L;

}
