CXX = g++
CXXFLAGS := -std=c++20 -O2 -pipe -DLOCAL -Wall -Wextra 
SRC := submit.cpp
OUT := a.out

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT) < input.txt
