# @project Jetson GPIO library project makefile
# @date October 5 2019
# @author Aqeel AlShafei

# Target executable
TARGET_EXEC = jetson

# Build directory
BUILD_DIR = build
# Source directory
SRC_DIR = src
# Include directory
INC_DIR = inc

# Load all sources, and headers files
SRCS :=	$(shell find $(SRC_DIR) -name '*.c' -o -name '*.cpp')
INCS := $(shell find $(INC_DIR) -name '*.h' -o -name '*.hpp')

# generate object files list
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(OBJS))

# Compiler
CXX := clang
# Compiler flags
CXXFLAGS := -I$(INC_DIR) -Wall -O0

# Linker
LD = $(CXX) -o
# Linker flags
LDFLAGS = -Wall -I$(INC_DIR) -O0

# Load libraries compiler flags and linker flags
LIBLDFLAGS := 

# Build All
all: $(BUILD_DIR)/$(TARGET_EXEC)

# Build Target
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(LD) $@ $(LDFLAGS) $(LIBLDFLAGS) $(OBJS)

# Build C++ object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) $(LIBCXXFLAGS) -c $< -o $@

# Build C object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CXX) $(CXXFLAGS) $(LIBCXXFLAGS) -c $< -o $@

# Clean build
.PHONY: clean
clean:
	@$(RM) -r $(BUILD_DIR)/*
