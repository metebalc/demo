#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"

class GameObject
{
	public:
		GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
		~GameObject();

		void Update();
		void Render();

	private:
		int xpos;
		int ypos;

		SDL_Texture* objTexture;
		SDL_Rect sourceRect, destinationRect;
		SDL_Renderer* renderer;

};

#endif
