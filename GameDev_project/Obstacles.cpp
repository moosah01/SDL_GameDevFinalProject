#include "Obstacles.h"

Obstacles::~Obstacles()
{

}

Obstacles::Obstacles() : GameObject()
{
	this->objectType = 1;
}

void Obstacles::SetParameters(SDL_Renderer* gameRenderer, string path, int x, int y, int w, int h)
{
	char* c = const_cast<char*>(path.c_str());
	this->unitTexture = IMG_LoadTexture(gameRenderer, c);

	this->unitBounds->w = w;
	this->unitBounds->h = h;
	this->unitBounds->x = x;
	this->unitBounds->y = y;
}