#include "../../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
  pid_t child;
  int fd[2];
  char *x;
 x = (char*)my_vect2str(&argv[1]);
  if(x==NULL){
    my_str("Usage: ./pipes [string]..[string]....\n");
    return 0 ;
  }
 
  my_str("Parent: ");
  my_str(x);
  my_str("\n");
  if(pipe(fd)<0){
      my_str("pipe failed\n");
      return 1;
  }
  write(fd[1],x,my_strlen(x)+1);
  if((child=fork())<0){
    my_str("error\n");
    return 1;
  }else if(child ==0){
    char y[100];
    read(fd[0],y,100);
    my_str("Child: ");
    my_str(y);
    my_str("\n");
    close(fd[0]);
    close(fd[1]);
    int fd2[2];
    if(pipe(fd2)<0){
      my_str("pipe has failed\n");
      return 1;
    }
    write(fd2[1],y,100);
    pid_t grandchild;
    if((grandchild=fork())<-1){
      my_str("error");
      return 1;
    }
    if(grandchild==0){
      //printf("this is the grandchild\n");
      char z[100];
      read(fd2[0],z,100);
      my_str("Grandchild: ");
      my_str(z);
      my_str("\n");
      close(fd2[0]);
      close(fd2[1]);
    }else{
      wait(NULL);
    }
  }else{
    wait(NULL);
  }
  return 0;
}
