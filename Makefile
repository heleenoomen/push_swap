# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:22:54 by hoomen            #+#    #+#              #
#    Updated: 2022/06/14 18:24:34 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler variables
CC		=	cc
FLAGS 	=	-Wall -Wextra -Werror
# file variables
NAME			= push_swap
BONUSNAME		= checker
# source files
MAIN			= push_swap
UTILS			= print_dlst input_utils1 input_utils2 dlst_basics1 dlst_basics2 operations1 operations2 check_dupl sort sort_utils push_sort calc_o calc_d calc_d_min calc_d_max ins_dst
LIBFT			= atoi isdigit strchr strlen split calloc memcpy putstr_fd putchar_fd strncmp
FT_PRINTF		= convert initmodifiers modifiers pad parse printchar printf printint printnbr printstr putnbrpf
GNL				= get_next_line get_next_line_utils
# add prefix and suffix to filenames
MAINFILES		= $(addsuffix .c, $(MAIN))
UTILSFILES		= $(addsuffix .c, $(UTILS))
BONUSFILES		= bonus.c
LIBFTFILES		= $(addprefix libft/ft_,$(addsuffix .c, $(LIBFT)))
FT_PRINTFFILES	= $(addprefix ft_printf/ft_, $(addsuffix .c, $(FT_PRINTF)))
GNLFILES		= $(addprefix get_next_line/, $(addsuffix .c, $(GNL)))
# object files
MAINOBJS		= $(MAINFILES:.c=.o)
UTILSOBJS		= $(UTILSFILES:.c=.o)
LIBFTOBJS		= $(LIBFTFILES:.c=.o)
FT_PRINTFOBJS 	= $(FT_PRINTFFILES:.c=.o)
GNLOBJS			= $(GNLFILES:.c=.o)
BONUSOBJS		= $(BONUSFILES:.c=.o)

all : $(NAME) clean

$(NAME): $(MAINOBJS) $(UTILSOBJS) $(LIBFTOBJS) $(FT_PRINTFOBJS)
	@$(CC) $(FLAGS) $(MAINOBJS) $(UTILSOBJS) $(LIBFTOBJS) $(FT_PRINTFOBJS) -o $(NAME)
	@echo "push_swap is compiled"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@rm -f libft/*.o
	@rm -f ft_printf/*.o

bonus: $(BONUSOBJS) $(UTILSOBJS) $(LIBFTOBJS) $(FT_PRINTFOBJS) $(GNLOBJS)
	@$(CC) $(FLAGS) $(BONUSOBJS) $(UTILSOBJS) $(LIBFTOBJS) $(FT_PRINTFOBJS) $(GNLOBJS) -o $(BONUSNAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
