# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++14

# Targets and files
TARGET = myprogram
SRCS = main.cpp AdultBird.cpp AdultCat.cpp AdultDog.cpp TeenBird.cpp TeenCat.cpp TeenDog.cpp BabyCat.cpp BabyBird.cpp BabyDog.cpp BasePet.cpp Cat.cpp Dog.cpp Bird.cpp Game1.cpp Stats.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# How to build the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# How to compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
