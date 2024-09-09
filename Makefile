# Matan Markovits 322318080
# Matanmarkovits@gmail.com

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -v

# Source files
SRCS = main.cpp board.cpp spot.cpp

# Object files
OBJS = main.o board.o spot.o

# Header files
HEADERS = board.hpp spot.hpp

# Output executable
TARGET = catan_game

# Build target
all: $(TARGET)

# Compile and link the executable with verbose output
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile individual source files
main.o: main.cpp board.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

board.o: board.cpp board.hpp spot.hpp
	$(CXX) $(CXXFLAGS) -c board.cpp

spot.o: spot.cpp spot.hpp
	$(CXX) $(CXXFLAGS) -c spot.cpp

# Clean the project
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable
run: all
	./$(TARGET)
