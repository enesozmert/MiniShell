#Definition
CC          =   gcc
NAME        =   mini_shell
LIBFT		=	./libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -f
#READLINE	=	/Users/eozmert/goinfre/homebrew/opt/readline/lib/libreadline.8.dylib
READLINE	=	/Users/cyalniz/goinfre/homebrew/opt/readline/lib/libreadline.8.dylib

#Directory
OBJ_DIR		=	obj/
SRC_DIR		= 	src/

SRC_COMMON	= 	mini_shell/
SRC_KEYWORDS=	keywords/
SRC_TOKEN	= 	token/
SRC_HISTORY	= 	history/
SRC_PARSE	= 	parse/
SRC_LIBFT	=	libft/
SRC_RDL		=	rdl/
SRC_SYNTAX	=	syntax/
SRC_LEXICAL	=	lexical/
SRC_STATIC	=	static/
SRC_CORE	=	core/
SRC_EXCEPTION	=	exception/
SRC_COMMAND	=	command/
SRC_BUILTIN =	builtin/

#Files
COMMON		= 	main reader routine 
KEYWORDS	=	keywords keywords_size
TOKEN		=	get_token token_clear token_print token_add token_new token_size
HISTORY		=	history
PARSE		=	parser parser_add parser_arg parser_add_buffer
RDL			=	rdl
SYNTAX		=	syntax quote keyword_syntax quote_syntax redir_syntax
STATIC		=	keyword_list operator_list command_list
LEXICAL		=	lexical is_keyword is_operator find_operator find_keyword
CORE		=	white_space count_char quote_count count_matris char_replace \
char_pos keyword_trim keyword_trim_len token_arg_count
EXCEPTION   =	exception_handler exception_write
COMMAND		=	command_create command_run command_find command
BUILTIN		=	echo_builtin
#FileCreate

SRC_FILES	+=	$(addprefix $(SRC_COMMON),$(COMMON))
SRC_FILES	+=	$(addprefix $(SRC_KEYWORDS),$(KEYWORDS))
SRC_FILES	+=	$(addprefix $(SRC_TOKEN),$(TOKEN))
SRC_FILES	+=	$(addprefix $(SRC_HISTORY),$(HISTORY))
SRC_FILES	+=	$(addprefix $(SRC_PARSE),$(PARSE))
SRC_FILES	+=	$(addprefix $(SRC_RDL),$(RDL))
SRC_FILES	+=	$(addprefix $(SRC_SYNTAX),$(SYNTAX))
SRC_FILES	+=	$(addprefix $(SRC_LEXICAL),$(LEXICAL))
SRC_FILES	+=	$(addprefix $(SRC_STATIC),$(STATIC))
SRC_FILES	+=	$(addprefix $(SRC_CORE),$(CORE))
SRC_FILES	+=	$(addprefix $(SRC_EXCEPTION),$(EXCEPTION))
SRC_FILES	+=	$(addprefix $(SRC_COMMAND),$(COMMAND))
SRC_FILES	+=	$(addprefix $(SRC_BUILTIN),$(BUILTIN))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMON)
			@mkdir -p $(OBJ_DIR)$(SRC_KEYWORDS)
			@mkdir -p $(OBJ_DIR)$(SRC_TOKEN)
			@mkdir -p $(OBJ_DIR)$(SRC_HISTORY)
			@mkdir -p $(OBJ_DIR)$(SRC_PARSE)
			@mkdir -p $(OBJ_DIR)$(SRC_RDL)
			@mkdir -p $(OBJ_DIR)$(SRC_SYNTAX)
			@mkdir -p $(OBJ_DIR)$(SRC_LEXICAL)
			@mkdir -p $(OBJ_DIR)$(SRC_STATIC)
			@mkdir -p $(OBJ_DIR)$(SRC_CORE)
			@mkdir -p $(OBJ_DIR)$(SRC_EXCEPTION)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMAND)
			@mkdir -p $(OBJ_DIR)$(SRC_BUILTIN)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception


$(NAME):	$(OBJ)
			@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) -lreadline -o $(NAME)
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