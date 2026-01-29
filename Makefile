CXX = g++
CXXFLAGS := -std=c++20 -O2 -pipe -DLOCAL -Wall
SRC := submit.cpp
OUT := a.out

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT) < input.txt
