# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 17:39:47 by mcarepa-          #+#    #+#              #
#    Updated: 2024/10/03 12:53:06 by mcarepa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for building a library (libft.a) from a set of C source files

# Name of the library to be created
NAME = libft.a

# Compiler to use
CC = cc

# Compiler flags for warnings and errors
CFLAGS = -Wall -Wextra -Werror

# Source files for the library (excluding bonus files)
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
      ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
      ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
      ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
      ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
      ft_putnbr_fd.c ft_strtrim.c ft_striteri.c ft_strjoin.c ft_strcmp.c\

# Bonus source files
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
            ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

# Object files derived from main source files
OBJ = $(SRC:.c=.o)

# Object files derived from bonus source files
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Main target: build the library
all: $(NAME)

# Rule to build the library from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Bonus target: build the library with bonus functions only
bonus:	$(BONUS_OBJ)
	make OBJ="$(BONUS_OBJ)" all

	#ar is a Unix utility used to create, modify, and extract files from archives. In this case, it is used to manage static library archives.
	#r: Replace or add files to the archive. This option specifies that ar should replace existing files in the archive or add new files if they do not already exist.
	#c: Create a new archive if it does not already exist. This option ensures that a new archive is created if the specified archive ($(NAME)) does not exist.
	#s: Write an index into the archive, allowing faster access to members later. This option is commonly used when creating or updating static library archives.

	#$(OBJ) (object files) are prerequisites, meaning they must exist or be built first before $(NAME) (the static library archive) can be created.
	#$(NAME) specifies the name of the static library archive to create or update.

# Rule to compile main C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

	# $< represents the prerequisite (source file)
	## $@ represents the target (object file)

# Rule to compile bonus C source files into object files
bonus_%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning rules
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

	# rm -f: remove files without prompting, ignore nonexistent files

fclean: clean
	rm -f $(NAME)

# Rule to perform a clean build (remove all generated files and rebuild) - regra para recompilar o projeto do zero
re: fclean all

# Declare phony targets(targets that are not filenames) - Indicando que 'clean', 'fclean' e 're' não são nomes de arquivos
.PHONY: all bonus clean fclean re

