#include "dynstr.h"
DSTR new_dynstr(){
  DSTR new = (DSTR)malloc(sizeof(struct dstr));
  new->size = 0;
  new->len = 0;
  new->elem = NULL;
  return new;
}

void  dynstr(DSTR str, char x){
  if(str->elem==NULL){
    char * string = (char*)malloc(256);
    string[0] = x;
    string[1]='\0';
    str->elem = string;
    str->size = 256;//null terminator included
    str->len = 1;
    return;
  }
  if(((str->len)+1)<str->size){
    str->elem[str->len]= x;
    str->elem[str->len+1]='\0';
    str->len+=1;
    return;
  }else{
   str->elem= realloc(str->elem,str->size+256);
    str->size+=256;
    dynstr(str,x);
  }
}
void clear_dynstr(DSTR str){
  if(str->elem!=NULL){
  memset(str->elem, 0, str->size);
  }
  str->len = 0;
}

void backspc_dynstr(DSTR str){
  if(str->elem!=NULL&&str->len!=0){
  str->elem[str->len-1]='\0';
  str->len--;
  }
}
void backspc_at_dynstr(DSTR str, int n){//"hello" at 1,1 "hllo"
  cut(str,NULL,n,n);
  str->len--;
}
void cut(DSTR str, DSTR str2, int start, int end){//start and end inclusive-> hello
  if(str2!=NULL){
  for(int x = start; x<=end; x++){
    dynstr(str2, str->elem[x]);
    
  }
  }
  char first[start+1];
  my_strncpy(first,str->elem, start);
  char second[str->len-end];
  int y = 0;
  for(int x = end+1; x<str->len;x++){
    second[y]=str->elem[x];
    y++;
    
  }
  second[str->len-end-1] = '\0';
  clear_dynstr(str);
  my_strcat(str->elem,first);
  my_strcat(str->elem, second);
  str->len = my_strlen(str->elem);
  
}
void dynstr_at (DSTR str, int n,char a){//hllo, 2, hlelo,hello e
  if(n<0){
    return;
  }
  if(n>str->len||str->elem==NULL){
    dynstr(str,a);
    return;
  }
  if(str->len+1>=str->size){
    str->elem = realloc(str->elem, str->size+256);
    str->size+=256;
  }
  char first[n+1];
  char second[str->len-n+1];
  my_strncpy(first,str->elem,n);
  //first[n]='\0';
  int y = 0;
  for(int x =n; x<str->len;x++){
    second[y]= str->elem[x];
    y++;
  }
  second[str->len-n]='\0';
  clear_dynstr(str);
  my_strcpy(str->elem, first);
  str->len +=my_strlen(first);
  dynstr(str, a);
  my_strcat(str->elem,second);
  str->len+=my_strlen(second);
} 
void insert_str_at(DSTR str1, DSTR str2, int n){
  for(int x = 0; x<str2->len;x++){
    dynstr_at(str1,n,str2->elem[x]);
    n++;
  }
}
