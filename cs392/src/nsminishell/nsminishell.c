#define _POSIX_SOURCE
#define _BSD_SOURCE
#define READ 0
#define WRITE 1
#include "../../include/my.h"
#include "../../include/list.h"
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
#include "dynstr.h"
pid_t pid;
struct s_node* head = NULL;
struct s_node *current = NULL;
int clipboardflag = 0;
int controluflag = 0;
int controlwflag = 0;
pid_t pid,pid1;
int sigcall = 0;
DSTR clipboard;
DSTR buffer;
int clearflag = 0;
void clipboardcpy(char* text);
void processlauncher(char**argv);
void commandlauncher(char *argv);
void loop();
void ls();
void freevect();
void sigkill(int x);
void signothing(int x);
void chhandler(int x, DSTR input);
int maxy, maxx;
int endx;
int endy;
int cursor;
int lx;
int ly;
int scrlflag = 0;
SCREEN* screen;
 char wdir[4096];
char* historyfile = ".nsmshistory";
FILE *file;
void loadhistory();
void onexit();
void init(){
  clipboard = new_dynstr();
  buffer = new_dynstr();
   initscr();
  start_color();
  //file = fopen("/dev/tty","r+");
  //screen = newterm(NULL,stdout,stdin);
  //set_term(screen);
   init_pair(1,COLOR_WHITE,COLOR_BLACK);
   init_pair(2,COLOR_RED,COLOR_BLACK);
   init_pair(3,COLOR_GREEN,COLOR_BLACK);
   noecho();
   raw();
   nonl();
   keypad(stdscr,TRUE);
  // FILE *f = fopen("/dev/tty","r+");
  // screen = newterm(NULL,f,f);
  // set_term(screen);
  scrollok(stdscr,TRUE);
}
int main(){
  // FILE *f = fopen("/dev/tty","r+");
  // screen = newterm(NULL,f,f);
  //set_term(screen);
  // freopen("/dev/tty/","rw",stdin);
  loadhistory();
  init();
  //scrollok(stdscr,TRUE);
  loop();
  echo();
  endwin();
  //delscreen(screen);
  onexit();
  return 0;
}
void loop(){
  int x,y;
  refresh();
  DSTR input;
  input=new_dynstr();
  char *args;
  char prompt[] = "MINISHELL:";
  char *commands[]= {"cd","exit","help"};
  char **vect;
  
  getcwd(wdir, 500);
  
  while(1){
    if(!clearflag){
      cursor = 0;
    }else{
      
    }
    
    attron(COLOR_PAIR(2));
    
    refresh();
    getmaxyx(curscr,maxy,maxx);
    //input = NULL;
     getyx(curscr,y,x);
    refresh();
     getyx(curscr,y,x);
     if(scrlflag==0){
       move(y+1,0);}else{
       move(maxy-1,0);
     }
    refresh();
    signal(SIGINT,signothing);
    if(sigcall==1){
      sigcall =0;
      printw("\n");
      continue;
    }
    printw(prompt);
   printw(" ");
	   attron(COLOR_PAIR(3));
   printw(wdir);
    printw("$:");
    addch(' ');
    refresh();
	   attron(COLOR_PAIR(1));
    getyx(curscr,y,x);
    endx = x;
    endy = y;
    
    //memset(input,0,255);
    int ch=0;
    if(!clearflag){
    lx = endx;
    ly = endy;
    }else{
      clearflag = 0;
      ly = endy+ly;
      cursor = input->len;
    }
    if(input->elem!=NULL){
      printw(input->elem);
    }
    while(ch!=13){
      ch = getch();
      chhandler(ch,input);
      refresh();
      if(clearflag){
	//clearflag = 0;
	break;
      }
    }
    clear_dynstr(buffer);
    current = NULL;
    refresh();
    if(clearflag){
      continue;
    }
   
    refresh();
    
    //getstr(input);
   
   /* if(sigcall ==1){
     sigcall = 0;
     continue;
     }*/
    
    if(input->elem==NULL||input->len==0){
      int k,j;
  getyx(curscr,k,j);
  if(k==maxy-1){
    scrlflag = 1;
    scrl(1);
  }
      continue;
    }
    char* string = (char*)malloc(input->len);
    my_strcpy(string,input->elem);
    add_elem(string,&head);
    move(endy+1,0);
    vect = my_str2vect(input->elem);
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
      int k,j;
      getyx(curscr,k,j);
      if(k==maxy-1){
	scrl(1);
      move(k,0);
      }else{
	move(k+1,0);
      }
      refresh();
      if(x==-2){
       
	addstr("no arguments\n");
      }
      if(x ==-1){
       addstr("file not found\n");
      }
      getcwd(wdir,4096);
      free(vect);
      clear_dynstr(input);
      getyx(curscr,k,j);
  if(k==maxy-1){
    scrlflag = 1;
    scrl(1);
  }
      continue;
    }
    if(my_strncmp(vect[0],"./",2)==0){
      
       processlauncher(vect);
      free(vect);
      clear_dynstr(input);
      continue;
    }
    if(my_strcmp(vect[0],commands[2])==0){
      freevect(vect);
     printw("HELP: This minishell was created because......cs392 :(\n");
      printw("commands:\n");
      printw("ls [no arg] [directory]      cd [directory]\n");
      
      printw("exit                         help\n");
      refresh();
      clear_dynstr(input);
      continue;
	
    }
    if(my_strcmp(vect[0],"hello")==0){
      freevect(vect);
      printw("Hello Erlich Bachman, this issa your mom, and you are not my baby\n");
      refresh();
      clear_dynstr(input);
      continue;
    }
    if(my_strcmp(vect[0],"clear")==0){
      clear();
      scrlflag=0;
      freevect(vect);
      clear_dynstr(input);
      continue;
    }
    commandlauncher(input->elem);
    freevect(vect);
    clear_dynstr(input);
    // my_str("this issa wrong command, please try again (to be read by Jian Yang from silicon valley in V 2.0)\n");
    getyx(curscr, y,x);
    if(y==maxy-1){
      scrl(1);
      scrlflag=1;
    }
    continue;
  }
}

