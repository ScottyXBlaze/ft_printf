NAME = libftprintf.a
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

OBJ_PATH = obj/
SRC_PATH = src/
INC_PATH = includes/

SRC_FILES	=	ft_printf.c \
				ft_utoa.c \
				ft_puthex.c \
				safe_write.c \


SRC	= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH) -I$(LIBFT_PATH)
RM = rm -rf
AR = ar crs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	@cp $(LIBFT) $@
	@$(AR) $@ $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
