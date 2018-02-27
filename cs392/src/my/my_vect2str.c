#include "../../include/my.h"

char *my_vect2str(char **x){
  int len = 0;
  int space = 0;
  if(x==NULL){
    return NULL;
  }
  for(int g = 0; x[g]!=NULL;g++){
    len+=my_strlen(x[g])+1;
    if(x[g+1]!=NULL){
    space++;
    }
  }
  char *c = (char*)malloc(len+space);
  if(x[0]==NULL){
    c = (char*)malloc(1);
    c[0] = '\0';
    return c;
  }
 
  for(int g = 0; x[g]!=NULL;g++){
    my_strcat(c,x[g]);
    if(x[g+1]!=NULL){
    my_strcat(c," ");
    }
  }
  return c;

}
