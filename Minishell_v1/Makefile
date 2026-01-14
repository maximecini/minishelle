# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 13:19:53 by rcini-ha          #+#    #+#              #
#    Updated: 2025/07/31 19:36:28 by rcini-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = src
OBJDIR = obj
INCDIR = includes

SRC_MAIN		=	main.c
SRC_HANDLERS 	=	handlers/signals.c
SRC_PARS		=	parser/cmd_node_builder.c parser/expand.c parser/expand_utils.c\
					parser/build_cmd_lst.c parser/expand_quotes.c

SRC_BUILTINS	=	builtins/builtins.c builtins/cd.c \
					builtins/export.c builtins/pwd.c\
					builtins/unset.c builtins/env.c \
					builtins/echo.c builtins/exit.c \

SRC_HEREDOC		= 	heredoc/heredoc.c heredoc/child_heredoc.c heredoc/read_heredoc.c \
					heredoc/heredoc_data.c heredoc/heredoc_signals.c heredoc/heredoc_utils.c \

SRC_UTILS		=	utils/string/u_word.c utils/string/u_word_helpers.c utils/u_env.c\
					utils/string/u_quotes.c utils/split_smart.c utils/string/u_checks.c\
					utils/string/u_space.c utils/u_read.c utils/redirect/u_redirect_utils.c\
					utils/redirect/u_parser.c utils/u_files.c utils/redirect/u_redirect_cmd.c \
					utils/redirect/u_redirect_process.c \
					utils/u_export.c utils/u_lst.c utils/string/u_str_replace.c utils/u_path.c\
					utils/u_pipe.c utils/u_pipe_utils.c utils/u_init.c utils/u_cmd.c utils/cpy_lst_to_tab.c\
					utils/u_exec.c  utils/read_multilin.c utils/string/u_str_replace_substring.c\
					utils/u_env_utils.c utils/string/u_space_2.c

SRC_ERROR 	= 	errors/error_lexer.c errors/error_lexer_helpers.c errors/error_exec.c errors/error_syntax.c errors/error_bultin.c
SRC_PRINT 	= 	print/print.c
SRC_EXEC 	= 	exec/exec.c exec/status.c exec/finalize.c exec/process_cmd.c exec/setup.c exec/exec_builtin_utils.c
SRC_FREE	= 	utils/free/u_free.c utils/free/u_free_lst.c

SRC = $(SRC_MAIN) $(SRC_HEREDOC) $(SRC_EXEC) $(SRC_HANDLERS) $(SRC_PARS) $(SRC_BUILTINS)  $(SRC_FREE) $(SRC_UTILS) $(SRC_ERROR) $(SRC_PRINT)
OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)

LDFLAGS =  -L$(LIBFT_DIR)  -lreadline -lncurses
LIBS =  $(LIBFT)

# Archiver
AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3  -I$(LIBFT_INCLUDE) -I

VERBOSE ?= 1
ifeq ($(VERBOSE),1)
  V :=
else
  V := @
endif

RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"

all: $(OBJDIR) $(LIBFT) $(NAME)

$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS)  -MMD -MP -c $< -o $@

-include $(DEP)

$(NAME): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBS) -o $(NAME)
	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)

$(LIBFT):
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	$(V)echo '[$(NAME)] Libft build successfully'

clean:
	$(V)echo $(RED)'[$(NAME)] Cleaning objects'd$(RESET)
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus regen
.DEFAULT_GOAL := all
