HEAD = libasm.h
NAME = libasm.a
NASM = nasm -fmacho64
FLAGS = -Wall -Werror -Wextra
SRC = ft_read.s\
		ft_strcmp.s\
		ft_strcpy.s\
		ft_strdup.s\
		ft_strlen.s\
		ft_write.s
OBJ = ft_read.o\
		ft_strcmp.o\
		ft_strcpy.o\
		ft_strdup.o\
		ft_strlen.o\
		ft_write.o

$(NAME): $(SRC)
		$(NASM) ft_read.s -o ft_read.o && $(NASM) ft_strcmp.s -o ft_strcmp.o && $(NASM) ft_strcpy.s -o ft_strcpy.o && $(NASM) ft_strdup.s -o ft_strdup.o && $(NASM) ft_strlen.s -o ft_strlen.o && $(NASM) ft_write.s -o ft_write.o
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re