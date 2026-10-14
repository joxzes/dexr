CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Iinclude

TARGET := build/dexr

.PHONY: all run clean

all: $(TARGET)

$(TARGET): src/main.cpp include/dexr/order.hpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build
