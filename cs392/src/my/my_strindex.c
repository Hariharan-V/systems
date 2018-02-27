#include "../../include/my.h"

int my_strindex(char*c, char x){
	int len = my_strlen(c);
	if(len== -1){return -1;}
	for(int n= 0; n<len;n++){
		if(c[n]==x){return n;}
	}
	return -1;
}
