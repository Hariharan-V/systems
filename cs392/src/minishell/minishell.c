#define _POSIX_SOURCE
#include "../../include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
pid_t pid,pid1;
int sigcall = 0;
void processlauncher(char**argv);
void commandlauncher(char**argv);
void loop();
void ls();
void freevect();
void sigkill(int x);
void signothing(int x);
int main(){
  loop(); 
  return 0;
}
void loop(){
  char input[256];
  char *args;
  char wdir[4096];
  char prompt[] = "MINISHELL:";
  char *commands[]= {"cd","exit","help"};
  char **vect;
  getcwd(wdir, 500);
  
  while(1){
    signal(SIGINT,signothing);
    my_str(prompt);
    my_str(" ");
    my_str(wdir);
    my_str("$:");
  
   int readbyte =  read(0,input,256);
   input[readbyte]='\0';
   if(sigcall ==1){
     sigcall = 0;
     continue;
   }
    vect = my_str2vect(input);
    if(vect[0]==NULL){
      continue;
    }
    if(my_strcmp(vect[0],commands[1])==0){
      freevect(vect);
      //kill(getpid(),SIGKILL);
      break;
    }
    
    if(my_strcmp(vect[0],commands[0])==0){
      int x;
      x = (vect[1]==NULL)?-2: chdir(vect[1]);
      if(x==-2){
	my_str("no arguments\n");
      }
      if(x ==-1){
	my_str("file not found\n");
      }
      getcwd(wdir,4096);
      free(vect);
      continue;
    }
    if(my_strncmp(vect[0],"./",2)==0){
       processlauncher(vect);
      free(vect);
      continue;
    }
    if(my_strcmp(vect[0],commands[2])==0){
      freevect(vect);
      my_str("HELP: This minishell was created because......cs392 :(\n");
      my_str("commands:\n");
      my_str("ls [no arg] [directory]      cd [directory]\n");
      
      my_str("exit                         help\n");
      continue;
	
    }
    if(my_strcmp(vect[0],"hello")==0){
      freevect(vect);
      my_str("Hello Erlich Bachman, this issa your mom, and you are not my baby\n");
      continue;
    }
    commandlauncher(vect);
    freevect(vect);
    
    // my_str("this issa wrong command, please try again (to be read by Jian Yang from silicon valley in V 2.0)\n");
    continue;
  }
}

void freevect(char**vect){
  for(int x = 0; vect[x]!=NULL; x++){
    free(vect[x]);
  }
}
void commandlauncher(char** argv){
  pid1 = fork();
  if(pid1==0){
    if(execvp(argv[0],argv)==-1){
      my_str("this issa wrong command, please try again (to be read by Jian Yang from silicon valley in V 2.0)\n");
      kill(getpid(),SIGKILL);
    }
  }else if(pid1>0){
    wait(NULL);
  }

}

void processlauncher(char**argv){
 /* pid_t pid; */
  // signal(SIGINT, sigkill);
   pid=fork();
  if(pid==0){
    //signal(SIGINT, sigkill);
    if(execvp(argv[0],argv)==-1){
      my_str("error, file not found\n");

      kill(getpid(),SIGKILL);
    }
    /*  */
  }else if(pid>0) {
    wait(NULL);
  }

}

void sigkill(int x){
  kill(getpid(),SIGINT);
}
void signothing(int x){
  signal(SIGINT,signothing);
  my_str("\n");
  if(pid>0){
    wait(NULL);
  }
  sigcall = 1;//continue;
}
