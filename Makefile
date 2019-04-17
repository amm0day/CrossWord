NAME = crossWord

CC = cc# C compiler

RESET = \033[0m
PURPLE = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m

# Paths
# Paths

SRCS =	crossWord.c \
		src/read.c \
		src/grid.c 
		# src/solver.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	@echo "$(YELLOW)Deleting objects files...$(RESET)"
	@rm -rf $(OBJS)
	@echo "$(GREEN)Object files (based in 'src/') have been deleted !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Deleting executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)The executable '$(NAME)' has been deleted !$(RESET)"

re: fclean all

.PHONY: re fclean clean