void freevect(char**vect){
  for(int x = 0; vect[x]!=NULL; x++){
    free(vect[x]);
  }
}
void commandlauncher(char *argv){
  fflush(stdout);
  fclose(stderr);
  if(my_strlen(argv)==0){return;}
  FILE *fd = popen(argv,"re");
  // fclose(stderr);
  
  int xx,yy;
  refresh();
  getyx(curscr, yy,xx);
  if(yy==maxy-1){
    scrl(1);
    scrlflag = 1;
    move(yy,0);
    refresh();
  }
  getmaxyx(curscr,yy,xx);
  int x , y;
  char s[xx];
  char *l;
  int g = 0;
  refresh();
  getyx(curscr,y,x);
  y = ly+1;
   move(y,0);
  while((l=fgets(s,xx,fd))!=NULL){
    refresh();
    getyx(curscr,y,x);
    wmove(curscr,y+1,0);
    addstr(s);
    
    refresh();
    g++;
    
  }
  if(g==0){
    
    
    move(y,0);
    printw("this issa wrong command, please try later (read by jian yang)");
    refresh();
  }
  pclose(fd);
  int k,j;
  getyx(curscr,k,j);
  if(k==maxy-1){
    scrlflag = 1;
    scrl(1);
  }

}

void processlauncher(char**argv){
   
  int out[2];
  int in[2];
  int c = pipe(out);
  int d = pipe(in);
  pid = fork();
  if(pid<0){
    printw("fork failed");
    return;
  }
  if(pid==0){
   
    close(out[0]);
    dup2(out[1],1);
    close(in[1]);
    //dup2(in[0],STDIN_FILENO);
    if( execvp(argv[0],argv)==-1){
      write(out[1],"file not found",15);
    }
    write(out[1],"\f",3);
  }else{
    
    char readd[256];
    close(out[1]);
    int s;
    close(in[0]);
    /* fd_set set;
    FD_ZERO(&set);
    FD_SET(out[0],&set);
    FD_SET(0,&set);
    //int n = out[0]+1;;
    int l;
    int status;*/
    // pid_t result = waitpid(pid,&status,WNOHANG);
    /*while(result==0&&select(n,&set,NULL,NULL,NULL)>=0){
     
      if(FD_ISSET(out[0],&set)){
	int d = 0;
	FD_ZERO(&set);
	FD_SET(out[0],&set);
	FD_SET(0,&set);
	 while((s=read(out[0],readd,255))>0){
	readd[s]='\0';
	printw(readd);
	if(s==1&&readd[0]=='\f'){
	  d = 1;
	  break;
	}
	refresh();
	 }
	 if(d==1){
	   break;
	 }
	
      }else if(FD_ISSET(0,&set)){
	FD_SET(out[0],&set);
	FD_SET(0,&set);
	char b[256];
	  int f = 0;
	while((f=read(0,b,255))!=0){
	    b[f]='\0';
	write(in[1],b,f);
	  }
	
      }
      result = waitpid(pid,&status,WNOHANG);
    }*/
    
    // while(result==0){
      while((s=read(out[0],readd,255))>0){
	 
	readd[s]='\0';
	if(readd[0]=='\f'){
	  if(pid!=0){
	  kill(pid,SIGKILL);
	  }
	}
	printw(readd);
	refresh();
        
   
       }
      //result = waitpid(pid,&status,WNOHANG);
      //if(result!=0){
      //break;
      // }
      /*while(l!=13){
	  l = getch();
	  char c = (char)l;
	  write(in[1],&(c),1);
      }
      result = waitpid(pid,&status,WNOHANG);
      }*/
      close(in[1]);
      close(out[0]);
    wait(NULL);
  }
  int k,j;
  getyx(curscr,k,j);
  if(k==maxy-1){
    scrlflag = 1;
    scrl(1);
  }
}

