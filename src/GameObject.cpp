#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureSheet, ren);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	++xpos;
	++ypos;

	sourceRect.h = 32;
	sourceRect.w = 32;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = xpos;
	destinationRect.y = ypos;
	destinationRect.h = sourceRect.h * 2;
	destinationRect.w = sourceRect.w * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &sourceRect, &destinationRect);
}


