CC	:= gcc -std=c99
DEBUG	:=-g  
LDFLAGS	:= $(DEBUG) -I ../include -L../../lib/ -llist -lmy -lncurses

all: mytest

mytest:	nsminishell.c 
	$(CC)   nsminishell.c dynstr.c  $(LDFLAGS) -o nsminishell
re: fclean all
fclean: clean 
	
clean: 
	rm nsminishell
