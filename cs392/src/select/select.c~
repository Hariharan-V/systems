#include "../../include/my.h"
//#include "../../include/list.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <string.h>
#include <ncurses.h>
#include <stdio.h>
#include <errno.h>
#include <sys/select.h>
int flag = 0;
int ceildiv(int x, int y){
  double j = x;
  double k = y;
  if(j/k>0.0){
    return (x/y)+1;
  }
  return x/y;
}
int numstr = 0;
int main(int argc, char **argv){
  if(argv[1]==NULL){
    my_str("Usage: ./myselect [DIRECTORY] * or ./myselect *\n or ./myselect [string args]\n");
    return 0;
  }
  // char *string = my_vect2str(&argv[1]);
  initscr();
  noecho();
  raw();
  nonl();
  keypad(stdscr,TRUE);
  int cursor = 2;
  int highlight[argc];
  for(int i = 0;i<argc;i++){
    highlight[i]=0;
  }
  
  
  //highlight[12]=0;
  // printf("%i",argc);
  curs_set(0);
  //int underline = 0;
  int len;// my_strlen(string);
  int xx,yy;
  int maxx,maxy;
  int  maxlen = 0;
  
  while(1){
  refresh();
  clear();
  getmaxyx(curscr,maxy,maxx);
  int col = 0;
  for(int x = 2;x<argc;x++){
    len =my_strlen(argv[x]);
    if(maxlen<len){
      maxlen =len;
    }      
  }
  col = ceildiv(argc-1,maxy);
  if(col*maxlen+col-1>maxx){
    clear();
    refresh();
    move(0,0);
    
    printw("enlarge screen pls");
    continue;
  }
  
  move(0,0);
  xx = 0; yy=0;
  for(int x = 2;x<argc;x++){
    refresh();
    
    move(yy,xx);
    if(cursor==x){
      attron(A_UNDERLINE);
      
      
    }
    if(highlight[x]==1){
      attron(A_STANDOUT);
    }
    addstr(argv[x]);
    attroff(A_UNDERLINE);
    attroff(A_STANDOUT);
    yy++;
    if(yy==maxy){
      yy = 0;
      xx += maxlen;
    }

  }
  int c = getch();
  //int c = (int)d;
  if(c==27){
    break;
  }
  if(c==KEY_DOWN){
    cursor++;
    if(cursor!=argc&&cursor>maxy&&cursor%maxy==1){
      cursor-=maxy;
      
    }
    if(cursor==argc){
      if(argc-1==maxy){
	cursor-=maxy;
      }else{
	cursor-=argc%maxy;
	cursor++;
      }
      
    }
    
  }
  if(c==KEY_UP){
    cursor--;
    
    if(cursor==1||(cursor>=maxy&&cursor%maxy==0)){
      cursor+=maxy;
      if(cursor>argc-1){
	cursor = argc-1;
      }
    }
  }
  if(c==(int)' '){
    if(highlight[cursor]==0){
      numstr++;
      highlight[cursor]=1;
    }else
    if(highlight[cursor]==1){
      highlight[cursor]=0;
      numstr--;
    }
    
  } 
  if(c==KEY_RIGHT){
    if( cursor+maxy<argc){
      cursor+=maxy;
    }
    
  }
  if(c==KEY_LEFT){
    if(cursor-maxy>0){
      cursor-=maxy;
    }
  }
  if(c==13){
  flag = 1;
   break;
   }
  }
  endwin();
  char * arg[numstr+2];
  arg[numstr+1] = NULL;
  int counter = 1;
  if(flag == 1){
    for(int x = 2;x<argc;x++){
      if(highlight[x]==1){
	arg[counter]= my_strdup(argv[x]);
	counter++;
      }
    }
  
  }
  arg[0]= strdup(argv[1]);
  execvp(arg[0],arg);
  return 0;
}
