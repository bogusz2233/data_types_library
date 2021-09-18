CC 				= gcc

CFLAGS  		= -Os -std=c11 -Wall -Wextra -pedantic -ffunction-sections -fdata-sections
LDFLAGS 		= -Wl,--gc-sections
ARFLAGS			= rcs

BUILD_DIR 		= build
SRC_DIR			= src
EXAMPLE_DIR		= example

MAIN_FILES		= $(SRC_DIR)/*

MAIN_SRC 		= $(foreach d, $(MAIN_FILES),$(filter-out ,$(wildcard $(d)*.c)))
MAIN_INC 		= $(foreach d, $(SRC_DIR), -I$d)
MAIN_OBJ		= $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(subst ../,,$(patsubst %.c,%.o,$(subst $(MAIN_FILES)/,,$(MAIN_SRC)))))

all: $(MAIN_OBJ)
	@echo $(MAIN_INC)
	@$(CC) -shared -o datatypes.so $(MAIN_OBJ)
#	@$(AR) $(ARFLAGS) libdatatypes.a $(MAIN_OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(info Compiling: $@)
	@$(CC) $(CFLAGS) $(MAIN_INC) -c $< -o $@

init:
	mkdir build

example_list: all
	$(CC) $(CFLAGS) $(LDFLAGS) $(MAIN_INC) ./datatypes.so $(EXAMPLE_DIR)/list_uint8.c -o $(EXAMPLE_DIR)/list_example
	./$(EXAMPLE_DIR)/list_example