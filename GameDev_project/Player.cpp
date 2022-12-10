#pragma once
#include "Player.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int moveDiff = 0;
int oldDistance = 0;

Player::~Player()
{
	
}

Player::Player() : GameObject()
{

	this->objectType = 0;
	frinctionCoff = 0.75;
	tx = 0.0;
	ty = 0.0;

	bool endTop = false;
	bool endBottom = false;
	bool endLeft = false;
	bool endRight = false;



	//this->isIdle = true;
	//FIRST ROW START
	gSpriteClips[0][0].x = 0;
	gSpriteClips[0][0].y = 0;
	gSpriteClips[0][0].w = 924;
	gSpriteClips[0][0].h = 960;

	gSpriteClips[0][1].x = 934;
	gSpriteClips[0][1].y = 0;
	gSpriteClips[0][1].w = 924;
	gSpriteClips[0][1].h = 960;

	gSpriteClips[0][2].x = 1867;
	gSpriteClips[0][2].y = 0;
	gSpriteClips[0][2].w = 924;
	gSpriteClips[0][2].h = 960;
	//FIRST ROW END
	
	//SECOND ROW START
	gSpriteClips[1][0].x = 0;
	gSpriteClips[1][0].y = 960;
	gSpriteClips[1][0].w = 924;
	gSpriteClips[1][0].h = 960;

	gSpriteClips[1][1].x = 934;
	gSpriteClips[1][1].y = 960;
	gSpriteClips[1][1].w = 924;
	gSpriteClips[1][1].h = 960;

	gSpriteClips[1][2].x = 1867;
	gSpriteClips[1][2].y = 960;
	gSpriteClips[1][2].w = 924;
	gSpriteClips[1][2].h = 960;
	//SECOND ROW END

	//THIRD ROW START
	gSpriteClips[2][0].x = 0;
	gSpriteClips[2][0].y = 1920;
	gSpriteClips[2][0].w = 924;
	gSpriteClips[2][0].h = 960;

	gSpriteClips[2][1].x = 934;
	gSpriteClips[2][1].y = 1920;
	gSpriteClips[2][1].w = 924;
	gSpriteClips[2][1].h = 960;

	gSpriteClips[2][2].x = 1867;
	gSpriteClips[2][2].y = 1920;
	gSpriteClips[2][2].w = 924;
	gSpriteClips[2][2].h = 960;
	//THIRD ROW END

	//FOURTH ROW START
	gSpriteClips[3][0].x = 0;
	gSpriteClips[3][0].y = 2880;
	gSpriteClips[3][0].w = 924;
	gSpriteClips[3][0].h = 960;

	gSpriteClips[3][1].x = 934;
	gSpriteClips[3][1].y = 2880;
	gSpriteClips[3][1].w = 924;
	gSpriteClips[3][1].h = 960;

	gSpriteClips[3][2].x = 1867;
	gSpriteClips[3][2].y = 2880;
	gSpriteClips[3][2].w = 924;
	gSpriteClips[3][2].h = 960;
	//FOURTH ROW END
}

