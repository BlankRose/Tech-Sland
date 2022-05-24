# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   Tech-sland - Makefile                           #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Tue May 24 23:58:14 CEST 2022     #
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

ENGINE = main.cpp

ALL = $(ENGINE)
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

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re