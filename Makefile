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

NAME = techsland

COMPILER = c++
FLAGS = -Wall -Werror -Wextra -g3 -std=c++11
DANGER = -fsanitize=address

# =-----------------= #
#       SOURCES       #
# =-----------------= #

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

all: $(NAME)

.cpp.o:
	@$(COMPILER) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(COMPILER) $(DANGER) -o $(NAME) $(OBJ)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)
	@make fclean

.PHONY: all clean fclean re test