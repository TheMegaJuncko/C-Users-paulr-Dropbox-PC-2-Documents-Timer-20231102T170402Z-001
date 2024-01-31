#include "state.h"
#include "tools.h"
#include "musique.h"

// Affichage du background des boutons et du titre

float delayVideo = 0.f;

sfTexture* bgTexture;
sfSprite* bgSprite;
sfVector2f bgOrigin = { 360.f, 202.5f };
sfVector2f bgPos = { -50.f, 0.f };
sfVector2f bgScale = { 1.5f, 1.5f };

sfTexture* titleTexture;
sfSprite* titleSprite;
sfVector2f titleOrigin = { 328.5f, 46.f };
sfVector2f titlePos = { 400.f, 100.f };
sfVector2f titleScale = { 1.f, 1.f };

sfTexture* playTexture;
sfSprite* playSprite;
sfVector2f playOrigin = { 140.f, 52.f };
sfVector2f playPos = { 400.f, 250.f };
sfVector2f playScale = { 0.75f, 0.75f };

sfTexture* editTexture;
sfSprite* editSprite;
sfVector2f editOrigin = { 140.f, 52.f };
sfVector2f editPos = { 400.f, 350.f };
sfVector2f editScale = { 0.75f, 0.75f };

sfTexture* quitTexture;
sfSprite* quitSprite;
sfVector2f quitOrigin = { 140.f, 52.f };
sfVector2f quitPos = { 400.f, 450.f };
sfVector2f quitScale = { 0.75f, 0.75f };

//Souris et Update des boutons
sfVector2i mousePos;
sfFloatRect playButton;
sfFloatRect editButton;
sfFloatRect quitButton;

//View du menu
sfView* menuCam;
sfVector2f menuCenter = { 400,300 };
sfVector2f menuRect = { 800,600 };

void initMenu()
{
	delayVideo += getDeltaTime();

	if (state == MENU) {
		sonMenu();
	}
	menuCam = sfView_create();
	sfView_setSize(menuCam, menuRect);

}

/*Au début le state est à menu et on display et update le menu, SI state est à (exemple) GAME, on display le jeu et on l'update*/


void updateMenu(sfRenderWindow* _window)
{
	if (sfKeyboard_isKeyPressed(sfKeyEnter) && delayVideo > 5.f) {
		state = MENU;
	}
}

void displayMenu(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, menuCam);
	sfRenderWindow_drawSprite(_window, bgSprite, NULL);
	sfRenderWindow_drawSprite(_window, titleSprite, NULL);
	sfRenderWindow_drawSprite(_window, playSprite, NULL);
	sfRenderWindow_drawSprite(_window, editSprite, NULL);
	sfRenderWindow_drawSprite(_window, quitSprite, NULL);
}