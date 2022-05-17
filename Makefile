NEW_DIR						= mkdir -p
DEL_DIR						= rm -rf

CC							= c++
COMPILE_FLAG				= $(STD_FLAG) $(DEPS_FLAG) -g #-std=c++98 #-Wall -Werror -Wextra
DEPS_FLAG					= -MMD
INCLUDES_FLAG				= $(INCLUDES_DIR) $(CLASS_DIR)
STD_FLAG					=

INCLUDES_DIR				= $(addprefix -I, includes/ \
								$(addprefix includes/,	define))
CLASS_DIR					= $(addprefix -I, class/ \
								$(addprefix class/,		vector \
														type_traits ))
OBJS_DIR					= objs/
SRCS_DIR					= srcs/
UTILS_DIR					= $(SRCS_DIR)Utils/

VPATH						= $(SRCS_DIR) $(UTILS_DIR) $(MAKE_DIR)

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

