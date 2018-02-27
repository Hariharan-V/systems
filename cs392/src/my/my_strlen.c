#include "../../include/my.h"


int my_strlen(char* c){
	if(c==NULL){
		return -1;
	}
	int x = 0;
	while(c[x]!='\0') x++;
	return x;
}
