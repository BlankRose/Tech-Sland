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

# Messages to be displayed during compilation runtime
SUCCESS_MSG = √ The programm $(NAME) has been compiled successfully!
COMPILE_MSG = ƒ Compiling $@ ...
CLEANING_MSG = ƒ Cleaning files ...
CLEANOBJ_MSG = ø Objects has been cleared!
CLEANLIB_MSG = ø Library has been cleared!

#==--------------------------------------==#
# *                                      * #
#             SPECIAL METHODS              #
# *                                      * #
#==--------------------------------------==#

# Quick control methods
SILENT = > /dev/null 2>&1
NOERR = || true
STOP = && false

# Syntax colors methods
RED = \033[0;31m
GRN = \033[0;32m
YLW = \033[0;33m
BLU = \033[0;34m
NUL = \033[0m
END = \033[0m\n
BACK = \033[2K\r

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

MLX_FOLDER = MLX42/
MLX_FILE = libmlx42.a
MLX_URL = git@github.com:codam-coding-college/MLX42.git
MLX = $(addprefix $(MLX_FOLDER), $(MLX_FILE))

GRAPHICS_FOLDER = framework/
GRAPHICS_FILES = framework.cpp draw.cpp
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
	@printf "$(BACK)$(YLW)$(COMPILE_MSG)$(NUL)"
	@$(COMPILER) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
	@git clone $(MLX_URL) $(MLX_FOLDER) $(SILENT) $(NOERR)
	@make -sC $(MLX_FOLDER)

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@printf "$(BACK)$(YLW)$(COMPILE_MSG)$(NUL)"
	@$(COMPILER) $(LIBRARIES) $(DANGER) -o $(NAME) $(OBJ) $(MLX)
	@printf "$(BACK)$(GRN)$(SUCCESS_MSG)$(END)"

# Clears all objects files
clean:
	@printf "$(BACK)$(YLW)$(CLEANING_MSG)$(NUL)"
	@rm -f $(OBJ)
	@printf "$(BACK)$(RED)$(CLEANOBJ_MSG)$(END)"

# Clears all objects files, INCLUDING the executable
fclean: clean
	@rm -f $(NAME)

# Cleans the External libs folder using their Makefiles
libclean:
	@make fclean -sC $(MLX_FOLDER)
	@printf "$(BACK)$(RED)$(CLEANLIB_MSG)$(END)"

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
	@echo $(COMPILE_MSG)
	@$(COMPILER) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
	@git clone $(MLX_URL) $(MLX_FOLDER) $(SILENT) $(NOERR)
	@make -sC $(MLX_FOLDER)

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@echo $(COMPILE_MSG)
	@$(COMPILER) $(LIBRARIES) $(DANGER) -o $(NAME) $(OBJ) $(MLX) 
	@echo $(SUCCESS_MSG)

# Clears all objects files
clean:
	@echo $(CLEANING_MSG)
	@del /F /Q $(subst /,\,$(OBJ))
	@echo $(CLEANOBJ_MSG)

# Clears all objects files, INCLUDING the executable
fclean: clean
	@del /F /Q $(addsuffix .exe, $(subst /,\,$(NAME)))

# Cleans the External libs folder using their Makefiles
libclean:
	@make fclean -sC $(MLX_FOLDER)
	@echo $(CLEANLIB_MSG)

# Clears and recompile the whole project
re: fclean all

# Does a quick compile to test run then clears everything
test: all
	@./$(NAME)
	@make fclean

# Protection
.PHONY: all dependency clean fclean libclean re test

endif