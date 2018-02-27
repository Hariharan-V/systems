#include "../../include/my.h"

void my_int (int c){
	long int g = c;
	if(c<0){my_char('-');g = -1*g;}
	long int x = 1;
	while(g/(x*10)!=0){
		x=x*10;
	}
	while(x!=0){
		my_char((char)(int)((g/x)+48));
		g%=x;
		x/=10;
	}
}
