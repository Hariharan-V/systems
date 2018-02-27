CC	:= gcc -std=c99
DEBUG	:=-g  
LDFLAGS	:= $(DEBUG) -I ../include -L../../lib/ -llist -lmy -lncurses

all: mytest

mytest:	minishell.c 
	$(CC)   minishell.c  $(LDFLAGS) -o minishell
re: fclean all
fclean: clean 
	
clean: 
	rm minishell
