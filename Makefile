# # Matan Markovits 322318080
# # Matanmarkovits@gmail.com

# # Compiler
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -v

# # Source files
# SRCS = main.cpp board.cpp spot.cpp

# # Object files
# OBJS = main.o board.o spot.o

# # Header files
# HEADERS = board.hpp spot.hpp

# # Output executable
# TARGET = catan_game

# # Build target
# all: $(TARGET)

# # Compile and link the executable with verbose output
# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# # Compile individual source files
# main.o: main.cpp board.hpp
# 	$(CXX) $(CXXFLAGS) -c main.cpp

# board.o: board.cpp board.hpp spot.hpp
# 	$(CXX) $(CXXFLAGS) -c board.cpp

# spot.o: spot.cpp spot.hpp
# 	$(CXX) $(CXXFLAGS) -c spot.cpp

# # Clean the project
# clean:
# 	rm -f $(OBJS) $(TARGET)

# # Run the executable
# run: all
# 	./$(TARGET)


# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable name
EXEC = catan_game

# Source files
SRC = main.cpp board.cpp catan.cpp player.cpp spot.cpp

# Object files (generated automatically from source files)
OBJ = $(SRC:.cpp=.o)

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program
run: $(EXEC)
	./$(EXEC)
