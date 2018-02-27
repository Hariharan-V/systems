#include "../../include/my.h"

char *my_strdup(char *str){
	if(str==NULL){
		return str;
	}
	int len = (my_strlen(str)+1);
	char *n = (char*)malloc(sizeof(char)*len);
	return my_strcpy(n,str);
 

}
