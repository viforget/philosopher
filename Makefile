NAME = philo

FLAGS = -Wall -Wextra -Werror -I includes

LIB = libft

CC = @gcc $(FLAGS)

SRCS =	srcs/main.c\
		srcs/check_parsing.c\
		srcs/error.c\
		srcs/parser.c\
		srcs/create_thread.c\
		srcs/timer.c\
		srcs/eat_sleep_think.c\

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LIB)
			$(CC) -L$(LIB) -lft $(OBJ) -o $(NAME)
			@echo "\033[32mCOMPILATION OK\033[0m"
			
clean:
		@rm -rf $(OBJ)
		@make clean -C $(LIB)
		@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C $(LIB)
		@echo "\033[36mFCLEAN OK\033[0m"

lib:
		@make re -C $(LIB)
	
norm:
		@norminettev3 srcs includes

normlib:
		@norminettev3 libft

re: fclean all

.PHONY: all fclean clean re lib norm normlib
