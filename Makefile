SRCS = push_functions.c push_aux.c push_swap.c 

NAME = push_swap

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = cc

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME) push_swap
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all


.PHONY: all fclean clean