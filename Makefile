EXEC = $(shell basename $(shell pwd))
SOURCE = src
BUILD = build

CC_LINUX = g++
CC_WIN = /usr/bin/i686-w64-mingw32-g++

CC = $(CC_LINUX)

CCFLAGS = -O3 -Os
LDFLAGS = -static -static-libgcc -static-libstdc++

SOURCES := $(shell find $(SOURCE) -name *.cpp)
MODULES := $(shell find $(SOURCE) -name *.cppm)
PCMS := $(MODULES:%.cppm=$(BUILD)/%.pcm)
OBJS := $(SOURCES:%.cpp=$(BUILD)/%.o) $(MODULES:%.cppm=$(BUILD)/%.o)

$(BUILD)/%.pcm: %.cppm
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) --precompile $< -o $@

$(BUILD)/%.o: $(BUILD)/%.pcm
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILD)/%.o: %.cpp | $(PCMS)
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILD)/$(EXEC): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.PRECIOUS: $(BUILD)/%.pcm $(BUILD)/%.o
.PHONY: clean all run run-std

all: $(BUILD)/$(EXEC)

run: all
	./$(BUILD)/$(EXEC) $(ARGS)

run-std: all
	./$(BUILD)/$(EXEC) $(shell cat args)

clean:
	@rm -rf $(BUILD)
