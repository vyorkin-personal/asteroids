BIN_DIR := bin
SRC_DIR := src

EXTERNAL_DIR := external

GFS_LIB := gfs
GFS_LIB_NAME := lib$(GFS_LIB)
GFS_LIB_DIR := $(EXTERNAL_DIR)/$(GFS_LIB)
GFS_LIB_PATH := $(GFS_LIB_DIR)/bin/$(GFS_LIB_NAME).a

TARGET := $(BIN_DIR)/asteriods

SRC_EXT := cpp

SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))

LIB := -lstdc++
INC := -I include -I $(GFS_LIB_DIR)/include

CXXFLAGS := -g -std=c++11 -Wall -pedantic
MAKEFLAGS += --quiet

# keep in mind that shit works only for clang compiler
LDFLAGS = -framework Carbon -framework OpenGL -framework GLUT -L $(GFS_LIB_DIR)

game: $(TARGET)
	@echo 'running game'
	./$<

$(TARGET): $(SOURCES) $(GFS_LIB_PATH)
	@echo 'building...'
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LIB) $(INC) $^ -o $@

$(GFS_LIB_PATH): $(GFS_LIB_NAME) ;

$(GFS_LIB_NAME):
	$(MAKE) -C $(GFS_LIB_DIR)

clean:
	@echo 'cleaning...'
	$(RM) -r $(TARGET)

.PHONY: clean $(GFS_LIB_NAME)
