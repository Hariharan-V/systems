#include "../../include/my.h"


int my_strrindex(char*c, char x){
	int len = my_strlen(c);
	if(len == -1){return -1;}
	while(len!=0){
		if(c[len-1]==x){return len-1;}
		len--;
	}
	return -1;
}
