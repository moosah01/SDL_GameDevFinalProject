#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <string>
using namespace std;

GameObject::~GameObject() 
{

}

GameObject::GameObject()
{
	alive = true;
	unitBounds = new SDL_Rect();
	unitTexture = NULL;
}

bool GameObject::isAlive()
{
	return this->alive;
}

void GameObject::setAliveAsFalse()
{
	this->alive = false;
}

void GameObject::Move()
{

}

void GameObject::setTexture(SDL_Renderer* gameRenderer, string path)
{
	char* c = const_cast<char*>(path.c_str());
	this->unitTexture = IMG_LoadTexture(gameRenderer, c);

}

//void GameObject::SetParameters(SDL_Renderer* gameRenderer, string path, int x, int y, int w, int h)
//{
//	char* c = const_cast<char*>(path.c_str());
//	this->unitTexture = IMG_LoadTexture(gameRenderer, c);
//
//	this->unitBounds->w = w;
//	this->unitBounds->h = h;
//	this->unitBounds->x = x;
//	this->unitBounds->y = y;
//}
