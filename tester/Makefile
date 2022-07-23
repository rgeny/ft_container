# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 20:14:20 by rgeny             #+#    #+#              #
#    Updated: 2022/07/18 11:05:24 by rgeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf

CC					= c++
VALGRIND			= valgrind
COMPILE_FLAG		= $(DEPS_FLAG) -std=c++98 -Wall -Werror -Wextra -g
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= -I$(INCLUDES_DIR) -I$(CLASS_DIR)
VALGRIND_FLAG		= --leak-check=full --show-leak-kinds=all --track-fds=yes

INCLUDES_DIR		= includes/
CLASS_DIR			= class/
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
TESTER_DIR			= $(SRCS_DIR)tester/

VPATH				= $(SRCS_DIR) $(TESTER_DIR)


DEFAULT_FILES		= operator structor member accessor
SRCS				= $(addsuffix .cpp,			main \
												Exceptions \
						$(addprefix tester.,	$(DEFAULT_FILES)))
OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS				= $(OBJS:.o=.d)

EXE					= tester

all					: $(EXE)

$(EXE)				: $(OBJS)
					$(CC) $(COMPILE_FLAG) $^ -o $@

$(OBJS_DIR)%.o		: %.cpp
					$(NEW_DIR) $(OBJS_DIR)
					$(CC) $(COMPILE_FLAG) -c $< $(INCLUDES_FLAG) -o $@

clean				:
					$(DEL_DIR) $(OBJS_DIR)

fclean				: clean
					$(DEL_DIR) $(EXE)

re					: fclean all

valgrind			: all
					$(VALGRIND) $(VALGRIND_FLAG) ./$(EXE) $(ARG)

-include			$(DEPS)

.PHONY				: all clean fclean re valgrind

