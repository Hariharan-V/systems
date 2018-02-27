CC      := gcc -std=c99                                                                
DEBUG   :=-g                                                                     
LFLAGS :=  -Wall -Werror --pedantic -L../../lib/ -lmy
SOURCES:= new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_last.c remove_node_at.c count_s_nodes.c empty_list.c node_at.c elem_at.c traverse_int.c traverse_char.c traverse_string.c debug_int.c debug_char.c debug_string.c print_int.c print_char.c print_string.c arraylist.c
OBJ:= new_node.o add_node.o add_elem.o append.o add_node_at.o remove_node.o remove_last.o remove_node_at.o count_s_nodes.o empty_list.o node_at.o elem_at.o traverse_int.o traverse_char.o traverse_string.o debug_int.o debug_char.o debug_string.o print_int.o print_char.o print_string.o arraylist.o
all: $(SOURCES)
	$(CC) $(DEBUG)  $(LFLAGS) -c $(SOURCES)
	ar -rc liblist.a $(OBJ)
	ranlib liblist.a
	mv liblist.a ../../lib
re: fclean all
fclean: clean 
	rm -f ../../lib/liblist.a
clean: 
	rm -f $(OBJ)

