NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf

CC					= c++
COMPILE_FLAG		= $(DEPS_FLAG) -std=c++98 #-Wall -Werror -Wextra
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= $(INCLUDES_DIR) $(CLASS_DIR)

INCLUDES_DIR		= $(addprefix -I includes/,	define)
CLASS_DIR			= $(addprefix -I class/,	vector)
OBJS_DIR			= objs/
SRCS_DIR			= srcs/

VPATH				= $(SRCS_DIR)


DEFAULT_FILES		= operator. structor. member. accessor.
SRCS				= $(addsuffix .cpp,		my_main)
OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS				= $(OBJS:.o=.d)

EXE					= test

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

-include			$(DEPS)

.PHONY				: all clean fclean re

