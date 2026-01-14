# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 13:59:21 by sle-bail          #+#    #+#              #
#    Updated: 2025/10/17 11:39:03 by sle-bail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = src
OBJDIR = obj
INCDIR = includes

SRC_MAIN = main.c minishell/init_env.c minishell/shell_loop.c \
	minishell/shell_parse.c minishell/shell_exec.c
SRC_TOKENIZER = tokenizer/tokenisation.c tokenizer/tokenisation_utils.c
SRC_PARSING = parsing/create_cmd.c
SRC_UTILS = utils/quotes/quotes.c\
		utils/smart_split/smart_split.c utils/smart_split/u_smart_split.c\
			utils/string/utils_string.c utils/smart_split/u2_smart_split.c\
			utils/smart_split/smart_split_helpers.c \
			utils/lst/lst.c utils/lst/lst1.c utils/lst/delimiter_process.c \
			utils/lst/lst_fill.c utils/trim_cmd.c \
			utils/trim_cmd_utils.c utils/trim_cmd_internal.c \
			utils/trim_cmd_args.c utils/trim_cmd_redirect.c
SRC_SYNTAX_ERROR = syntax_error/syntax_error.c syntax_error/syntax_error_utils.c \
				   syntax_error/syntax_error_redirect.c syntax_error/syntax_error_redirect_utils.c \
				   syntax_error/syntax_error_pipe.c
SRC_FREE = free/free.c free/free_cmd.c
SRC_EXPAND = expand/env_utils.c expand/expand_core.c \
		   expand/expand_commands.c expand/expand_state.c expand/expand_variable.c \
		   expand/expand_process.c expand/expand_args.c expand/expand_redirects.c \
		   expand/expand_heredoc_clean.c
SRC_BUILTIN = builtin/builtins.c builtin/echo.c builtin/cd.c builtin/pwd.c builtin/unset.c builtin/exit.c \
			  builtin/exit_utils.c \
			  builtin/env/env.c builtin/env/u_env.c builtin/env/u1_env.c \
			  builtin/export/export.c builtin/export/u_export.c builtin/export/u1_export.c
SRC_HANDEL =  handel/signals.c handel/signals_utils.c
SRC_HEREDOC = herdoc/herdoc.c herdoc/heredoc_utils.c herdoc/heredoc_child.c \
	herdoc/heredoc_child_utils.c herdoc/heredoc_init.c herdoc/heredoc_cleanup.c \
	herdoc/heredoc_path.c
SRC_EXEC = exec/exec.c exec/exec_command.c exec/exec_stdio.c exec/exec_pipeline.c \
	   exec/exec_pipes.c exec/exec_redirections.c exec/exec_redirections_validate.c exec/exec_child.c \
		   exec/exec_path.c exec/exec_env.c exec/exec_uchild.c

SRC = $(SRC_MAIN) $(SRC_UTILS) $(SRC_TOKENIZER) $(SRC_SYNTAX_ERROR) $(SRC_FREE) $(SRC_EXEC) $(SRC_PARSING) $(SRC_EXPAND) \
$(SRC_BUILTIN) $(SRC_HANDEL) $(SRC_HEREDOC)
OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC) )
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))


LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)

LDFLAGS =  -L$(LIBFT_DIR)
LIBS =  $(LIBFT) -lreadline

# Archiver
AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3 -I$(LIBFT_INCLUDE) -I$(READLINE_DIR)/include

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
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) clean

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re bonus regen
.DEFAULT_GOAL := all
