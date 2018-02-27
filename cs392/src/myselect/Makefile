CC	:= gcc -std=c99
DEBUG	:=-g  
LDFLAGS	:= $(DEBUG) -I ../include -L../../lib/ -llist -lmy -lncurses

all: mytest

mytest:	myselect.c 
	$(CC)   myselect.c   $(LDFLAGS) -o myselect
re: fclean all
fclean: clean 
	
clean: 
	rm myselect
