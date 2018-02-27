CC	:= gcc -std=c99
DEBUG	:=-g  
LDFLAGS	:= $(DEBUG) -I ../include -L../../lib/ -llist -lmy 

all: mytest

mytest:	pipe.c 
	$(CC)   pipe.c  $(LDFLAGS) -o pipes
re: fclean all
fclean: clean 
	
clean: 
	rm pipes
