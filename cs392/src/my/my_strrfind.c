#include "../../include/my.h"                                                    
                                                                              
char* my_strrfind(char* str, char c){                                         
  if(str==NULL){                                                              
    return NULL;                                                              
  }
  int len = my_strlen(str);
	for(int x = len-1; x>=0; x--){
		if(str[x]== c){
			return &str[x];
		}
	}
  return NULL;                                                                 
}                                                                             
    
