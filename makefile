NAME = edMatch.out
COMPILER = gcc
FLAGS = -lm -pedantic -Wall

EXEC_DIR = ./bin
OBJ_DIR = ./objects

C_FILES = *.c
O_FILES = *.o

YELLOW = "\033[1;33m"
RED = "\033[1;31m" 
CYAN = "\033[1;36m"
PURPLE = "\033[1;35m"
RESET_COLOR = "\033[0m"


all: create_directories $(O_FILES) create_binary

%.o: ./src/%.c ./include/%.h
	@echo $(YELLOW)
	@echo Compilling $(C_FILES) files...
	@$(COMPILER) -c ./src/$(C_FILES) 
	@mv $(O_FILES) $(OBJ_DIR)
	@echo $(RESET_COLOR)

create_directories:
	@echo $(PURPLE)
	@echo Creating and organizing directories...
	@mkdir $(OBJ_DIR)
	@echo $(RESET_COLOR)

create_binary:
	@echo $(YELLOW)
	@echo Creating executable file...
	@$(COMPILER) -o $(NAME) $(OBJ_DIR)/$(O_FILES) $(FLAGS)
	@echo $(RESET_COLOR)

clean:
	@echo $(RED)
	@echo Cleaning directory...
	@rm -rf $(OBJ_DIR) *.o $(NAME)
	@echo $(RESET_COLOR)

run:
	@echo $(CYAN)
	@echo Running program...
	@echo $(RESET_COLOR)
	@./$(NAME) $(r)

valgrind:
	@echo $(CYAN)
	@echo Running valgrind on $(NAME)
	@echo $(RESET_COLOR)
	@valgrind ./$(NAME) $(r)

again: clean all run