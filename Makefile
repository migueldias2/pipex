NAME = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

# Define sources and objects

SRCS = 	pipex.c\
		perrors.c\
		utils.c\

OBJ = $(SRCS:.c=.o)

# Bonus sources and objects

SRCS_BONUS = 	pipex_bonus.c\
 				utils_bonus.c\
				perrors_bonus.c\
				utils2_bonus.c


OBJ_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = libft/libft.a
# Compile the main program

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

all : $(NAME)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

bonus : $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME)
