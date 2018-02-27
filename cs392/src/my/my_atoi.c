#include "../../include/my.h"
#include <assert.h>
int my_atoi(char* str){
	assert(str!=NULL);
	 int number = 0;
	int sign = 1;
	int len = my_strlen(str);
	int x = 0;
	for( x = 0; x<len&&(str[x]>'9'||str[x]<'0');x++){
	  if(str[x]=='-'){
	    sign*=-1;
	  }
	}
	for(int g = x; g<len && str[g]<='9'&&str[g]>='0';g++){
	  number = number*10+(int)(str[g]-'0');
	}
	return sign*number;
}
