#include "FogOfWar.h"

const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;

FogOfWar::FogOfWar(SDL_Renderer* gameRenderer)
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {

			if (this->fog[i][j] == 1) {
				this->fogTiles[i][j] = new GameObject();

				this->fogTiles[i][j]->unitBounds->x = TILE_WIDTH * i;
				this->fogTiles[i][j]->unitBounds->y = TILE_HEIGHT * j;
				this->fogTiles[i][j]->unitBounds->w = TILE_WIDTH;
				this->fogTiles[i][j]->unitBounds->h = TILE_HEIGHT;
				
				this->fogTiles[i][j]->setTexture(gameRenderer, "media/FogSquare.png");
				//this->fogTiles[i][j]->aplha = 220;
				//SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);

			}
		}
	}
}


void FogOfWar::RenderFog(SDL_Renderer* gameRenderer, int posX, int posY)
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {

			if (this->fogTiles[i][j]->unitBounds != NULL && this->fogTiles[i][j]->unitTexture != NULL) {

				//player pos will be brightest
				if ((i == posX) && (j == posY)) {
					this->fogTiles[i][j]->aplha = 175;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}

				//4 squares adjacent to player
				//top
				else if ((i == posX - 1) && (j == posY)) {
					this->fogTiles[i][j]->aplha = 175;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				//bottom
				else if ((i == posX + 1) && (j == posY)) {
					this->fogTiles[i][j]->aplha = 175;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				//left
				else if ((i == posX) && (j == posY - 1)) {
					this->fogTiles[i][j]->aplha = 175;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				//right
				else if ((i == posX) && (j == posY + 1)) {
					this->fogTiles[i][j]->aplha = 175;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				// END ^^^ => 4 squares adjacent to player

				//diagonals
				else if ((i == posX - 1) && (j == posY - 1)) {
					this->fogTiles[i][j]->aplha = 200;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				else if ((i == posX + 1) && (j == posY - 1)) {
					this->fogTiles[i][j]->aplha = 200;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				else if ((i == posX - 1) && (j == posY + 1)) {
					this->fogTiles[i][j]->aplha = 200;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				else if ((i == posX + 1) && (j == posY + 1)) {
					this->fogTiles[i][j]->aplha = 200;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				else {
					this->fogTiles[i][j]->aplha = 245;
					SDL_SetTextureAlphaMod(this->fogTiles[i][j]->unitTexture, this->fogTiles[i][j]->aplha);
				}
				SDL_RenderCopy(gameRenderer, this->fogTiles[i][j]->unitTexture, NULL, this->fogTiles[i][j]->unitBounds);

			}
		}
	}
}

FogOfWar::~FogOfWar()
{

}