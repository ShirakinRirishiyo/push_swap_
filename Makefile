NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3

OBJDIR = ./obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFTDIR = ./libft
LIBFt = $(LIBFTDIR)/libft.a

SRCS =  main.c \
		utils_2.c \
		q_sort.c \
		check_all.c \
		rev_rotate.c \
		rotate.c \
		sort_simple.c \
		swap.c \
		push_stack.c \
		t_list_order.c \
		index_stack.c \
		test.c \

all: $(NAME) $(LIBFt) $(OBJDIR)


$(OBJDIR)/%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFt) $(OBJDIR) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBFt) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFt):
	make -C $(LIBFTDIR) all

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean

	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
