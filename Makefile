# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   TechSland - Makefile                            #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Sat Jul 16 20:29:23 CEST 2022     #
#      ||  '-'                                                          #
# ********************************************************************* #


#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#
 
# Executable specialities
NAME = TechSland
LANG = cpp
DEFINES = 
TEST_ARGS = 

# Compilation options
COMPILER = default
FLAGS = -Wall -Werror -Wextra -g3
ifneq ($(OS), Windows_NT)
# Is unsupported on windows
	LINKER = -fsanitize=address
endif

# External dependencies
# MAKE_DIRS: not finished yet..
LIBRARIES = -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
INCLUDES = /Users/$(USER)/.brew/opt/glfw/include ./include
MAKE_DIRS = 

# Messages to display
COMPILE_MSG = ƒ Compiling $@ ...
SUCCESS_MSG = √ The programm $(NAME) has been compiled successfully!
CLEANING_MSG = ƒ Cleaning files ...
CLEANOBJ_MSG = ø Objects has been cleared!





#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

# Listing every source files
GLAD = src/glad.c
ALL = main openGL output
SUBFOLDER = src
BINFOLDER = bin

# Adds the applicable extension and path to each files
SRC = $(addprefix $(SUBFOLDER)/, $(addsuffix .$(LANG), $(ALL)))
OBJ = $(GLAD:.c=.o) $(SRC:.$(LANG)=.o)





#==--------------------------------------==#
# *                                      * #
#               QUICK MACROS               #
# *                                      * #
#==--------------------------------------==#

# Quick control
SILENT = > /dev/null 2>&1
NOERR = || true
STOP = && false

# Escape sequence getter
ifeq ($(OS), Windows_NT)
	ESC = 
else
	ESC = \033
	NEWLINE = \n
	BREAK = \r
endif

# Output control
RED = $(ESC)[0;31m
GRN = $(ESC)[0;32m
YLW = $(ESC)[0;33m
BLU = $(ESC)[0;34m
NUL = $(ESC)[0m
END = $(ESC)[0m$(NEWLINE)
BACK = $(ESC)[2K$(BREAK)

# Compiler counter
CMP_TOTAL = $(shell awk -F' ' '{printf NF}' <<< "$(SRC) $(GLAD)")
CMP_COUNT = 0

# If COMPILER is set to default
ifeq ($(COMPILER), default)
	ifeq ($(LANG), c)
		COMPILER = gcc
	else ifeq ($(LANG), cpp)
		COMPILER = c++
	endif
endif

FLAGS += $(addprefix -I, $(INCLUDES)) $(addprefix -D, $(DEFINES))
LINKER += $(LIBRARIES)



#==--------------------------------------==#
# *                                      * #
#              RULES - COMMON              #
# *                                      * #
#==--------------------------------------==#

# Main call upon 'make'
all: $(NAME)

# Clears and recompile the whole project
re: fclean all

# Execute all makefiles requierd
dependencies:
	@$(shell awk -F' ' '{make -sC }' <<< '$(MAKE_DIRS)')

# Compile and run the executable and clears
ifeq ($(NAME), test)
tester: all
else # Prevents override issue due to commonly choosen name
test: all
endif
	@./$(NAME) $(TEST_ARGS) $(NOERR)
	@make fclean

# Protection
.PHONY: all re clean fclean re





#==--------------------------------------==#
# *                                      * #
#             RULES - LINUX OS             #
# *                                      * #
#==--------------------------------------==#

# Checks if its NOT Windows
ifneq ($(OS), Windows_NT)

# Compile the sources into object files
.$(LANG).o:
	@printf "$(BACK)$(YLW)[$(CMP_COUNT) / $(CMP_TOTAL)] $(COMPILE_MSG)$(NUL)"
	@mkdir $(BINFOLDER) $(SILENT) $(NOERR)
	@$(COMPILER) $(FLAGS) -o $(subst $(SUBFOLDER)/, $(BINFOLDER)/, $@) -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))

.c.o:
	@printf "$(BACK)$(YLW)[$(CMP_COUNT) / $(CMP_TOTAL)] $(COMPILE_MSG)$(NUL)"
	@mkdir $(BINFOLDER) $(SILENT) $(NOERR)
	@gcc -I ./include/ -g3 -o $(subst $(SUBFOLDER)/, $(BINFOLDER)/, $@) -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))

# Compile the objects and dependencies into an executable
$(NAME): $(GLAD) $(OBJ)
	@printf "$(BACK)$(YLW)[Finalizing..] $(COMPILE_MSG)$(NUL)"
	@$(COMPILER) $(LINKER) -o $(NAME) $(subst $(SUBFOLDER)/, $(BINFOLDER)/, $(OBJ))
	@printf "$(BACK)$(GRN)$(SUCCESS_MSG)$(END)"

# Clears all objects files
clean:
	@printf "$(BACK)$(YLW)$(CLEANING_MSG)$(NUL)"
	@rm -Rf $(BINFOLDER)
	@printf "$(BACK)$(RED)$(CLEANOBJ_MSG)$(END)"

# Clears all objects files, INCLUDING the executable
fclean: clean
	@rm -f $(NAME)





#==--------------------------------------==#
# *                                      * #
#            RULES - WINDOWS OS            #
# *                                      * #
#==--------------------------------------==#

# In case its running under Windows
else

# Compile the sources into object files
.$(LANG).o:
	@echo $(BACK)$(YLW)$(COMPILE_MSG)$(NUL)
	@$(COMPILER) $(FLAGS) -o $@ -c $<

# Compile the objects and dependencies into an executable
$(NAME): $(OBJ)
	@echo $(BACK)$(YLW)$(COMPILE_MSG)$(NUL)
	@$(COMPILER) $(LINKER) -o $(NAME) $(OBJ)
	@echo $(BACK)$(GRN)$(SUCCESS_MSG)$(END)

# Clears all objects files
clean:
	@echo $(BACK)$(YLW)$(CLEANING_MSG)$(NUL)
	@del /f /q $(subst /,\,$(OBJ))
	@echo $(BACK)$(RED)$(CLEANOBJ_MSG)$(END)

# Clears all objects files, INCLUDING the executable
fclean: clean
	@del /f /q $(addsuffix .exe, $(subst /,\,$(NAME)))

endif


# Personnal free to use template
# BY Rosie ~