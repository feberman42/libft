NAME = libft

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c\
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
		ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_memcmp.c
BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

.PHONY: all clean fclean re bonus test

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME).a $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME).a
	rm -f program
	rm -f bonus

re: fclean all

bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME).a $(OBJS) $(BOBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

test: re
	$(CC) $(CFLAGS) test.c -o program libft.a

testbonus: fclean bonus
	$(CC) $(CFLAGS) bonus.c -o bonus libft.a
