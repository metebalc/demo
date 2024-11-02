# Makefile for SDL2 project

CXX = g++
CXXFLAGS = -std=c++20 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image
TARGET = test
SRC = main.cpp Game.cpp TextureManager.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

