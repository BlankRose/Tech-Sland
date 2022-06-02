# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   Tech-sland - Makefile                           #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Thu Jun  2 16:57:45 CEST 2022     #
#      ||  '-'                                                          #
# ********************************************************************* #

# =-----------------= #
#       SETTING       #
# =-----------------= #

# Executable's name
NAME = techsland

# Compilation options
COMPILER = c++
LIBRARIES = -lglfw3 -lopengl32 -lgdi32
FLAGS = -Wall -Werror -Wextra -g3 -std=c++11
ifneq ($(OS), Windows_NT)
	DANGER = -fsanitize=address
endif

# Success message to be displayed when compilation is complete
SUCCESS_MSG = The programm $(NAME) has been compiled successfully!

# =-----------------= #
#       SOURCES       #
# =-----------------= #

EXTERNAL_FOLDER = MLX42/
EXTERNAL_FILES = libmlx42.a
EXTERNAL = $(addprefix $(EXTERNAL_FOLDER), $(EXTERNAL_FILES))

FUNCTIONS = main.cpp

CLASSES_FOLDER = classes/
CLASSES_FILES = Player.cpp Unlimited.cpp
CLASSES = $(addprefix $(CLASSES_FOLDER), $(CLASSES_FILES))

ALL = $(FUNCTIONS) $(CLASSES)
SRC = $(addprefix src/, $(ALL))
OBJ = $(SRC:.cpp=.o)

# =-----------------= #
#        RULES        #
# =-----------------= #

# Main call upon 'make'
all: $(NAME)

# Compile the sources into object files
.cpp.o:
	@$(COMPILER) $(LIBRARIES) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
	@make -sC $(EXTERNAL_FOLDER)

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@$(COMPILER) $(DANGER) -o $(NAME) $(OBJ) $(EXTERNAL)
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
	@make fclean -sC $(EXTERNAL_FOLDER)

# Clears and recompile the whole project
re: fclean all

# Does a quick compile to test run then clears everything
test: all
	@./$(NAME)
	@make fclean

# Protection
.PHONY: all dependency clean fclean libclean re test