void Player::Translate(float xVal, float yVal)
{

	if (xVal < 0) {

		this->dir = Left;
		this->endDir = LeftEnd;
	

		arcStartX = this->unitBounds->x - 20;
		arcStartY = this->unitBounds->y + this->unitBounds->h/2;
		/*this->isLeft = true;
		this->isRight = false;
		this->isBottom = false;
		this->isTop = false;

		this->endLeft = true;
		this->endRight = false;
		this->endBottom = false;
		this->endTop = false;*/
	}

	if (xVal > 0) {

		this->dir = Right;
		this->endDir = RightEnd;
		

		arcStartX = this->unitBounds->x + this->unitBounds->w + 20;
		arcStartY = this->unitBounds->y + this->unitBounds->h/2;
		/*this->isRight = true;
		this->isLeft = false;
		this->isBottom = false;
		this->isTop = false;

		this->endRight = true;
		this->endLeft = false;
		this->endTop = false;
		this->endBottom = false;*/
	}

	if (yVal > 0) {

		this->dir = Bottom;
		this->endDir = BottomEnd;

		arcStartX = this->unitBounds->x + this->unitBounds->w/2;
		arcStartY = this->unitBounds->y + this->unitBounds->h + 20;
		/*this->isBottom = true;
		this->isTop = false;
		this->isRight = false;
		this->isLeft = false;

		this->endBottom = true;
		this->endLeft = false;
		this->endRight = false;
		this->endTop = false;*/
	}

	if (yVal < 0) {

		this->dir = Top;
		this->endDir = TopEnd;

		arcStartX = this->unitBounds->x + this->unitBounds->w/2;
		arcStartY = this->unitBounds->y - 20;
		/*this->isTop = true;
		this->isBottom = false;
		this->isRight = false;
		this->isLeft = false;

		this->endTop = true;
		this->endLeft = false;
		this->endRight = false;
		this->endBottom = false;*/
	}
	//currDistMoved = 0;
	this->tx = xVal;
	this->ty = yVal;
	/*this->isBottom = false;
	this->isTop = false;
	this->isLeft = false;
	this->isRight = false;*/
}

//void Player::Move()
//{
//	currDistMoved = currDistMoved + (int)tx;
//	currDistMoved = currDistMoved + (int)ty;
//
////	if (currDistMoved < maxDistance) {
//		unitBounds->x = unitBounds->x + (int)tx;
//		unitBounds->y = unitBounds->y + (int)ty;
//
//		if (unitBounds->x < -80) {
//			unitBounds->x = SCREEN_WIDTH - unitBounds->w;
//		}
//
//		if (unitBounds->x > SCREEN_WIDTH) {
//			unitBounds->x = 0;
//		}
//
//		if (unitBounds->y > SCREEN_HEIGHT) {
//			unitBounds->y = 0;
//		}
//
//		if (unitBounds->y < -80) {
//			unitBounds->y = SCREEN_HEIGHT - unitBounds->h;
//		}
//
//		tx *= frinctionCoff;
//		ty *= frinctionCoff;
//
//		if ((abs(tx)) <= 1.1 && (abs(ty)) <= 1.1) {
//			//printf("I am here");
//			this->isIdle = true;
//			/*this->isRight = false;
//			this->isLeft = false;
//			this->isBottom = false;
//			this->isTop = false;*/
//		}
////	}
//	/*else {
//		moveDiff = currDistMoved - maxDistance;
//		if (tx != 0) {
//			unitBounds->x = unitBounds->x + moveDiff;
//		}
//		else if (ty != 0) {
//			unitBounds->y = unitBounds->y + moveDiff;
//
//		}
//		this->isIdle = true;
//	}*/
//
//	
//}


