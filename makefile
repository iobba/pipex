SRCS			= ft_split.c ft_strjoin.c pipex.c pipex_utils.c handle_errors.c

SRCS_B			= ft_split_bonus.c ft_strjoin_bonus.c handle_errors_bonus.c pipex_bonus.c pipex_utils2_bonus.c pipex_utils_bonus.c get_next_line_bonus.c

NAME			= pipex

NAME_B			= pipex_bonus

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

AR				= ar rc 

OBJS			= $(SRCS:.c=.o)
OBJS_B			= $(SRCS_B:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	cc ${CFLAGS} ${OBJS} -o ${NAME}

bonus : $(NAME_B)

$(NAME_B): $(OBJS_B)
	cc ${CFLAGS} ${OBJS_B} -o ${NAME_B}

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all
