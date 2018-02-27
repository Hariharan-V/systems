#include "../../include/my.h"

int my_revstr(char* s){
	int len = my_strlen(s);
	if(len==-1){return len;}
	char n;
	for(int x = 0; x<len/2;x++){
		n  = s[x];
		s[x]=s[len-1-x];
		s[len-1-x]=n;
	}
	
	return len;
}
