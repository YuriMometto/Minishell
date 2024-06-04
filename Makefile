NAME	=	minishell

SRCS	=	main.c        \
		signals.c     \
		environment.c \
		builtins.c    \
		unset.c       \
		cd.c          \
		pwd.c         \
		export.c      \
		errors.c      \
		cleaners.c    \
		utils1.c      \
		utils2.c      \
		utils3.c      \
		utils4.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-g -Wall -Werror -Wextra

RLFLAG	=	-lreadline

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(RLFLAG)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
