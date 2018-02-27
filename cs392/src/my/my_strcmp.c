#include "../../include/my.h"

int my_strcmp(char *a, char *b){
     
	if(a==NULL && b==NULL){
	  return 0;
	}
	if(a==NULL){
	  return -1;
	}
	if(b==NULL){
	  return 1;
	}
	for(int x = 0; a[x]!='\0'||b[x]!='\0'; x++){
	  if(a[x]!=b[x]){
	    return (int)a[x]-(int)b[x];
	   }
	}
        return 0;
}
