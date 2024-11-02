#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

struct GameSettings 
{
    	const char* title = "TEST";
    	int xpos = SDL_WINDOWPOS_CENTERED;
    	int ypos = SDL_WINDOWPOS_CENTERED;
    	int width = 800;
    	int height = 600;
    	bool fullscreen = false;
};

class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height,  bool fullscreen);
		void init(const GameSettings& settings);

		void handleEvents();
		void update();
		void render();
		void clean();

		bool running() { return isRunning; };
	
	private:
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
};



#endif