void Player::Move() 
{
	if (ty == 0) {
		//implementation for left and right movement
		oldDistance = currDistMoved;
		currDistMoved = currDistMoved + abs((int)tx);
		if (currDistMoved <= 32)
		{
			unitBounds->x = unitBounds->x + (int)tx;

			if (unitBounds->x <= 0) {
				unitBounds->x = 0;
			}
			if (unitBounds->x  <= SCREEN_WIDTH && unitBounds->x >= SCREEN_WIDTH - unitBounds->w) {
				unitBounds->x = SCREEN_WIDTH - unitBounds->w;
			}
			if (unitBounds->y < 0) {
				unitBounds->y = 0;
			}
			if (unitBounds->y <= SCREEN_HEIGHT && unitBounds->y >= SCREEN_HEIGHT - unitBounds->h) {
				unitBounds->y = SCREEN_HEIGHT - unitBounds->h;
			}

			tx *= frinctionCoff;
			ty *= frinctionCoff;

			
			if ((abs(tx)) <= 1.1 && (abs(ty)) <= 1.1) 
			{
				this->isIdle = true;
			}
			if (currDistMoved == 32) {
				printf("i am here A => x direction\n");
				this->isIdle = true;
				tx = 0;
				ty = 0;
				currDistMoved = 0;

				unitBounds->x = Snapping(unitBounds->x);
				unitBounds->y = Snapping(unitBounds->y);


			}
		}
		else if (currDistMoved > 32)
		{
			printf("i am here B => x direction");
			moveDiff = 32 - oldDistance;
			unitBounds->x = unitBounds->x + moveDiff;

			if (unitBounds->x <= 0) {
				unitBounds->x = 0;
			}
			if (unitBounds->x <= SCREEN_WIDTH && unitBounds->x >= SCREEN_WIDTH - unitBounds->w) {
				unitBounds->x = SCREEN_WIDTH - unitBounds->w;
			}
			if (unitBounds->y < 0) {
				unitBounds->y = 0;
			}
			if (unitBounds->y <= SCREEN_HEIGHT && unitBounds->y >= SCREEN_HEIGHT - unitBounds->h) {
				unitBounds->y = SCREEN_HEIGHT - unitBounds->h;
			}
			this->isIdle = true;
			tx = 0;
			ty = 0;
			currDistMoved = 0;
			unitBounds->x = Snapping(unitBounds->x);
			unitBounds->y = Snapping(unitBounds->y);
		}
	}
	else if (tx == 0) {
		//implementation for left and right movement
		oldDistance = currDistMoved;
		currDistMoved = currDistMoved + abs((int)ty);
		if (currDistMoved <= 32)
		{
			unitBounds->y = unitBounds->y + (int)ty;
			if (unitBounds->x <= 0) {
				unitBounds->x = 0;
			}
			if (unitBounds->x <= SCREEN_WIDTH && unitBounds->x >= SCREEN_WIDTH - unitBounds->w) {
				unitBounds->x = SCREEN_WIDTH - unitBounds->w;
			}
			if (unitBounds->y < 0) {
				unitBounds->y = 0;
			}
			if (unitBounds->y <= SCREEN_HEIGHT && unitBounds->y >= SCREEN_HEIGHT - unitBounds->h) {
				unitBounds->y = SCREEN_HEIGHT - unitBounds->h;
			}

			tx *= frinctionCoff;
			ty *= frinctionCoff;

			if ((abs(tx)) <= 1.1 && (abs(ty)) <= 1.1)
			{
				this->isIdle = true;
			}
			if (currDistMoved == 32) {
				printf("i am here A => y direction\n");
				this->isIdle = true;
				tx = 0;
				ty = 0;
				currDistMoved = 0;
				unitBounds->x = Snapping(unitBounds->x);
				unitBounds->y = Snapping(unitBounds->y);
			}

		}
		else if (currDistMoved > 32)
		{

			printf("i am here B => y direction");
			moveDiff = 32 - oldDistance;
			unitBounds->y = unitBounds->y + moveDiff;

			if (unitBounds->x <= 0) {
				unitBounds->x = 0;
			}
			if (unitBounds->x <= SCREEN_WIDTH && unitBounds->x >= SCREEN_WIDTH - unitBounds->w) {
				unitBounds->x = SCREEN_WIDTH - unitBounds->w;
			}
			if (unitBounds->y < 0) {
				unitBounds->y = 0;
			}
			if (unitBounds->y <= SCREEN_HEIGHT && unitBounds->y >= SCREEN_HEIGHT - unitBounds->h) {
				unitBounds->y = SCREEN_HEIGHT - unitBounds->h;
			}
			this->isIdle = true;
			tx = 0;
			ty = 0;
			currDistMoved = 0;
			unitBounds->x = Snapping(unitBounds->x);
			unitBounds->y = Snapping(unitBounds->y);
		}
	}
}

