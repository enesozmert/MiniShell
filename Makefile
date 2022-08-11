#Definition
CC          =   gcc
NAME        =   mini_shell
LIBFT		=	./libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -f

#Directory
OBJ_DIR		=	obj/
SRC_DIR		= 	src/

SRC_COMMON	= 	mini_shell/
SRC_LEXCIAL	= 	lexcial/
SRC_HISTORY	= 	history/
SRC_PARSE	= 	parse/
SRC_LIBFT	=	libft/
SRC_READLINE_PROP	=	readline_prop/

#Files
COMMON		= 	main reader routine
LEXCIAL		=	lexcial token
HISTORY		=	history
PARSE		=	parser
READLINE_PROP		=	readline_prop
#FileCreate

SRC_FILES	+=	$(addprefix $(SRC_COMMON),$(COMMON))
SRC_FILES	+=	$(addprefix $(SRC_LEXCIAL),$(LEXCIAL))
SRC_FILES	+=	$(addprefix $(SRC_HISTORY),$(HISTORY))
SRC_FILES	+=	$(addprefix $(SRC_PARSE),$(PARSE))
SRC_FILES	+=	$(addprefix $(SRC_READLINE_PROP),$(READLINE_PROP))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMON)
			@mkdir -p $(OBJ_DIR)$(SRC_LEXCIAL)
			@mkdir -p $(OBJ_DIR)$(SRC_HISTORY)
			@mkdir -p $(OBJ_DIR)$(SRC_PARSE)
			@mkdir -p $(OBJ_DIR)$(SRC_READLINE_PROP)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception


$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -lreadline -o $(NAME)
			@echo $(NAME) compiled!

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(OBJF)const
			@echo Objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo $(NAME) executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

welcome:
			@echo "Mini Shelle"
			@echo "\n"

.PHONY:		all clean fclean re bonus norm