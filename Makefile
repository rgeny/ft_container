# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 11:00:36 by rgeny             #+#    #+#              #
#    Updated: 2022/08/26 11:23:57 by rgeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#INCLUDES_FLAG				= $(INCLUDES_DIR) $(CLASS_DIR)
#STD_FLAG					=
#
#INCLUDES_DIR				= $(addprefix -I, includes/ \
#								$(addprefix includes/,	define \
#									$(addprefix class/,	iterator \
#														common \
#														vector)))
#VPATH						= $(SRCS_DIR) $(UTILS_DIR) $(MAKE_DIR)
#
#UTILS						= $(addsuffix .cpp,		print)
#OBJS						= $(patsubst %.cpp, $(OBJS_DIR)$(EXE)_%.o, $(SRCS) $(UTILS))
#DEPS						= $(OBJS:.o=.d)
#
NEW_DIR						= mkdir -p
DEL_DIR						= rm -rf

CC							= c++
COMPILE_FLAG				= $(STD_FLAG) $(DEPS_FLAG) -g #-std=c++98 #-Wall -Werror -Wextra
DEPS_FLAG					= -MMD -MP
INCLUDES_FLAG				= $(addprefix -I,	$(INCLUDES_DIR) \
												$(CLASS_DIR) \
												$(DEFINES_DIR) \
												$(FUNCTIONS_DIR) \
												$(TEMPLATES_DIR) \
												$(ITERATOR_DIR) \
												$(TYPE_TRAITS_DIR) \
												$(VECTOR_DIR))

INCLUDES_DIR				= includes/
CLASS_DIR					= $(INCLUDES_DIR)class/
DEFINES_DIR					= $(INCLUDES_DIR)defines/
FUNCTIONS_DIR				= $(INCLUDES_DIR)functions/
TEMPLATES_DIR				= $(INCLUDES_DIR)templates/
ITERATOR_DIR				= $(TEMPLATES_DIR)iterator/
TYPE_TRAITS_DIR				= $(TEMPLATES_DIR)type_traits/
VECTOR_DIR					= $(TEMPLATES_DIR)vector/
OBJS_DIR					= objs/
SRCS_DIR					= srcs/
UTILS_DIR					= $(SRCS_DIR)Utils/

VPATH						= $(SRCS_DIR)
VPATH						+=$(UTILS_DIR)
VPATH						+=$(MAKE_DIR)

UTILS						= $(addsuffix .cpp,		print)
OBJS						= $(patsubst %.cpp, $(OBJS_DIR)$(EXE)_%.o, $(SRCS) $(UTILS))
DEPS						= $(OBJS:.o=.d)

ifdef SRCS
all							: $(EXE)
else
all							:
							./test.sh
endif

$(EXE)						: $(OBJS)
							$(CC) $(COMPILE_FLAG) $^ -o $@

$(OBJS_DIR)$(EXE)_%.o		: %.cpp
							$(NEW_DIR) $(OBJS_DIR)
							$(CC) $(COMPILE_FLAG) -c $< $(INCLUDES_FLAG) -o $@

clean						:
							$(DEL_DIR) $(OBJS_DIR)

fclean						: clean
#							$(DEL_DIR) $(EXE)

re							:
							make fclean
							make

-include					$(DEPS)

.PHONY						: all clean fclean re

