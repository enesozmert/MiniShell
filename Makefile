#Definition
CC          =   gcc
NAME        =   minishell
LIBFT		=	./libft/libft.a
CC			=	gcc
USER_NAME1	=	eozmert
USER_NAME2	=	cyalniz
READLINE	=	/Users/${USER_NAME2}/goinfre/homebrew/opt/readline/lib
READLINE_INCLUDE	=	/Users/${USER_NAME2}/goinfre/homebrew/opt/readline/include
CFLAGS		=	-Wall -Werror -Wextra -g -I $(READLINE_INCLUDE)
RM			=	rm -f


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
SRC_SIGNAL	=	signal/
SRC_CORE	=	core/
SRC_EXCEPTION	=	exception/
SRC_COMMAND	=	command/
SRC_BUILTIN =	builtin/
SRC_ENVIRONMENT = environment/

#Files
COMMON		= 	main reader routine
KEYWORDS	=	keywords keywords_size
TOKEN		=	get_token token_clear token_delone token_add_copy token_add token_new token_size token_add_type \
				token_type_is token_print 
HISTORY		=	history
PARSE		=	parser parser_arg  parser_arg_quote parser_arg_keyword parser_arg_space \
				parser_arg_is parser_arg_isnot parser_arg_isquote\
				parser_add parser_add_buffer
RDL			=	rdl
SYNTAX		=	syntax keyword_syntax quote_syntax redir_syntax export_syntax pipe_syntax
STATIC		=	keyword_list operator_list command_list quote_list delimiter_list identifier_list \
				token_type_list
LEXICAL		=	lexical is_keyword is_operator is_quote is_dollar is_identifier is_delimiter is_token_type\
				find_operator find_keyword find_quote \
				command_in_token_type keyword_in_operator find_keyword_id
CORE		=	white_space count_char quote_count count_matris char_replace free_double_str \
				char_pos keyword_trim keyword_trim_len token_arg_count \
				token_key_count token_value_count
EXCEPTION   =	exception_handler exception_write
COMMAND		=	command_create command_run command_find command_exec command_find_path \
				command_clear command_fork command 
BUILTIN		=	echo_builtin cd_builtin pwd_builtin exit_builtin env_builtin export_builtin unset_builtin
ENVIRONMENT =	environment env_find env_len env_update env_add env_exist env_asc env_dsc env_delete
SIGNAL		=	signal_handler
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
SRC_FILES	+=	$(addprefix $(SRC_SIGNAL),$(SIGNAL))
SRC_FILES	+=	$(addprefix $(SRC_CORE),$(CORE))
SRC_FILES	+=	$(addprefix $(SRC_EXCEPTION),$(EXCEPTION))
SRC_FILES	+=	$(addprefix $(SRC_COMMAND),$(COMMAND))
SRC_FILES	+=	$(addprefix $(SRC_BUILTIN),$(BUILTIN))
SRC_FILES	+=	$(addprefix $(SRC_ENVIRONMENT),$(ENVIRONMENT))

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
			@mkdir -p $(OBJ_DIR)$(SRC_SIGNAL)
			@mkdir -p $(OBJ_DIR)$(SRC_CORE)
			@mkdir -p $(OBJ_DIR)$(SRC_EXCEPTION)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMAND)
			@mkdir -p $(OBJ_DIR)$(SRC_BUILTIN)
			@mkdir -p $(OBJ_DIR)$(SRC_ENVIRONMENT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception


$(NAME):	$(OBJ)
			@$(CC) $(OBJ) $(CFLAGS) -lreadline -L $(READLINE)  -o $(NAME) $(LIBFT) 
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