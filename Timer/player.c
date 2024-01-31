#include "player.h"
#define SPEED 100

sfTexture* spritesheet;
sfSprite* player;
sfIntRect irect = { 0, 0, 64, 64 };
float animTime;
int frameX;
int frameY;
sfBool isMoving;

sfVector2f playerpos;

void initPlayer()
{
	spritesheet = sfTexture_createFromFile("..\\Ressources\\Textures\\louka.png", NULL);
	player = sfSprite_create();
	sfSprite_setTexture(player, spritesheet, sfTrue);
	sfSprite_setScale(player, vector2f(0.66f, 0.66f));

	sfSprite_setTextureRect(player, irect);

	animTime = 0;
	frameX = 0;
	frameY = 0;
	isMoving = sfFalse;

	sfVector2f playerpos = vector2f(0, 0);

	sfSprite_setPosition(player, playerpos);
	
}

void updatePlayer() 
{
	isMoving = sfFalse;
	

	if (sfKeyboard_isKeyPressed(sfKeyD) && playerpos.x < 615) {
		frameY = 2;
		playerpos.x += SPEED * getDeltaTime();
		//sfSprite_setPosition(player, playerpos);
		isMoving = sfTrue;
		animTime += getDeltaTime();
	}
	else if (sfKeyboard_isKeyPressed(sfKeyZ) && playerpos.y >= 0) {
		frameY = 3;
		playerpos.y -= SPEED * getDeltaTime();
		//sfSprite_setPosition(player, playerpos);
		isMoving = sfTrue;
		animTime += getDeltaTime();
	}
	else if (sfKeyboard_isKeyPressed(sfKeyQ) && playerpos.x >= 0) {
		frameY = 1;
		playerpos.x -= SPEED * getDeltaTime();

		isMoving = sfTrue;
		animTime += getDeltaTime();
	}
	else if (sfKeyboard_isKeyPressed(sfKeyS) && playerpos.y <= 285) {
		frameY = 0;
		playerpos.y += SPEED * getDeltaTime();
		//sfSprite_setPosition(player, playerpos);
		isMoving = sfTrue;
		animTime += getDeltaTime();
	}
	else if (sfKeyboard_isKeyPressed(sfKeyA))
	{
		frameY = 4;
		animTime += getDeltaTime();
		isMoving = sfTrue;
	}
	if (isMoving) {
		if (animTime > 0.2) {
			frameX++;
			if (frameX > 3) {
				frameX = 0;
			}
			irect.left = frameX * irect.width;
			irect.top = frameY * irect.height;
			sfSprite_setTextureRect(player, irect);
			animTime = 0.0f;
		}

		}
		else {
			frameX = 0;
			irect.left = frameX * irect.width;
			sfSprite_setTextureRect(player, irect);
		}


		/*if (sfMouse_isButtonPressed(sfMouseLeft)) {
			sfVector2i mousePos = sfMouse_getPosition(_window);
			playerpos.x = mousePos.x;
			playerpos.y = mousePos.y;
		}*/

		sfSprite_setPosition(player, playerpos);
		updateCamera(playerpos);

}

void displayPlayer(sfRenderWindow * _window)
{
	sfRenderWindow_drawSprite(_window, player, NULL);
};