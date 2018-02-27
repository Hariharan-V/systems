#include "../../include/my.h"

char *my_strcat(char *dst, char *src) {
	if(src==NULL){
		return dst;
	}
	if(dst==NULL){
		return NULL;
	}
	//char * d;
	//d = dst;
	int dstindex =  my_strlen(dst);
	int len = my_strlen(src);
	for(int x = 0; x<len;x++){
		dst[dstindex+x] = src[x];
		
	}
	dst[dstindex+len]='\0';
	return dst;

}
