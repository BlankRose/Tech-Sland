# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   Tech-sland - Makefile                           #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Sun Jun 12 18:29:56 CEST 2022     #
#      ||  '-'                                                          #
# ********************************************************************* #

# =-----------------= #
#       SETTING       #
# =-----------------= #

# Executable's name
NAME = techsland

# Compilation options
COMPILER = c++
FLAGS = -Wall -Werror -Wextra -g3 -std=c++11
ifneq ($(OS), Windows_NT)
	DANGER = -fsanitize=address
	LIBRARIES = -I include -lglfw
#-L "/Users/$USER/.brew/opt/glfw/lib/"
else
	LIBRARIES = -lglfw3 -lopengl32 -lgdi32
endif

# Success message to be displayed when compilation is complete
SUCCESS_MSG = The programm $(NAME) has been compiled successfully!

# =-----------------= #
#       SOURCES       #
# =-----------------= #

MLX_FOLDER = MLX42/
MLX_FILE = libmlx42.a
MLX = $(addprefix $(MLX_FOLDER), $(MLX_FILE))

LIBFT_FOLDER = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_FILE))

EXT_FILES = $(LIBFT) $(MLX)

GRAPHICS_FOLDER = graphics/
GRAPHICS_FILES = 
GRAPHICS = $(addprefix $(GRAPHICS_FOLDER), $(GRAPHICS_FILES))

CLASSES_FOLDER = classes/
CLASSES_FILES = Entity.cpp Player.cpp
CLASSES = $(addprefix $(CLASSES_FOLDER), $(CLASSES_FILES))

ALL = main.cpp framework.cpp $(CLASSES) $(GRAPHICS)
SRC = $(addprefix src/, $(ALL))
OBJ = $(SRC:.cpp=.o)

# =-----------------= #
#        RULES        #
# =-----------------= #

# Main call upon 'make'
all: $(NAME)

# Compile the sources into object files
.cpp.o:
	@$(COMPILER) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
	@make -sC $(LIBFT_FOLDER)
	@make -sC $(MLX_FOLDER)

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@$(COMPILER) $(LIBRARIES) $(DANGER) -o $(NAME) $(OBJ) $(EXT_FILES) 
ifneq ($(OS), Windows_NT)
	@printf "\033[32m$(SUCCESS_MSG)\033[0m\n"
else
	@echo $(SUCCESS_MSG)
endif

# Clears all objects files
clean:
ifeq ($(OS), Windows_NT)
	@del /F /Q $(subst /,\,$(OBJ))
else
	@rm -f $(OBJ)
endif

# Clears all objects files, INCLUDING the executable
fclean: clean
ifeq ($(OS), Windows_NT)
	@del /F /Q $(addsuffix .exe, $(subst /,\,$(NAME)))
else
	@rm -f $(NAME)
endif

# Cleans the External libs folder using their Makefiles
libclean:
	@make fclean -sC $(EXT_FOLDER)

# Clears and recompile the whole project
re: fclean all

# Does a quick compile to test run then clears everything
test: all
	@./$(NAME)
	@make fclean

# Protection
.PHONY: all dependency clean fclean libclean re test