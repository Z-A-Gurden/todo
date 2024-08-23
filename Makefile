CXX := g++
OBJ_DIR := obj
OBJECTS := $(addprefix $(OBJ_DIR)/, main.o menu.o read.o add.o mark.o remove.o erase.o)

#compiles all object files into main todo file
todo: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

#creates object directory if not existant and compiles object files
$(OBJ_DIR)/%.o: %.cpp headers.h
	mkdir -p $(OBJ_DIR)
	$(CXX) $< -c -o $@


.PHONY: clean clean-obj
#removes all content created with the Makefile including list.txt
clean: clean-obj
	rm -f todo list.txt

#removes only object files
clean-obj:
	rm -rf $(OBJ_DIR)