# Matan Markovits 322318080
# Matanmarkovits@gmail.com

# # Compiler and flags
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall

# # Executable name
# EXEC = catan_game

# # Source files
# SRC = demo.cpp board.cpp catan.cpp player.cpp spot.cpp

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

# Executable names
EXEC = catan_game
TEST_EXEC = catan_test

# Source files for the main game
SRC = demo.cpp board.cpp catan.cpp player.cpp spot.cpp

# Source files for the test
TEST_SRC = tests.cpp board.cpp catan.cpp player.cpp spot.cpp

# Object files for the main game
OBJ = $(SRC:.cpp=.o)

# Object files for the test
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Rule to build the main game executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to build the test executable
$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and executables
clean:
	rm -f $(OBJ) $(EXEC) $(TEST_OBJ) $(TEST_EXEC)

# Run the main program
run: $(EXEC)
	./$(EXEC)

# Run the tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

