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

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

# Executable's name
NAME = techsland

# Compilation options
COMPILER = c++
FLAGS = -Wall -Werror -Wextra -g3 -std=c++11
ifneq ($(OS), Windows_NT)
	DANGER = -fsanitize=address
	LIBRARIES = -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
else
	LIBRARIES = -lglfw3 -lopengl32 -lgdi32
endif

# Success message to be displayed when compilation is complete
SUCCESS_MSG = The programm $(NAME) has been compiled successfully!

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

MLX_FOLDER = MLX42/
MLX_FILE = libmlx42.a
MLX = $(addprefix $(MLX_FOLDER), $(MLX_FILE))

GRAPHICS_FOLDER = framework/
GRAPHICS_FILES = framework.cpp
GRAPHICS = $(addprefix $(GRAPHICS_FOLDER), $(GRAPHICS_FILES))

CLASSES_FOLDER = classes/
CLASSES_FILES = Entity.cpp Player.cpp Time.cpp
CLASSES = $(addprefix $(CLASSES_FOLDER), $(CLASSES_FILES))

ALL = main.cpp $(CLASSES) $(GRAPHICS)
SRC = $(addprefix src/, $(ALL))
OBJ = $(SRC:.cpp=.o)

#==--------------------------------------==#
# *                                      * #
#             RULES - LINUX OS             #
# *                                      * #
#==--------------------------------------==#

ifneq ($(OS), Windows_NT) # Checks if its NOT Windows

# Main call upon 'make'
all: $(NAME)

# Compile the sources into object files
.cpp.o:
	@$(COMPILER) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
	@make -sC $(MLX_FOLDER)

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@$(COMPILER) $(LIBRARIES) $(DANGER) -o $(NAME) $(OBJ) $(MLX)
	@printf "\033[32m$(SUCCESS_MSG)\033[0m\n"

# Clears all objects files
clean:
	@rm -f $(OBJ)

# Clears all objects files, INCLUDING the executable
fclean: clean
	@rm -f $(NAME)

# Cleans the External libs folder using their Makefiles
libclean:
	@make fclean -sC $(MLX_FOLDER)

# Clears and recompile the whole project
re: fclean all

# Does a quick compile to test run then clears everything
test: all
	@./$(NAME)
	@make fclean

# Protection
.PHONY: all dependency clean fclean libclean re test

#==--------------------------------------==#
# *                                      * #
#            RULES - WINDOWS OS            #
# *                                      * #
#==--------------------------------------==#

else # In case its running on Windows

# Main call upon 'make'
all: $(NAME)

# Compile the sources into object files
.cpp.o:
	@$(COMPILER) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
	@make -sC $(MLX_FOLDER)

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@$(COMPILER) $(LIBRARIES) $(DANGER) -o $(NAME) $(OBJ) $(MLX) 
	@echo $(SUCCESS_MSG)

# Clears all objects files
clean:
	@del /F /Q $(subst /,\,$(OBJ))

# Clears all objects files, INCLUDING the executable
fclean: clean
	@del /F /Q $(addsuffix .exe, $(subst /,\,$(NAME)))

# Cleans the External libs folder using their Makefiles
libclean:
	@make fclean -sC $(MLX_FOLDER)

# Clears and recompile the whole project
re: fclean all

# Does a quick compile to test run then clears everything
test: all
	@./$(NAME)
	@make fclean

# Protection
.PHONY: all dependency clean fclean libclean re test

endif