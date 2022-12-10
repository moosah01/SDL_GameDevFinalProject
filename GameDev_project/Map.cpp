#include "Map.h"
#include "Obstacles.h"

const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;

Map::Map(SDL_Renderer* gameRenderer)
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {

			if (this->map[i][j] == 1) {
				this->tiles[i][j] = new Obstacles();

				this->tiles[i][j]->unitBounds->x = TILE_WIDTH * i;
				this->tiles[i][j]->unitBounds->y = TILE_HEIGHT * j;
				this->tiles[i][j]->unitBounds->w = TILE_WIDTH;
				this->tiles[i][j]->unitBounds->h = TILE_HEIGHT;

				this->tiles[i][j]->setTexture(gameRenderer, "media/wall_center.png");
			}

			else if (this->map[i][j] == 2) {
				this->tiles[i][j] = new Obstacles();

				this->tiles[i][j]->unitBounds->x = TILE_WIDTH * i;
				this->tiles[i][j]->unitBounds->y = TILE_HEIGHT * j;
				this->tiles[i][j]->unitBounds->w = TILE_WIDTH;
				this->tiles[i][j]->unitBounds->h = TILE_HEIGHT;

				this->tiles[i][j]->setTexture(gameRenderer, "media/blueTile.png");
			}
			else {
				this->tiles[i][j] = new Obstacles();

				this->tiles[i][j]->unitBounds->x = TILE_WIDTH * i;
				this->tiles[i][j]->unitBounds->y = TILE_HEIGHT * j;
				this->tiles[i][j]->unitBounds->w = TILE_WIDTH;
				this->tiles[i][j]->unitBounds->h = TILE_HEIGHT;

				this->tiles[i][j]->objectType = 0;
				this->tiles[i][j]->setTexture(gameRenderer, "media/emptyPNG.png");
			}
		}
	}
}

void Map::RenderMap(SDL_Renderer* gameRenderer)
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {

			if (this->tiles[i][j]->unitBounds != NULL && this->tiles[i][j]->unitTexture != NULL) {
				SDL_RenderCopy(gameRenderer, this->tiles[i][j]->unitTexture, NULL, this->tiles[i][j]->unitBounds);
			}
		}
	}
}

Map::~Map()
{

}