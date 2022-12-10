#define SDL_MAIN_HANDLED
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "GameObject.h"
#include "Player.h"
#include "Map.h"
#include "FogOfWar.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

const int CAMERA_WIDTH = 200;
const int CAMERA_HEIGHT = 200;

int frameStart;
int frameTime;
int frameDelay = 25;


bool moveRight = true;
bool moveLeft = true;
bool moveDown = true;
bool moveUp = true;

bool canMove = true;


int main(int argc, char* argv)
{
	SDL_Renderer* gameRenderer;
	SDL_Surface* background;
	SDL_Surface* WindowSurface;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL Failed to initialize. Error Code : " << SDL_GetError() << std::endl;
	}

	SDL_Window* window = SDL_CreateWindow("Game Dev Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	WindowSurface = SDL_GetWindowSurface(window);

	if (window == NULL) {
		std::cout << "Could not initialize SDL Window. Error Code : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (~(IMG_Init(IMG_INIT_PNG)) & IMG_INIT_PNG) {
		std::cout << "Could not initialize PNG. Error Code : " << SDL_GetError() << std::endl;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	//SDL_Event window_event;
	background = IMG_Load("media/game_BG.jpg");
	if (background == NULL) {
		std::cout << "Could not load background image. Error Code : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	bool game_running = true;
	SDL_Rect* background_Rect = new SDL_Rect();
	background_Rect->w = SCREEN_WIDTH;
	background_Rect->h = SCREEN_HEIGHT;
	background_Rect->x = 0;
	background_Rect->y = 0;
	SDL_Texture* game_BG = IMG_LoadTexture(gameRenderer, "media/game_BG.jpg");

	SDL_Event window_event;

	Player* player1 = new Player();
	player1->SetParameters(gameRenderer, "media/Player_PokemonSprite.png", 64, 64, 32, 32);
	
	Map* map1 = new Map(gameRenderer);
	FogOfWar* fog1 = new FogOfWar(gameRenderer);


	int itemLocX = 0;
	int itemLocY = 0;

	int playerLocX = 0;
	int playerLocY = 0;
	int playerWidth = 32;
	int playerHeight = 32;

	int itemWidth = 0;
	int itemHeight = 0;

	int xDiff = 0;
	int yDiff = 0;
	int objectType = 0;

	int gameFrames = 0;

	SDL_Rect camera = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };


	float xyz = -9.75;
	int test = int(xyz);

	printf("%d", test);

	while (game_running) 
	{
		frameStart = SDL_GetTicks();
		if (SDL_PollEvent(&window_event)) 
		{
			if (SDL_QUIT == window_event.type) 
			{
				break;
			}
			if (SDL_KEYDOWN == window_event.type) 
			{
				if (canMove == true) {
					if (SDLK_DOWN == window_event.key.keysym.sym) {
						if (moveDown) {
							player1->Translate(0, 10);
							player1->isIdle = false;
			
							moveUp= true;
							moveRight = true;
							moveLeft = true;
							canMove = false;
						}

					}
					if (SDLK_UP == window_event.key.keysym.sym) {
						if (moveUp) {
							player1->isIdle = false;
							player1->Translate(0, -10);
							
							moveDown = true;
							moveRight = true;
							moveLeft = true;
							// 
							canMove = false;
						}
					}
					if (SDLK_LEFT == window_event.key.keysym.sym) {
						if (moveLeft) {
							player1->Translate(-10, 0);
							
							moveDown = true;
							moveRight = true;
							moveUp = true;
							player1->isIdle = false;
							canMove = false;
						}
					}
					if (SDLK_RIGHT == window_event.key.keysym.sym) {
						if (moveRight) {
							player1->Translate(10, 0);
							player1->isIdle = false;
							moveDown = true;
							moveUp = true;
							moveLeft = true;
							canMove = false;
						}
					}
					if (SDLK_SPACE == window_event.key.keysym.sym) {

					}
					if (SDLK_b == window_event.key.keysym.sym) {

					}
					if (SDLK_ESCAPE == window_event.key.keysym.sym)
					{
						game_running = false;
						break;
					}
					
				}	
			}
		}
		//canMove = true;

		gameFrames++;
		//std::cout << frameStart << std::endl;
		if (gameFrames % 10 == 0) {
			canMove = true;

			//std::cout << "Ia m here" << std::endl;
		}
		
		SDL_SetRenderDrawBlendMode(gameRenderer, SDL_BLENDMODE_BLEND);
		

		SDL_RenderCopy(gameRenderer, game_BG, NULL, background_Rect);
		map1->RenderMap(gameRenderer);
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {

				playerLocX = player1->unitBounds->x;
				playerLocY = player1->unitBounds->y;

				/*xDiff = player1->unitBounds->x - map1->tiles[i][j]->unitBounds->x;
				yDiff = player1->unitBounds->y - map1->tiles[i][j]->unitBounds->y;*/

				objectType = map1->tiles[i][j]->objectType;
				if (objectType == 1) {
					//std::cout << objectType << std::endl;

					itemLocX = map1->tiles[i][j]->unitBounds->x;
					itemLocY = map1->tiles[i][j]->unitBounds->y;
					itemWidth = map1->tiles[i][j]->unitBounds->w;
					itemHeight = map1->tiles[i][j]->unitBounds->h;

					if (
						(playerLocX + playerWidth >= itemLocX) && (playerLocX <= itemLocX + itemWidth) //checking in X direction
						&&
						(playerLocY + playerHeight >= itemLocY) && (playerLocY <= itemLocY + itemHeight)	//checking in y direction		 
						) 
					{
						//check if player is at the top of wall
						switch (player1->dir)
						{
						case Bottom:
							if (playerLocY + playerHeight > itemLocY && playerLocY + playerHeight < itemLocY + itemHeight) {
								if (playerLocX == itemLocX) {
									std::cout << "Colliding with top of wall" << std::endl;	
									player1->unitBounds->y = player1->Snapping(itemLocY - itemHeight);
									player1->unitBounds->x = player1->Snapping(itemLocX);

									//player1->unitBounds->y = player1->unitBounds->y - 5;
									//moveDown = false;
								}
							}
							break;
						case Top:
							if (playerLocY > itemLocY && playerLocY < itemLocY + itemHeight) {
								if (playerLocX == itemLocX) {
									std::cout << "Colliding with bottom of wall" << std::endl;
									player1->unitBounds->y = player1->Snapping(itemLocY + itemHeight +16);
									player1->unitBounds->x = player1->Snapping(itemLocX);
									//player1->unitBounds->y = player1->unitBounds->y + 5;
									//moveUp = false;
								}
							}
							break;

						case Right: //player is at left of wall
							if (playerLocX + playerWidth > itemLocX && playerLocX + playerWidth < itemLocX + itemWidth) {
								if (playerLocY == itemLocY) {
									std::cout << "Colliding with left of wall" << std::endl;
									player1->unitBounds->x = player1->Snapping(itemLocX - itemWidth);
									player1->unitBounds->y = player1->Snapping(itemLocY);
									//moveRight = false;
								}
							}
							break;

						case Left://player is at right of wall
							if (playerLocX > itemLocX && playerLocX < itemLocX + itemWidth) {
								if (playerLocY == itemLocY)
								{
									std::cout << "Colliding with right side of wall" << std::endl;
									//player1->unitBounds->x = itemLocX + itemWidth +1;
									player1->unitBounds->x = player1->Snapping(itemLocX + itemWidth +16);
									player1->unitBounds->y = player1->Snapping(itemLocY);
									//player1->unitBounds->x = player1->unitBounds->x + 5;
									//moveLeft = false;
								}
							}
							break;
						}
					}
				}
				else if (objectType == 0) {
				//	std::cout << "pussy" << std::endl;

				}
			}
		}

		
		player1->Move();
		SDL_RenderCopy(gameRenderer, player1->unitTexture, player1->getCurrentClip(), player1->unitBounds);

		//fog1->RenderFog(gameRenderer, player1->unitBounds->x / 32, player1->unitBounds->y / 32);
		//player1->drawArc(gameRenderer);
		//SDL_RenderDrawLine(gameRenderer, 10, 10, 100, 100);
		

		SDL_RenderPresent(gameRenderer);

		SDL_RenderClear(gameRenderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
		SDL_DestroyTexture(player1->unitTexture);

		SDL_FreeSurface(background);
		SDL_FreeSurface(WindowSurface);

		background = NULL;
		WindowSurface = NULL;

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(gameRenderer);

		SDL_Quit();
		return EXIT_SUCCESS;
}

