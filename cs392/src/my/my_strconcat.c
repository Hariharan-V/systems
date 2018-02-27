#include "../../include/my.h"
char *my_strconcat(char *a, char *b){
	if(a==NULL&&b==NULL){return NULL;}
	if(a==NULL){return my_strdup(b);}
	if(b==NULL){return my_strdup(a);}
	int len = my_strlen(a)+my_strlen(b);
	char *c = (char*) malloc(len+1);
	my_strcpy(c,a);
	return my_strcat (c,b);

}
