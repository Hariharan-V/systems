#include "../../include/my.h"


void my_num_base(int x , char* base){
	int len = my_strlen(base);
	long int j; 
	if(len==-1||len==0){ my_str("error");
	}else if (len==1){
		j = x;
		if(x<0){ j *=-1;  my_char('-');} 
		long int n = 0;
		while(n<j) {my_char(base[0]);n++;}
	}else{
		j = x;
		if(x<0){j*=-1;  my_char('-');}
	 long	int n = 1;
		long int prev = 0;
		long int  y = j;
		
		while(y/len!=0){
			y = y/len;
			n*=len;
		}
		while(n!=0){
			my_char(base[j/n-prev*len]);
			prev = j/n;
			n = n/len;
		}
	}
}
