# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:33:36 by ajothos           #+#    #+#              #
#    Updated: 2022/01/23 05:02:17 by ajothos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re check_obj_dir

# _____________________________________________________________________VARIABLES

COL_0					:=	\033[38;2;0;145;15
COL_1					:=	\033[38;2;46;84;240
COL_2					:=	\033[37
UNSET					:=	\033[m

NAME					:=	so_long

CC						:=	clang
OBJ_DIR					:=	obj
FLAGS					:=	-Wall -Wextra -Werror
INCLUDE					:=	include

MLX_DIR					:=	libs/mlx
LIBFT_DIR				:=	libs/libft
LIBS					:=	$(MLX_DIR)/libmlx.a \
							$(LIBFT_DIR)/libft.a
VPATH					:=	src \
							utils \
							gnl

SRC						:=	so_long.c \
							arg_check.c \
							goodbye.c \
							inits.c \
							handlers.c \
							get_next_line.c \
							open_util.c \
							image_opener.c \
							rendering.c \
							map_check.c


OBJ						:=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
DEP						:=	$(wildcard $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.d))))

# _______________________________________________________________________TARGETS

all						:	other_libs_rule $(OBJ_DIR) $(NAME)

$(NAME)					:	$(OBJ)
							@$(CC) $(OBJ) $(LIBS) -framework OpenGL -framework AppKit -o $@
							@echo "$(COL_0);1m"
							@echo "\t\tCOMMAND + V"
							@echo "$(UNSET)"
							@printf "$(shell pwd)/$@ map.ber" | pbcopy

$(OBJ_DIR)/%.o			:	%.c
							$(CC) $(FLAGS) -I $(INCLUDE) -MD -c $< -o $@

$(OBJ_DIR)				:
							@mkdir -p $(OBJ_DIR)/

other_libs_rule: $(MLX_DIR) $(LIBFT_DIR)
							@make -C $<

include $(DEP)
# ________________________________________________________________CLEANS TARGETS

clean					:
							@make clean -C $(MLX_DIR)
							@make clean -C $(LIBFT_DIR)
							@rm -rf $(OBJ_DIR)
							@echo "$(COL_1);3;1mobject\033[23;22m files for \033[3;1m$(NAME)\033[23;22m have been deleted\033[0m"

fclean					:	clean
							@rm -f $(NAME)
							@echo "$(COL_1);3;1m$(NAME)\033[23;22m have been deleted\033[0m"

re						:	fclean all
