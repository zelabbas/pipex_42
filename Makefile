NAME = pipex

NAME_BONUS = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c utls.c src/ft_check_env.c src/ft_free_memory.c src/ft_split.c \
      src/ft_strncmp.c src/ft_strjoin.c src/ft_strnstr.c

SRCS_BONUS = pipex_bonus.c utls.c src/ft_check_env.c src/ft_free_memory.c src/ft_split.c \
      		src/ft_strncmp.c src/ft_strjoin.c src/ft_strnstr.c utls_bonus.c \
			get_next_line_d/get_next_line_utils.c get_next_line_d/get_next_line.c

all: $(NAME)

OBJS =  $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c ./includes/pipex.h ./includes/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

$(NAME_BONUS) : $(OBJS_BONUS)
		$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

bonus : $(NAME_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : re fclean bonus clean all