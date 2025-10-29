CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = src/main.cpp src/LanguageModel.cpp src/RandomGenerator.cpp
TARGET = slm

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
