# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:22:54 by hoomen            #+#    #+#              #
#    Updated: 2022/06/03 15:30:50 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler variables
CC		=	cc
FLAGS 	=	-Wall -Wextra -Werror
# file variables
NAME			= push_swap
# source files
MAIN			= push_swap dlst_basics print_dlst sort operations liss
LIBFT			= atoi isdigit strchr strlen
FT_PRINTF 		= convert initmodifiers modifiers pad parse printchar printf printint printnbr printstr putnbrpf
# add prefix and suffix to filenames
MAINFILES		= $(addsuffix .c, $(MAIN))
LIBFTFILES		= $(addprefix libft/ft_,$(addsuffix .c, $(LIBFT)))
FT_PRINTFFILES	= $(addprefix ft_printf/ft_, $(addsuffix .c, $(FT_PRINTF)))
# object files
MAINOBJS		= $(MAINFILES:.c=.o)
LIBFTOBJS		= $(LIBFTFILES:.c=.o)
FT_PRINTFOBJS 	= $(FT_PRINTFFILES:.c=.o)
GNLOBJS			= $(GNLFILES:.c=.o)

all : $(NAME)

$(NAME): $(MAINOBJS) $(LIBFTOBJS) $(FT_PRINTFOBJS)
	@$(CC) $(FLAGS) $(MAINOBJS) $(LIBFTOBJS) $(FT_PRINTFOBJS) -o $(NAME)
	@echo "push_swap is compiled"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@rm -f libft/*.o
	@rm -f ft_printf/*.o

bonus: re

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