int Player::Snapping(int pos)
{
	//multiple of x closest to n where n is basically 32 i.e; tile_size
	if (pos < 32) {
		return 0;
	}
	printf("I am snapping");
	if (32 > pos) {
		return 32;
	}
	pos = pos + 32 / 2;
	pos = pos - (pos % 32);
	return pos;
}

//SDL_Point GetPlayerBox(int posX, int posY)
//{
//	SDL_Point point;
//
//	if (posX == 0 && posY == 0) {
//		point.x = 0;
//		point.y = 0;
//		return point;
//	}
//
//	point.x = posX / 32;
//	point.y = posY / 32;
//
//	return point;
//}

void Player::realMove(int destX, int destY)
{
	int distance = abs(destX - this->unitBounds->x) + abs(destY - this->unitBounds->y);
	if (distance <= 1) {
		this->unitBounds->x += (destX - this->unitBounds->x) * 0.1;
		this->unitBounds->y += (destY - this->unitBounds->y) * 0.1;
	}
	else {
		this->isIdle = true;
	}
}

void Player::drawArc(SDL_Renderer* gameRenderer) {

	

	int endArcX = 0;
	int endArcY = 0;
	float offset = 0;
	int divBy = 100;
	
	switch (this->dir) {

	case Bottom:

		//endArcY = arcStartY - ceil(arcLength * sin(30));
		for (int i = 0; i < 500; i++) {
			endArcY = arcStartY - ceil(arcLength * sin(30)) + (i%5);
			endArcX = arcStartX - ceil(arcLength * cos(i));
			SDL_SetRenderDrawColor(gameRenderer, 245, 187, 0, 50);
			SDL_RenderDrawLine(gameRenderer, arcStartX, arcStartY, endArcX, endArcY);
		}
		break;

	case Top:
		//endArcY = arcStartY + ceil(arcLength * sin(30));
		for (int i = 0; i < 500; i++) {
			endArcY = arcStartY + ceil(arcLength * sin(30)) + (i % 5);

			endArcX = arcStartX - ceil(arcLength * cos(i));
			SDL_SetRenderDrawColor(gameRenderer, 245, 187, 0, 50);
			SDL_RenderDrawLine(gameRenderer, arcStartX, arcStartY, endArcX, endArcY);
		}
		break;

	case Left:		
		//endArcX = arcStartX + ceil(arcLength * cos(60));

		//endArcX = arcStartX + ceil(arcLength * cos(60));

		for (int i = 0; i < 500; i++) {
			endArcY = arcStartY + ceil(arcLength * sin(i));
			endArcX = arcStartX + ceil(arcLength * cos(60)) - (i%5);
			SDL_SetRenderDrawColor(gameRenderer, 245, 187, 0, 50);
			SDL_RenderDrawLine(gameRenderer, arcStartX, arcStartY, endArcX, endArcY);

		}			
		break;

	case Right:
		//endArcX = arcStartX - ceil(arcLength * cos(60));
		for (int i = 0; i < 500; i++) {
			endArcX = arcStartX - ceil(arcLength * cos(60)) - (i % 5);

			endArcY = arcStartY + ceil(arcLength * sin(i));
			SDL_SetRenderDrawColor(gameRenderer, 245, 187, 0, 50);
			SDL_RenderDrawLine(gameRenderer, arcStartX, arcStartY, endArcX, endArcY);

		}
		break;

	}
}

void Player::SetParameters(SDL_Renderer* gameRenderer, string path, int x, int y, int w, int h)
{
	char* c = const_cast<char*>(path.c_str());
	this->unitTexture = IMG_LoadTexture(gameRenderer, c);

	this->unitBounds->w = w;
	this->unitBounds->h = h;
	this->unitBounds->x = x;
	this->unitBounds->y = y;
}


