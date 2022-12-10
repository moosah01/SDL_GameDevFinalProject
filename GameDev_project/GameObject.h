#pragma once
#include <stdlib.h> 
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class GameObject
{

public:

	bool alive;
	SDL_Rect* unitBounds;
	int aplha = 255;
	SDL_Texture* unitTexture;
	int objectType = 0;
	bool isAlive();
	void setAliveAsFalse();
	virtual void Move();
	GameObject();
	virtual ~GameObject();
	//virtual void SetParameters(SDL_Renderer* gameRenderer, string path, int x, int y, int w, int h);

	void setTexture(SDL_Renderer* gameRenderer, std::string path);


};