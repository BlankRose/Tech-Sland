# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   Tech-sland - Makefile                           #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Wed May 25 21:11:20 CEST 2022     #
#      ||  '-'                                                          #
# ********************************************************************* #

# =-----------------= #
#       SETTING       #
# =-----------------= #

NAME = techsland

COMPILER = c++
FLAGS = -Wall -Werror -Wextra -g3
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

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re