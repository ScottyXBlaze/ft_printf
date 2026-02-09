NAME = libftprint.a

OBJ_PATH = obj/
SRC_PATH = src/
INC_PATH = includes/

SRC_FILES	=	ft_printf.c


SRC	= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)✨ ft_printf compilé avec succès !$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)🧹 Les fichiers objets ont été nettoyés.$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)🗑️  L'archive $(NAME) a été supprimée.$(DEF_COLOR)"

re: fclean all
	@echo "$(CYAN)🔄 Reconstruction terminée !$(DEF_COLOR)"

# Pour éviter les confusions avec des fichiers réels
.PHONY: all clean fclean re
