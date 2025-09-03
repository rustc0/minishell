CC = cc -Wall -Wextra -Werror #-g -fsanitize=address

NAME = minishell

SRCS = main.c ./execution/exec.c ./execution/main_utils.c ./execution/pipe.c ./execution/red.c ./execution/sig.c \
		./execution/builtins/echo.c ./execution/builtins/pwd.c ./execution/builtins/cd.c ./execution/builtins/env.c \
		./execution/builtins/export.c ./execution/builtins/unset.c ./execution/builtins/b_utils.c ./execution/builtins/exit.c \
		./parsing/token.c ./parsing/token_helpers.c ./parsing/freeing_functions.c ./parsing/fill_struct.c ./parsing/handles.c \
		./parsing/counts.c ./parsing/check_syntax.c ./parsing/heredoc.c ./parsing/expansion.c ./parsing/expansion_utils.c \
		./parsing/heredoc_utils.c 

LIBFT_SRCS =./libft/ft_atoi.c		./libft/ft_isprint.c	./libft/ft_strnstr.c 	./libft/ft_strncmp.c	./libft/ft_striteri.c	\
			./libft/ft_bzero.c		./libft/ft_strdup.c		./libft/ft_strrchr.c 	./libft/ft_tolower.c	./libft/ft_split.c		\
			./libft/ft_memchr.c		./libft/ft_strlcat.c 	./libft/ft_toupper.c	./libft/ft_putchar_fd.c	./libft/ft_calloc.c		\
			./libft/ft_isalnum.c	./libft/ft_memcmp.c		./libft/ft_strlcpy.c 	./libft/ft_substr.c		./libft/ft_putstr_fd.c	\
			./libft/ft_isalpha.c	./libft/ft_memcpy.c		./libft/ft_strlen.c		./libft/ft_strjoin.c	./libft/ft_putendl_fd.c	\
			./libft/ft_isascii.c	./libft/ft_memmove.c	./libft/ft_strchr.c		./libft/ft_itoa.c		./libft/ft_putnbr_fd.c	\
			./libft/ft_isdigit.c	./libft/ft_memset.c		./libft/ft_strtrim.c 	./libft/ft_strmapi.c	./libft/ft_strcmp.c

HEADERS = minishell.h ./libft/libft.h

LIBFT = ./libft/libft.a

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) $(HEADERS)
	$(CC) $(SRCS) -I./libft -L./libft -lft -lreadline -o $(NAME)
	@echo "Compilation complete. Executable: $(NAME)"

$(LIBFT): $(LIBFT_SRCS)
	@echo "MAKING LIBFT ARCHIVE..."
	@make bonus clean -C libft

install: $(NAME)
	@echo "installing minishell ..."
	@cp ./$(NAME) /home/rahmoham/bin/

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all