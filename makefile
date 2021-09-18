CC 				= gcc
AR				= ar

CFLAGS  		= -Os -std=c11 -Wall -Wextra -pedantic -ffunction-sections -fdata-sections
LDFLAGS 		= -Wl,--gc-sections
ARFLAGS			= rcs

BUILD_DIR 		= build
SRC_DIR			= src

MAIN_FILES		= $(SRC_DIR)/*

MAIN_SRC 		= $(foreach d, $(MAIN_FILES),$(filter-out ,$(wildcard $(d)*.c)))
MAIN_INC 		= $(foreach d, $(MAIN_FILES), -I$d)
MAIN_OBJ		= $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(subst ../,,$(patsubst %.c,%.o,$(subst $(MAIN_FILES)/,,$(MAIN_SRC)))))

all: $(MAIN_OBJ)
	@$(AR) $(ARFLAGS) libdatatypes.a $(MAIN_OBJ)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(info Compiling: $@)
	@$(CC) $(CFLAGS) $(MAIN_INC) -c $< -o $@

init:
	mkdir build