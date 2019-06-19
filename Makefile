# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 15:47:43 by zamazzal          #+#    #+#              #
#    Updated: 2019/06/19 15:24:33 by zamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FLAGS = -Wall -Wextra -Werror

SRCS_PATH = srcs/
OBJ_PATH = obj/

messages_SRCS = 	$(addprefix $(SRCS_PATH), messages/)
ft_select_SRCS = $(addprefix $(SRCS_PATH), ft_select/)
display_SRCS = $(addprefix $(SRCS_PATH), display/)
tools_SRCS = 	$(addprefix $(SRCS_PATH), tools/)
items_SRCS = $(addprefix $(SRCS_PATH), items/)
term_SRCS = 	$(addprefix $(SRCS_PATH), term/)

messages_OBJ = 	$(addprefix $(OBJ_PATH), messages/)
ft_select_OBJ = $(addprefix $(OBJ_PATH), ft_select/)
display_OBJ = $(addprefix $(OBJ_PATH), display/)
tools_OBJ = 	$(addprefix $(OBJ_PATH), tools/)
items_OBJ = $(addprefix $(OBJ_PATH), items/)
term_OBJ = 	$(addprefix $(OBJ_PATH), term/)

TERMCAP = -ltermcap
LIBFT_PATH = libft/
Libft = -L $(LIBFT_PATH) -lft
INCLUDES = -I includes/ -I $(LIBFT_PATH)

messages =		errrors.c		\

ft_select = 	ft_select.c		\
				select_tools.c	\
				select_tools2.c	\
				select_tools3.c \

display =		display.c		\
				display2.c		\

tools =			check.c			\
				tools1.c		\
				tools2.c		\

items =			moves.c			\
				moves2.c		\

term = 			att.c			\
				term.c			\

SRCS = $(addprefix $(messages_SRCS), $(messages)) $(addprefix $(ft_select_SRCS), $(ft_select)) $(addprefix $(display_SRCS), $(display)) $(addprefix $(tools_SRCS), $(tools)) $(addprefix $(items_SRCS), $(items)) $(addprefix $(term_SRCS), $(term))
OBJ = $(addprefix $(messages_OBJ), $(messages:.c=.o)) $(addprefix $(ft_select_OBJ), $(ft_select:.c=.o)) $(addprefix $(display_OBJ), $(display:.c=.o)) $(addprefix $(tools_OBJ), $(tools:.c=.o))  $(addprefix $(items_OBJ), $(items:.c=.o))  $(addprefix $(term_OBJ), $(term:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(Libft) $(INCLUDES) -o $(NAME) $(TERMCAP)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(messages_OBJ)%.o: $(messages_SRCS)%.c
	@mkdir -p $(messages_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(ft_select_OBJ)%.o: $(ft_select_SRCS)%.c
	@mkdir -p $(ft_select_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(display_OBJ)%.o: $(display_SRCS)%.c
	@mkdir -p $(display_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(tools_OBJ)%.o: $(tools_SRCS)%.c
	@mkdir -p $(tools_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(items_OBJ)%.o: $(items_SRCS)%.c
	@mkdir -p $(items_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(term_OBJ)%.o: $(term_SRCS)%.c
	@mkdir -p $(term_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\x1B[96mObjects Files \x1B[90;0m[\x1B[34;1m $(notdir $(OBJ)) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

re: fclean all

.PHONY: all, clean, fclean, re
