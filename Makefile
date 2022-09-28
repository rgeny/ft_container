# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 15:21:07 by rgeny             #+#    #+#              #
#    Updated: 2022/09/28 16:53:33 by rgeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf

CC					= c++
COMPILE_FLAG		= $(DEPS_FLAG) -std=c++98 -Wall -Werror -Wextra -g
DEPS_FLAG			= -MMD -MP
INCLUDES_FLAG		= $(addprefix -I,	$(INCLUDES_DIR) \
										$(CLASS_DIR) \
										$(DEFINES_DIR) \
										$(FUNCTIONS_DIR) \
										$(TEMPLATES_DIR))

OBJS_DIR			= objs/
SRCS_DIR			= srcs/
RBNODE_DIR			= $(SRCS_DIR)RBNode/
RBNODEBASE_DIR		= $(RBNODE_DIR)RBNodeBase/
INCLUDES_DIR		= includes/
CLASS_DIR			= $(INCLUDES_DIR)class/
DEFINES_DIR			= $(INCLUDES_DIR)defines/
FUNCTIONS_DIR		= $(INCLUDES_DIR)functions/
TEMPLATES_DIR		= $(INCLUDES_DIR)templates/

VPATH				= $(SRCS_DIR)
VPATH				+=$(RBNODE_DIR) $(RBNODEBASE_DIR)

DEFAULT_FILES		= operator structor member accessor
SRCS				= $(addsuffix .cpp,				increment \
						$(addprefix RBNodeBase.,	$(DEFAULT_FILES)))
OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS				= $(OBJS:.o=.d)

LIB					= container.a

all					: $(OBJS_DIR) $(LIB)

$(OBJS_DIR)			:
					echo b
					$(NEW_DIR) $@

$(LIB)				: $(OBJS)
					ar -rc $@ $^
					ranlib $@

$(OBJS_DIR)%.o		: %.cpp
					$(CC) $(COMPILE_FLAG) -c $< $(INCLUDES_FLAG) -o $@

clean				:
					$(DEL_DIR) $(OBJS_DIR)

fclean				: clean
					$(DEL_DIR) $(LIB)

re					:
					make fclean
					make all

-include			$(DEPS)

.PHONY				: all clean fclean re valgrind

