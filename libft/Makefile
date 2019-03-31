NAME = libft.a
SRC = ft_putstr.c\
	  ft_strmap.c\
	  digit_test.c\
	  ft_putstr_fd.c\
	  ft_strmapi.c\
	  ft_abs.c\
	  ft_size2d.c\
	  ft_memalloc.c\
	  ft_range.c\
	  free_2d.c\
	  ft_strncat.c\
	  ft_appending_char.c\
	  ft_memccpy.c\
	  ft_sqrt.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_memchr.c\
	  ft_strcat.c\
	  ft_strncpy.c\
	  ft_bzero.c\
	  ft_memcmp.c\
	  ft_strchr.c\
	  ft_strchr_int.c\
	  ft_strnequ.c\
	  ft_digit_size.c\
	  ft_memcpy.c\
	  ft_strclr.c\
	  ft_strnew.c\
	  ft_isalnum.c\
	  ft_memdel.c\
	  ft_strcmp.c\
	  ft_strnstr.c\
	  ft_isalpha.c\
	  ft_memmove.c\
	  ft_strcpy.c\
	  ft_strrchr.c\
	  ft_isascii.c\
	  ft_memset.c\
	  ft_strdel.c\
	  ft_strsplit.c\
	  ft_isdigit.c\
	  ft_pow.c\
	  ft_strdup.c\
	  ft_strstr.c\
	  ft_isprint.c\
	  ft_putchar.c\
	  ft_strequ.c\
	  ft_strsub.c\
	  ft_itoa.c\
	  ft_putchar_fd.c\
	  ft_striter.c\
	  ft_strtrim.c\
	  ft_putendl.c\
	  ft_striteri.c\
	  ft_tolower.c\
	  ft_putendl_fd.c\
	  ft_strjoin.c\
	  ft_toupper.c\
	  ft_putnbr.c\
	  ft_strlcat.c\
	  ft_putnbr_fd.c\
	  get_next_line.c\
	  ft_strlen.c

HDRS = libft.h

all: $(NAME)

$(NAME):
	@gcc -Wall -c -g -Wextra -Werror -I $(HDRS) $(SRC)
	@ar rc $(NAME) *.o

clean:
	@rm -rf *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

