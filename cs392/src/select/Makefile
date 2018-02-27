CC	:= gcc -std=c99
DEBUG	:=-g  
LDFLAGS	:= $(DEBUG) -I ../include -L../../lib/ -llist -lmy -lncurses

all: mytest

mytest:	select.c 
	$(CC)   select.c   $(LDFLAGS) -o select2
re: fclean all
fclean: clean 
	
clean: 
	rm select
