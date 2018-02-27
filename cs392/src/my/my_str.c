#include "../../include/my.h"
void my_str (char* c){
	if(c!=NULL){
		int i = 0;
		while(c[i]!= '\0'){
			my_char(c[i]);
			i++;
		}
	}
}
