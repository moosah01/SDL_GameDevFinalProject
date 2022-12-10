#pragma once
#pragma once
#include  "GameObject.h"
using namespace std;

class Obstacles : public GameObject
{
protected:

public:
	Obstacles();
	~Obstacles();
	void SetParameters(SDL_Renderer* gameRenderer, string path, int x, int y, int w, int h);


private:


};