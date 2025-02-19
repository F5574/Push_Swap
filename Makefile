SRCS = push_functions.c push_aux.c push_init_a.c push_init_b.c push_moves.c push_prep.c push_sortsmall.c push_swap.c push_utils.c push_validator.c

NAME = push_swap

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

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