#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
struct dstr {
  int size;
  int len;
  char* elem;
};
  typedef struct dstr* DSTR;
void dynstr(DSTR str, char x);
DSTR  new_dynstr();
void clear_dynstr(DSTR str);
void backspc_dynstr(DSTR str);
void backspc_at_dynstr(DSTR str,int n);
void cut(DSTR str, DSTR str2, int start, int end);
void dynstr_at(DSTR str, int n, char a);
void insert_str_at(DSTR str1, DSTR str2, int n);
void insertch(DSTR str, int n, char x);
void cpy(DSTR str, DSTR str2);//cpy str into str2
