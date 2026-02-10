NAME = libftprintf.a
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

OBJ_PATH = obj/
SRC_PATH = src/
INC_PATH = includes/

SRC_FILES	=	ft_printf.c \
				ft_utoa.c \
				ft_puthex.c \


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
	@echo "$(GREEN)✨ ft_printf compilé avec succès !$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "$(BLUE)🧹 Les fichiers objets ont été nettoyés.$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(MAGENTA)🗑️  L'archive $(NAME) a été supprimée.$(DEF_COLOR)"

re: fclean all
	@echo "$(CYAN)🔄 Reconstruction terminée !$(DEF_COLOR)"

# Pour éviter les confusions avec des fichiers réels
.PHONY: all clean fclean re
