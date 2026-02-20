NAME = libftprintf.a

OBJ_PATH = obj/
SRC_PATH = src/
INC_PATH = includes/

SRC_FILES	=	ft_printf.c \
				ft_utoa.c \
				ft_puthex.c \
				ft_write.c \
				ft_strlen.c \
				ft_itoa.c \


SRC	= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH)
RM = rm -rf
AR = ar rcs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $(OBJS)

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
