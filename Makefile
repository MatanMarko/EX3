# # # Matan Markovits 322318080
# # # Matanmarkovits@gmail.com

# # Compiler and flags
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall

# # Executable name
# EXEC = catan_game

# # Source files
# SRC = demo.cpp board.cpp catan.cpp player.cpp spot.cpp main.cpp

# # Object files (generated automatically from source files)
# OBJ = $(SRC:.cpp=.o)

# # Rule to build the executable
# $(EXEC): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# # Rule to compile each source file into an object file
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean rule to remove object files and the executable
# clean:
# 	rm -f $(OBJ) $(EXEC)

# # Run the program
# run: $(EXEC)
# 	./$(EXEC)


# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable name
EXEC = catan_game

# Source files
SRC = demo.cpp board.cpp catan.cpp player.cpp spot.cpp

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
