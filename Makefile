CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic

INCLUDE_DIRS := $(shell find include -type d)
HEADERS := $(shell find include -type f -name '*.h')
SOURCES := $(wildcard src/*.cpp)

CXXFLAGS += $(addprefix -I,$(INCLUDE_DIRS))

TARGET := build/dexr

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build
