NAME = libft.a

RESET   = \033[0m
GREEN   = \033[32m
RED     = \033[31m

SRCDIR = src
OBJDIR = obj
INCDIR = include

LIBFTDIR = $(SRCDIR)/
GNLDIR = $(SRCDIR)/get_next_line/
PRINTF_DIR = $(SRCDIR)/ft_printf/

LIBFT_SRC = $(LIBFTDIR)ft_isalpha.c $(LIBFTDIR)ft_isdigit.c $(LIBFTDIR)ft_isalnum.c $(LIBFTDIR)ft_isascii.c \
			$(LIBFTDIR)ft_isprint.c $(LIBFTDIR)ft_strlen.c $(LIBFTDIR)ft_memset.c $(LIBFTDIR)ft_bzero.c \
			$(LIBFTDIR)ft_memcpy.c $(LIBFTDIR)ft_memmove.c $(LIBFTDIR)ft_strlcpy.c $(LIBFTDIR)ft_strlcat.c \
			$(LIBFTDIR)ft_toupper.c $(LIBFTDIR)ft_tolower.c $(LIBFTDIR)ft_strrchr.c \
			$(LIBFTDIR)ft_strncmp.c $(LIBFTDIR)ft_memchr.c $(LIBFTDIR)ft_memcmp.c $(LIBFTDIR)ft_strnstr.c\
			$(LIBFTDIR)ft_atoi.c $(LIBFTDIR)ft_calloc.c $(LIBFTDIR)ft_substr.c \
			$(LIBFTDIR)ft_strtrim.c $(LIBFTDIR)ft_split.c $(LIBFTDIR)ft_itoa.c \
			$(LIBFTDIR)ft_strmapi.c $(LIBFTDIR)ft_striteri.c $(LIBFTDIR)ft_putchar_fd.c $(LIBFTDIR)ft_putstr_fd.c \
			$(LIBFTDIR)ft_putendl_fd.c $(LIBFTDIR)ft_putnbr_fd.c $(LIBFTDIR)ft_todigits.c $(LIBFTDIR)ft_int_isdigit.c \
			$(LIBFTDIR)valide_base.c $(LIBFTDIR)ft_count_world.c $(LIBFTDIR)ft_tab_is_sort.c $(LIBFTDIR)ft_shift_argv.c \
			$(LIBFTDIR)free_split.c $(LIBFTDIR)ft_strchr.c $(LIBFTDIR)ft_strdup.c $(LIBFTDIR)ft_strjoin.c  \
			$(LIBFTDIR)ft_atoi_base.c $(LIBFTDIR)ft_istouppercase.c $(LIBFTDIR)ft_strtolower.c $(LIBFTDIR)ft_strcat.c \
			$(LIBFTDIR)ft_strcmp.c $(LIBFTDIR)ft_strncat.c $(LIBFTDIR)ft_strstr.c $(LIBFTDIR)ft_print_bits.c \
			$(LIBFTDIR)ft_lstadd_back.c $(LIBFTDIR)ft_lstnew.c $(LIBFTDIR)ft_lstlast.c $(LIBFTDIR)ft_cpy_str_array.c\
			$(LIBFTDIR)ft_array_len.c 	$(LIBFTDIR)ft_sort_tab_str.c $(LIBFTDIR)ft_lstcpy.c $(LIBFTDIR)ft_lstclear.c\
			 $(LIBFTDIR)ft_lstdelone.c  $(LIBFTDIR)print_tab_str.c $(LIBFTDIR)ft_strcpy.c $(LIBFTDIR)ft_digitlen.c \
			 $(LIBFTDIR)ft_base_power.c \

GNL_SRC = $(GNLDIR)get_next_line.c
PRINTF_SRC = $(PRINTF_DIR)ft_printf.c $(PRINTF_DIR)ft_printf_util.c $(PRINTF_DIR)ft_calculate_length.c

SRC = $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@ $(AR) $(NAME) $(OBJ)
	@ echo "libft $(GREEN)O.K$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@ rm -rf $(OBJDIR)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

