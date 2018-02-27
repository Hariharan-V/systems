CC      := gcc -std=c99                                                                
DEBUG   :=-g                                                                    
LFLAGS :=  -Wall -Werror --pedantic
SOURCES:= my_digits.c my_strindex.c my_int.c my_strlen.c my_num_base.c my_strrindex.c my_alpha.c my_revstr.c my_char.c my_str.c my_strfind.c my_strrfind.c my_strcmp.c my_strncmp.c my_strcpy.c my_strcat.c my_strncpy.c my_strdup.c my_strconcat.c my_strnconcat.c my_atoi.c my_vect2str.c my_printf.c my_str2vect.c
OBJ:= my_digits.o my_strindex.o my_int.o my_strlen.o my_num_base.o my_strrindex.o my_alpha.o my_revstr.o my_char.o my_str.o my_strfind.o my_strrfind.o my_strcmp.o my_strncmp.o my_strcpy.o my_strcat.o my_strncpy.o my_strdup.o my_strconcat.o my_strnconcat.o my_atoi.o my_vect2str.o my_printf.o my_str2vect.o
all: $(SOURCES)
	$(CC) $(DEBUG)  $(LFLAGS) -c $(SOURCES)
	ar -rc libmy.a $(OBJ)
	ranlib libmy.a
	mv libmy.a ../../lib
re: fclean all
fclean: clean 
	rm -f ../../lib/libmy.a
clean: 
	rm -f $(OBJ)

