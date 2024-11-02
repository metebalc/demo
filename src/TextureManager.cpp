#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren) //fileName is a placeholder for texture
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	if (!tempSurface)
	{
		std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
		SDL_FreeSurface(tempSurface);
		return nullptr;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
