FLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c \
		utils/included.c \
		utils/write_spec_data.c \
		utils/create_string_spec.c \
		utils/check_cutted.c \
		utils/fill_format.c \
		utils/create_data_for_print.c \
		utils/handle_char.c \
		utils/is_simple.c \
		utils/handle_string.c \
		utils/handle_complex_string.c \
		utils/print_symbols.c \
		utils/handle_int.c \
		utils/handle_complex_int.c \
		utils/int_prec_case.c  \
		utils/int_wdth_and_prec.c \
		utils/int_wdth_case_only.c \
		utils/int_print_log.c \
		utils/handle_hex.c \
		utils/translate_base.c \
		utils/handle_complex_hex.c \
		utils/wdth_cases_only_hex.c \
		utils/simple_prec_case_hex.c \
		utils/wdth_and_prec_hex.c \
		utils/handle_pointer.c \
		utils/handle_percent.c 

CC = cc

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

LIB_PATH = ../libft/*.o

HEADER = ft_printf.h

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_PATH)
	ar rcs $(NAME) $(OBJS) $(LIB_PATH)

%.o:%.c $(HEADER)
	$(CC) $(FLAGS)  -I.  -c $< -o $@

bonus : all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re $(NAME)

