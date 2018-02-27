#include "../../include/my.h"
char **my_str2vect(char* str){
  int len = my_strlen(str);
  char** vect = (char**)malloc(sizeof(char*)*len);
  int vectcount = 0;
  for(int x = 0; x<len; x++){
    if(str[x]==' '){
      continue;
    }
    if(str[x]=='\n'||str[x]=='\t'){
      continue;
    }
    char *g = &str[x];
    int l = 0;
    while(x<len&&(str[x]!=' '&&str[x]!='\n'&&str[x]!='\t')){
      x++;
      l++;
    }
    char* j = (char*)malloc(l+1);
    my_strncpy(j, g,l);
    j[l] = '\0';
    vect[vectcount] = j;
    vectcount++;
  }
  vect[vectcount]=NULL;
return vect;
}