void sigkill(int x){
  kill(getpid(),SIGINT);
}
void signothing(int x){
  signal(SIGINT,signothing);
  fprintf(stdout,"^C\n");
  if(pid>0){
    wait(NULL);
  }
  sigcall = 1;//continue;
}
//struct s_node *current = NULL;
void  chhandler(int x,DSTR input){
  //struct s_node *current = NULL;
  //cpy(input,buffer);
  int xx, yy;
  if(x!=23){
    controlwflag = 0;
  }
  if(x==KEY_UP){
    if(current ==NULL){
      current = head;
      clear_dynstr(buffer);
      cpy(input,buffer);
    }else{
      if(current->next!=NULL){
      current = current->next;
      }
    }
    if(current==NULL||current->elem==NULL){
      return;
    }
    move(ly,lx);
    refresh();
    
    cursor = input->len;
    while(cursor!=0){
      cursor--;
      if(lx==0){
	lx = maxx-1;
	ly--;
      }else{
	lx--;
      }
      move(ly,lx);
      delch();
    }
    refresh();
    clear_dynstr(input);
    int len = my_strlen(current->elem);
    for(int i = 0; i<len;i++){
      dynstr(input,((char*)(current->elem))[i]);
    }
    move(endy,endx);
    addstr(input->elem);
    cursor = input->len;
    refresh();
    getyx(curscr,ly,lx);
    refresh();
  }else  if(x==KEY_DOWN){
    if(current==NULL){
      return;
    }
    
     move(ly,lx);
    refresh();
    
    cursor = input->len;
    while(cursor!=0){
      cursor--;
      if(lx==0){
	lx = maxx-1;
	ly--;
      }else{
	lx--;
      }
      move(ly,lx);
      delch();
    }
    refresh();
    clear_dynstr(input);
    if(current == head){
      current = NULL;
      cpy(buffer,input);
      
    }else{
      current = current->prev;
    int len = my_strlen(current->elem);
    for(int i = 0; i<len;i++){
      dynstr(input,((char*)(current->elem))[i]);
    }
    }
    move(endy,endx);
    addstr(input->elem);
    cursor = input->len;
    refresh();
    getyx(curscr,ly,lx);
    refresh();
  }else if(x==KEY_LEFT){
    refresh();
    getyx(curscr, yy,xx);
    if(xx>endx&&yy==endy){
      move(yy,xx-1);
      cursor--;
    }else if(yy>endy){
      if(xx==0){
	move(yy-1,maxx-1);
	cursor--;
      }else{
	move(yy,xx-1);
	cursor--;
      }
    }
    refresh();
    
  }else if(x==KEY_RIGHT){
     refresh();
     getyx(curscr,yy,xx);
     if((lx!=xx&&yy!=ly)||(lx==xx&&ly!=yy)||(lx!=xx&&ly==yy)){
       if(xx!= maxx-1){
       move(yy,xx+1);
       cursor++;
       refresh();
       }else{
	 move(yy+1,0);
	 cursor++;
	 refresh();
       }
     }
     refresh();
     
  }else if(x==KEY_BACKSPACE){
    refresh();
    if(cursor ==0){
      return;
    }
    getyx(curscr,yy,xx);
    cursor--;
    backspc_at_dynstr(input,cursor);
    if(xx==0){
      move(yy-1,maxx-1);
    }else {
      move(yy,xx-1);
    }
    delch();
    if(lx!=0){
      lx--;
    } else{
      ly--;
      lx = maxx-1;
    }
  }else if (x==13||x==10){
    
  }else if(x=='\f'){//ctrl L
    clear();
    clearflag = 1;
    scrlflag = 0;
    ly = ly-endy;
    return;
  }else if (x==1){//ctrl A {
	refresh();
	
	move(endy,endx);
	refresh();
  }else if(x==3){
    // kill(pid,SIGINT);
    return;
  }else if(x==5){//ctrl E
    refresh();
    move(ly,lx);
    cursor = input->len;
  }else if(x==(int)'\t'){
    return;
  }

  else if(x==23){//ctrl W
    refresh();
    if(cursor ==0){
      return;
    }
    if(controluflag){
      controluflag = 0;
      clear_dynstr(clipboard);
    }
    if(!controlwflag){
      clear_dynstr(clipboard);
    }else{
      //dynstr_at(clipboard,0,' ');
    }
    getyx(curscr, yy,xx);
    cursor--;
    int tempcursor = cursor;
    while(cursor!=0&&!(input->elem[cursor]!=' '&&input->elem[cursor-1]==' ')){
      cursor--;
    }
    cut(input,clipboard,cursor,tempcursor);
    /*if(cursor!=0){
      cursor--;
      }*/
    while(tempcursor!=0){
      refresh();
      if(xx!=0){
	move(yy,xx-1);
      }else{
	clrtoeol();
	move(yy-1,maxx-1);
	
	
      }
      
      refresh();
      delch();
      tempcursor--;
      getyx(curscr,yy,xx);
    }
    move(yy,xx-1);
    delch();
    move(endy,endx);
    addstr(input->elem);
    refresh();
    getyx(curscr,ly,lx);
    move(endy,endx);
    xx = endx;
    yy = endy;
    for(int i = 0; i<cursor;i++){
      if(xx==maxx-1){
	xx = 0;
	yy++;
      }else{
	xx++;
      }

    }
    move(yy,xx);
    refresh();
    controlwflag = 1;
  }else if(x==21){//ctrl u
    int tempflag = 0;
    refresh();
    if(cursor==0){
      return;
    }
    if(controluflag||controlwflag||clipboard->len!=0){
      controluflag = 0;
      controlwflag = 0;
      clear_dynstr(clipboard);
    }
    cursor--;
    cut(input,clipboard,0,cursor);
    getyx(curscr,yy,xx);
    while(cursor!=0){
      refresh();
      if(xx!=0){
	move(yy,xx-1);
      }else{
	clrtoeol();
	move(yy-1,maxx-1);
	
	tempflag = 1;
      }
      if(lx!=0){
	lx--;
      }else{
	ly--;
	lx = maxx-1;
      }
      refresh();
      delch();
      cursor--;
      getyx(curscr,yy,xx);
    }
    move(yy,xx-1);
    delch();
    if(lx!=0){
	lx--;
      }else{
	ly--;
	lx = maxx-1;
      }
    if(tempflag==1){
      addstr(input->elem);
    }
    move(endy,endx);
    refresh();
    controluflag = 1;  
 }else if(x==25){//ctrl y
    int tcur = cursor;
    
    int temp = input->len;
    insert_str_at(input,clipboard,cursor);
    move(ly,lx);
    refresh();
    getyx(curscr,yy,xx);
    while(yy!=endy){
      clrtoeol();
      yy = yy-1;
      move(yy,maxx-1);
      
    }
    xx = maxx-1;
    while(xx>=endx){
      move(endy,xx);
      xx--;
      delch();
    }
    move(endy,endx);
    printw(input->elem);
    refresh();
    getyx(curscr,yy,xx);
    lx = xx;
    ly = yy;
    cursor = tcur+clipboard->len;
    move(endy,endx+cursor);
  }else{
    cursor++;
    if(cursor>input->len){
      addch(x);
      dynstr(input,(char)x);
      refresh();
      getyx(curscr, ly,lx);
      
      
    }else{
      cursor--;
      insch(x);
      dynstr_at(input,cursor,x);
      cursor++;
      getyx(curscr,yy,xx);
     
      if(xx==maxx-1){
	yy++;
	xx = 0;
      }else{
	xx++;
      }
      move(yy,xx);
      for(int counter = cursor; counter<input->len; counter++){
	addch(input->elem[counter]);
	
      }
      move(yy,xx);
      if(lx==maxx){
	ly++;
	lx = 0;
      }else{
	lx++;
      }
      //insertch(input,cursor-1,(char)x);
    }
  }

}

void loadhistory(){
  int fd = open(historyfile,O_RDONLY);
  if(fd==-1){
    char * g = strerror(errno);
    return;
  }
  DSTR buf = new_dynstr();
  char x;
  int s;
  while((s = read(fd,&x,1))!=0){
    if(x!='\f'){
      dynstr(buf,x);
    }else{
      char * str = (char*)malloc(buf->len+1);
      my_strcpy(str,buf->elem);
      append(new_node(str,NULL,NULL),&head);
      clear_dynstr(buf);
    }
    
  }
  close(fd);
  remove(historyfile);


}

void onexit(){
  int fd = open(historyfile,O_WRONLY|O_CREAT,0644);
  if(fd==-1){
    return;
  }
  int size = count_s_nodes(head);
  struct s_node *node;
  for(int x = 0; x<size;x++){
    node = node_at(head,x);
    write(fd,node->elem,my_strlen(node->elem));
    write(fd,"\f",1);

  }
  close(fd);
  empty_list(&head);
}
