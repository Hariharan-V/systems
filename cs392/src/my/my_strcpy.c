#include "../../include/my.h"


char *my_strcpy(char *dst, char *src){
	if(dst==NULL){
		return NULL;
}
	if(src==NULL){
		return dst;
}
	
	//int dstlen = my_strlen(dst);
	int len = my_strlen(src);
	for(int x = 0; x<len+1; x++){
		dst[x]=src[x];
	}
	
	return dst;
}
