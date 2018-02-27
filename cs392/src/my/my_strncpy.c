#include "../../include/my.h"
//#include <assert.h>

char *my_strncpy(char *dst, char *src, int n){
	//assert(n>=0);
  n = (n>0)?n:0;
	if(dst==NULL){
		return NULL;
}
	if(src==NULL&&n!=0){
	  return dst;
	}
	if(src==NULL||n==0){
	  dst[n]='\0';
		return dst;
}
   
    	
	//int dstlen = my_strlen(dst);
	int len = my_strlen(src);
	for(int x = 0; x<n&&x<len; x++){
		dst[x]=src[x];
	}
	if(n<=len){
	  dst[n]='\0';
	}else{
	  dst[len]='\0';
	}
	return dst;

}
