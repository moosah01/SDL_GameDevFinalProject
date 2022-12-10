#pragma once
#include  "GameObject.h"
using namespace std;


enum Direction { Right, Top, Bottom, Left};
enum EndDirection { RightEnd, TopEnd, BottomEnd, LeftEnd};

class Player : public GameObject
{

protected:
	float frinctionCoff;
	float tx;
	float ty;

public:

	int arcStartX = 0;
	int arcStartY = 0;

	int currDistMoved = 0;
	int maxDistance = 32;

	Player();
	SDL_Rect gSpriteClips[4][3];

	int arcLength = 120;

	Direction dir;
	EndDirection endDir;
	bool isIdle;

	int currFrameX = 0;
	int currFrameY = 0;

	void realMove(int destX, int destY);
	//SDL_Point GetPlayerBox(int posX, int posY);


	int Snapping(int pos);

	void Translate(float xVal, float yVal);
	void SetParameters(SDL_Renderer* gameRenderer, string path, int x, int y, int w, int h);
	void Move();
	void drawArc(SDL_Renderer* gameRenderer);
	SDL_Rect* getCurrentClip();
	~Player();
};