SDL_Rect* Player::getCurrentClip()
{
	SDL_Rect* currClip = new SDL_Rect();

	//if (tx == 0 && ty == 0) {
	//	this->isIdle = true;
	//}

	switch (this->dir) {
	case Bottom:
		if (this->isIdle == false) {
			currClip = &gSpriteClips[0][this->currFrameY / 3];
			currFrameY++;
			if (currFrameY / 3 == 3) {
				currFrameY = 0;
			}
		}
		//arcStartX = this->unitBounds->x + (this->unitBounds->w / 2);
		//arcStartY = this->unitBounds->y + (this->unitBounds->h);
		break;

	case Left:
		if (this->isIdle == false) {
			currClip = &gSpriteClips[1][this->currFrameY / 3];
			currFrameY++;
			if (currFrameY / 3 == 3) {
				currFrameY = 0;
			}
		}
		//arcStartX = this->unitBounds->x;
		//arcStartY = this->unitBounds->y + (this->unitBounds->h / 2);
		break;

	case Right:
		if (this->isIdle == false) {
			currClip = &gSpriteClips[2][this->currFrameY / 3];
			currFrameY++;
			if (currFrameY / 3 == 3) {
				currFrameY = 0;
			}
		}

		//arcStartX = this->unitBounds->x + this->unitBounds->w;
		//arcStartY = this->unitBounds->y + (this->unitBounds->h / 2);
		break;

	case Top:
		if (this->isIdle == false) {
			currClip = &gSpriteClips[3][this->currFrameY / 3];
			currFrameY++;
			if (currFrameY / 3 == 3) {
				currFrameY = 0;
			}
		}
		//arcStartX = this->unitBounds->x + (this->unitBounds->w / 2);
		//arcStartY = this->unitBounds->y;
		break;
	}

	switch (this->endDir) {
	case BottomEnd: 
		if (this->isIdle == true) {
			return &gSpriteClips[0][1];
		}
		break;

	case TopEnd:
		if (this->isIdle == true) {
			return &gSpriteClips[3][1];
		}
		break;

	case RightEnd:
		if (this->isIdle == true) {
			return &gSpriteClips[2][1];

		}
		break;

	case LeftEnd:
		if (this->isIdle == true) {
			return &gSpriteClips[1][1];
		}
		break;
	}

	return currClip;


	/*if (this->isBottom == true && this->isIdle == false) {
		currClip = &gSpriteClips[0][this->currFrameY / 3];
		currFrameY++;
		if (currFrameY / 3 == 3) {
			currFrameY = 0;
		}
	}

	if (this->isLeft == true && this->isIdle == false) {
		currClip = &gSpriteClips[1][this->currFrameY / 3];
		currFrameY++;
		if (currFrameY / 3 == 3) {
			currFrameY = 0;
		}
	}*/

	/*if (this->isRight == true && this->isIdle == false) {
		currClip = &gSpriteClips[2][this->currFrameY / 3];
		currFrameY++;
		if (currFrameY / 3 == 3) {
			currFrameY = 0;
		}
	}

	if (this->isTop == true && this->isIdle == false) {
		currClip = &gSpriteClips[3][this->currFrameY / 3];
		currFrameY++;
		if (currFrameY / 3 == 3) {
			currFrameY = 0;
		}
	}*/
	
	/*if (this->isIdle == true && this->endBottom == true) {
		return &gSpriteClips[0][1];
	}

	if (this->isIdle == true && this->endTop == true) {
		return &gSpriteClips[3][1];
	}

	if (this->isIdle == true && this->endRight == true) {
		return &gSpriteClips[2][1];
	}

	if (this->isIdle == true && this->endLeft == true) {
		return &gSpriteClips[1][1];
	}*/

	/*if (this->isIdle == true) {
		return &gSpriteClips[0][0];
	}*/

	/*currFrameX++;
	currFrameY++;

	if (currFrameX / 3 == 3) {
		currFrameX = 0;
	}

	if (currFrameY / 4 == 4) {
		currFrameY = 0;
	}*/

}