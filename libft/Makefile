NAME		   :=    libft.a

INC            :=    libft.h
INC_DIR        :=    includes/

HEADERS        := $(addprefix $(INC_DIR), $(INC))

SRC_DIR        :=    sources/

SRC            :=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_split_quotes.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c \
					ft_isalpha.c ft_itoa.c ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c ft_strndup.c ft_strlen.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
					ft_sort_int_tab.c ft_rev_int_tab.c ft_strcpy.c ft_strncpy.c \
					ft_strcat.c ft_strcmp.c ft_strstr.c ft_strncat.c ft_free.c \
					ft_free_add.c ft_free_remove.c ft_free_init.c ft_free_size.c \
					ft_free_malloc.c ft_split_utils.c ft_split_tokens.c ft_split_slash.c\
					get_next_line.c get_next_line_utils.c ft_strrchr.c

OBJ_DIR        :=    build/
OBJ            :=    $(SRC:%.c=$(OBJ_DIR)%.o)

# Compiler options
CC            :=    cc
CC_FLAGS      :=    -Wextra -Werror -Wall -g3
DEBUG_FLAG    :=    -ggdb3

# define standard colors
_END        :=    \x1b[0m
_BOLD       :=    \x1b[1m
_UNDER      :=    \x1b[4m
_REV        :=    \x1b[7m
_GREY       :=    \x1b[30m
_RED        :=    \x1b[31m
_GREEN      :=    \x1b[32m
_YELLOW     :=    \x1b[33m
_BLUE       :=    \x1b[34m
_PURPLE     :=    \x1b[35m
_CYAN       :=    \x1b[36m
_WHITE      :=    \x1b[37m

all: $(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@echo "$(_WHITE)> $(_GREEN)libft compiled successfully\n"


$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) 
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -c $< -o $@

# clean commands
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(_WHITE)>$(_RED) remove libft\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 