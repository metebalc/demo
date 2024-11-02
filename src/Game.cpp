#include "Game.h"
#include "TextureManager.h"

SDL_Texture* playerTexture;
SDL_Rect sourceRect, destinationRect;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		else
		{
			std::cerr << "Window creation failed!" << SDL_GetError() << std::endl;
			isRunning = false;
			return;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		else
		{
			std::cerr << "Renderer creation failed!" << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			isRunning = false;;
			return;
		}
		
		isRunning = true;
	}
	else
	{
		std::cerr << "SDL Initalization failed: " << SDL_GetError() << std::endl;
		isRunning = false;
	}
	
	playerTexture = TextureManager::LoadTexture("../assets/Unarmed_Idle_full.png", renderer);	
}

void Game::init(const GameSettings& settings)
{
	init(settings.title, settings.xpos, settings.ypos, settings.width, settings.height, settings.fullscreen);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
	}
}

void Game::update()
{
	destinationRect.h = 64;
	destinationRect.w = 64;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//this is where we add stuff
	SDL_RenderCopy(renderer, playerTexture, NULL, &destinationRect);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned." << std::endl;
}

