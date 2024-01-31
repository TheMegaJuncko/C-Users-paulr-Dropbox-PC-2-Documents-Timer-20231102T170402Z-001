#include "map.h"
#include "tools.h"
#define TEXTURE_PATH "..\\Ressources\\Textures\\"

sfSprite* tileSprite;
sfTexture* tileTexture;
sfIntRect tileRect;
sfVector2f tileposition = { 0,0 };
float delay, delayChest;
int chestFrameX;

sfSprite* tileSpriteChest;
sfTexture* tileTextureChest;
sfIntRect tileRectChest;

//x1 = left + width + vit * deltatime / 32
//y1 = top + width + vit * deltatime / 32
//x2 = left + height + vit * deltatime / 32
//y2 = top + height + vit * delta time / 32


int tile;


char map[10][20] = {
	{1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1},
	{1,1,1,4,1,1,1,1,1,1,3,3,1,1,4,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
	{1,1,1,1,1,1,1,1,1,3,3,3,1,1,1,1,1,4,1,4},
	{1,1,1,1,1,1,1,1,3,3,3,1,1,1,1,1,1,1,1,5},
	{1,4,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,6},
	{1,1,1,1,1,4,1,3,3,3,1,1,1,1,1,4,1,1,1,7},
	{1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1},
};

void initMap() {
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSprite = sfSprite_create();
	sfSprite_setTexture(tileSprite, tileTexture, sfTrue);
	tileRect.left = 0;
	tileRect.top = 0;
	tileRect.width = 32;
	tileRect.height = 32;
	delay = 0;
	tile = 0;
	delayChest = 0;
	chestFrameX = 0;

	tileTextureChest = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	tileSpriteChest = sfSprite_create();
	sfSprite_setTexture(tileSpriteChest, tileTextureChest, sfTrue);
}

void updateMap(sfRenderWindow* _window) {
	int x, y;
	
	delay += getDeltaTime();
	if (sfKeyboard_isKeyPressed(sfKeyB)) {
		if (delay > 0.2) {
			if (tile < 7) {
				tile++;
			}
			else {
				tile = 0;
			}
			delay = 0;
		}
	}

	if (sfKeyboard_isKeyPressed(sfKeyN)) {
		if (delay > 0.2) {
			
			if (tile > 0) {
				tile--;
			}
			else {
				tile = 7;
			}
			delay = 0;
		}
		
	}

	if (sfMouse_isButtonPressed(sfMouseRight)) {
		sfVector2i mousePosition = sfMouse_getPosition(_window);
		x = mousePosition.x / 32;
		y = mousePosition.y / 32;
		tile = map[y][x];
	}
	if (sfMouse_isButtonPressed(sfMouseLeft) ) {
		sfVector2i mousePosition = sfMouse_getPosition(_window);
		if (mousePosition.x < 640 && mousePosition.x >= 0 && mousePosition.y >= 0 && mousePosition.y <= 320) {
			x = mousePosition.x / 32;
			y = mousePosition.y / 32;
			map[y][x] = tile;
		}
	}
}

void displayMap(sfRenderWindow* _window) {
	delayChest += getDeltaTime();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] < 7) {
				tileRect.left = map[i][j] * 32;
				sfSprite_setTextureRect(tileSprite, tileRect);
				tileposition.x = j * 32;
				tileposition.y = i * 32;
				sfSprite_setPosition(tileSprite, tileposition);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			}
			else
			{
				if (delayChest > 0.2) {
					tileRect.left = chestFrameX * 32;
					chestFrameX++;
					if (chestFrameX > 3) chestFrameX = 0;
					sfSprite_setTextureRect(tileSpriteChest, tileRect);
					delayChest = 0;
				}
				tileposition.x = j * 32;
				tileposition.y = i * 32;
				sfSprite_setPosition(tileSpriteChest, tileposition);
				sfRenderWindow_drawSprite(_window, tileSpriteChest, NULL);
			}
			
		}
	}
	
}
