#include "background.h"

sfVector2f mousePosMenu;

sfTexture* bgTexture;
sfSprite* bgSprite;

sfIntRect bgRect = { 0, 0, 1920, 1080 };

int frame_X1;
int frame_Y1;

void initBackground(sfRenderWindow* _window) {

	bgSprite = sfSprite_create();
	bgTexture = sfTexture_createFromFile("..\\Ressources\\Textures\\backgroundBattle.png", NULL);

	frame_X1 = 0;
	frame_Y1 = 0;

	sfSprite_setTexture(bgSprite, bgTexture, sfTrue);
	sfSprite_setPosition(bgSprite, vector2f(0.f, 0.f));
	sfSprite_setTextureRect(bgSprite, bgRect);
}

void updateBackground(sfRenderWindow* _window) {
	bgRect.left = frame_X1 * bgRect.width;
	bgRect.top = frame_Y1 * bgRect.height;

	sfSprite_setTextureRect(bgSprite, bgRect);

	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		frame_X1 = 1;
		bgRect.left = frame_X1 * bgRect.width;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyB)) 
	{
		frame_X1 = 0;
		bgRect.left = frame_X1 * bgRect.width;

	}
	else if (sfKeyboard_isKeyPressed(sfKeyV)) 
	{
		frame_X1 = 2;
		bgRect.left = frame_X1 * bgRect.width;

	}
	else if (sfKeyboard_isKeyPressed(sfKeyC))
	{
		frame_X1 = 3;
		bgRect.left = frame_X1 * bgRect.width;
	}
	sfSprite_setTextureRect(bgSprite, bgRect);
}

void displayBackground(sfRenderWindow* _window) {
	sfRenderWindow_drawSprite(_window, bgSprite, NULL);
}







































/*#include "menu.h"

ParticlesContainer* particle2;
sfVector2f mousePosMenu;

sfTexture* bgTexture;
sfSprite* bgSprite;

sfTexture* bandeauTexture;
sfSprite* bandeauSprite;

sfTexture* logoStartTexture;
sfSprite* logoStartSprite;

sfTexture* blackScreenTexture;
sfSprite* blackScreenSprite;

// Animation
static int animCountStartMenu;
static int animCountEndMenu;
sfTexture* animStartGameUnfinished;
sfTexture* animEndGameUnfinished;

sfSprite* animMenu;
sfSprite* animMenuEnd;
sfBool isAnimMenuAdvenruePlayed;
sfBool isAnimMenuQuitPlayed;

// Selection Icons
sfTexture* selecTexture;
sfSprite* selecSprite;

sfIntRect selecRect = { 0,0,700,745 };

int frameXselec;
int frameYselec;

// Main menu bgs

sfIntRect bg1Global;
sfIntRect bg2Global;
sfIntRect bg3Global;
sfIntRect bg4Global;

// Adventure bg
sfTexture* bgTexture;
sfSprite* bgSprite;

sfIntRect bgRect1 = { 0,0,442,84 };

int frame_X1;
int frame_Y1;
//  Reglages bg
sfSprite* bg2Sprite;

sfIntRect bgRect2 = { 0,0,442,84 };

int frame_X2;
int frame_Y2;
// Bonus bg
sfSprite* bg3Sprite;

sfIntRect bgRect3 = { 0,0,442,84 };

int frame_X3;
int frame_Y3;
// Quitter bg
sfSprite* bg4Sprite;

sfIntRect bgRect4 = { 0,0,442,84 };

int frame_X4;
int frame_Y4;

sfBool isSelected;
sfBool isFadedIn;
sfBool isMainThemePlaying;
sfColor colorFade;



int lastSelec;
int menuSelection;
// pour les setingsfaire dans le settings.c et vérifier sile state est à Menu ou est à game !
void initMenu(Window* _window) {
	Texture_Onload(MENU);
	Sound_Onload(MENU);
	Font_OnLoad(MENU);

	sfMusic_setLoop(getMainThemeMusic(), sfTrue);
	
	animMenu = sfSprite_create();
	animMenuEnd = sfSprite_create();
	animCountStartMenu = 1;
	animCountEndMenu = 1;
	isAnimMenuAdvenruePlayed = sfFalse;
	isAnimMenuQuitPlayed = sfFalse;

	bgSprite = sfSprite_create();
	bgTexture = sfTexture_createFromFile(PATH_MENU"bg.png", NULL);
	sfSprite_setTexture(bgSprite, bgTexture, sfTrue);
	sfSprite_setColor(bgSprite, sfColor_fromRGB(0, 0, 0));

	bandeauSprite = sfSprite_create();
	bandeauTexture = sfTexture_createFromFile(PATH_MENU"bandeauEng.png", NULL);
	sfSprite_setTexture(bandeauSprite, bandeauTexture, sfTrue);
	sfSprite_setPosition(bandeauSprite, vector2f(1.f, 0.f));
	sfSprite_setColor(bandeauSprite, sfColor_fromRGB(0, 0, 0));

	logoStartSprite = sfSprite_create();
	logoStartTexture = sfTexture_createFromFile(PATH_MENU"logoStart.png", NULL);
	sfSprite_setTexture(logoStartSprite, logoStartTexture, sfTrue);
	sfSprite_setPosition(logoStartSprite, vector2f(269.f, 30.f));
	sfSprite_setColor(logoStartSprite, sfColor_fromRGB(0, 0, 0));

	blackScreenSprite = sfSprite_create();
	blackScreenTexture = sfTexture_createFromFile(PATH_MENU"black_bg.png", NULL);
	sfSprite_setTexture(blackScreenSprite, blackScreenTexture, sfTrue);
	sfSprite_setColor(blackScreenSprite, sfColor_fromRGBA(255, 255, 255, 0));

	// Main menu bgs
	bgSprite = sfSprite_create();
	bg2Sprite = sfSprite_create();
	bg3Sprite = sfSprite_create();
	bg4Sprite = sfSprite_create();


	frame_X1 = 0;
	frame_Y1 = 0;

	frame_X2 = 0;
	frame_Y2 = 1;

	frame_X3 = 0;
	frame_Y3 = 2;

	frame_X4 = 0;
	frame_Y4 = 3;

	if (getLanguage() == ENGLISH) {

		bgRect1.width = 442;
		bgRect2.width = 442;
		bgRect3.width = 442;
		bgRect4.width = 442;

		bgTexture = sfTexture_createFromFile(PATH_MENU"bgEngMenu.png", NULL);
	}
	if (getLanguage() == FRENCH) {
		bgRect1.width = 396;
		bgRect2.width = 396;
		bgRect3.width = 396;
		bgRect4.width = 396;

		bgTexture = sfTexture_createFromFile(PATH_MENU"bgFraMenu.png", NULL);
	}
	

	bgRect1.left = frame_X1 * bgRect1.width;
	bgRect1.top = frame_Y1 * bgRect1.height;

	bg1Global.left = bgRect1.left + 184.f;
	bg1Global.top = bgRect1.top + 438.f;
	bg1Global.width = bgRect1.width;
	bg1Global.height = bgRect1.height;


	bgRect2.left = frame_X2 * bgRect2.width;
	bgRect2.top = frame_Y2 * bgRect2.height;

	bg2Global.left = bgRect2.left + 184.f;
	bg2Global.top = bgRect2.top + 457.f;
	bg2Global.width = bgRect2.width;
	bg2Global.height = bgRect2.height;


	bgRect3.left = frame_X3 * bgRect3.width;
	bgRect3.top = frame_Y3 * bgRect3.height;

	bg3Global.left = bgRect3.left + 184.f;
	bg3Global.top = bgRect3.top + 476.f;
	bg3Global.width = bgRect3.width;
	bg3Global.height = bgRect3.height;


	bgRect4.left = frame_X4 * bgRect4.width;
	bgRect4.top = frame_Y4 * bgRect4.height;

	bg4Global.left = bgRect4.left + 184.f;
	bg4Global.top = bgRect4.top + 495.f;
	bg4Global.width = bgRect4.width;
	bg4Global.height = bgRect4.height;

	sfSprite_setTexture(bgSprite, bgTexture, sfTrue);
	sfSprite_setPosition(bgSprite, vector2f(184.f, 438.f));
	sfSprite_setTextureRect(bgSprite, bgRect1);

	sfSprite_setTexture(bg2Sprite, bgTexture, sfTrue);
	sfSprite_setPosition(bg2Sprite, vector2f(184.f, 557.f));
	sfSprite_setTextureRect(bg2Sprite, bgRect2);

	sfSprite_setTexture(bg3Sprite, bgTexture, sfTrue);
	sfSprite_setPosition(bg3Sprite, vector2f(184.f, 665.f));
	sfSprite_setTextureRect(bg3Sprite, bgRect3);

	sfSprite_setTexture(bg4Sprite, bgTexture, sfTrue);
	sfSprite_setPosition(bg4Sprite, vector2f(184.f, 770.f));
	sfSprite_setTextureRect(bg4Sprite, bgRect4);

	sfSprite_setColor(bgSprite, sfColor_fromRGB(0, 0, 0));
	sfSprite_setColor(bg2Sprite, sfColor_fromRGB(0, 0, 0));
	sfSprite_setColor(bg3Sprite, sfColor_fromRGB(0, 0, 0));
	sfSprite_setColor(bg4Sprite, sfColor_fromRGB(0, 0, 0));

	SetViewPosition(mainView, vector2f(mainView->defaultVideoMode.x / 2.0f, mainView->defaultVideoMode.y / 2.0f));

	// Selection Icons
	frameXselec = 0;
	frameYselec = 0;

	selecRect.left = frameXselec * selecRect.width;
	selecRect.top = frameYselec * selecRect.height;

	selecSprite = sfSprite_create();
	selecTexture = sfTexture_createFromFile(PATH_MENU"iconeSelec.png", NULL);
	sfSprite_setTexture(selecSprite, selecTexture, sfTrue);
	sfSprite_setTextureRect(selecSprite, selecRect);
	sfSprite_setPosition(selecSprite, vector2f(1014.f, 191.f));

	isSelected = sfFalse;
	isFadedIn = sfFalse;
	isMainThemePlaying = sfFalse;
	menuSelection = 0;
}

void updateEventMenu(Window* _window) {

}

void updateMenu(Window* _window, State _state) {
	static float timer = 0.0f;
	static float timerAdvenrue = 0.0f;
	static float timerQuit = 0.0f;
	static float timerFadeIn = 0.0f;

	timer += GetDeltaTime();
	cursorNeutral();

	if (!isFadedIn) {
		timerFadeIn += GetDeltaTime();
		if (timerFadeIn >= 3.f) isFadedIn = sfTrue;
		fadeInMenu(bgSprite);
		fadeInMenu(bandeauSprite);
		fadeInMenu(logoStartSprite);
		fadeInMenu(bgSprite);
		fadeInMenu(bg2Sprite);
		fadeInMenu(bg3Sprite);
		fadeInMenu(bg4Sprite);
	}


	if (isAnimMenuAdvenruePlayed) timerAdvenrue += GetDeltaTime();
	if (timerAdvenrue >= 1.5f) if (_state != CINEMATIC_INTRO) setStateMain(_window, CINEMATIC_INTRO);

	if (isAnimMenuQuitPlayed) timerQuit += GetDeltaTime();
	if (timerQuit >= 1.5f) quick_exit(0);

	mousePosMenu = getFloatMousePos(_window->renderWindow);

	bgRect1.left = frame_X1 * bgRect1.width;
	bgRect1.top = frame_Y1 * bgRect1.height;

	bgRect2.left = frame_X2 * bgRect2.width;
	bgRect2.top = frame_Y2 * bgRect2.height;

	bgRect3.left = frame_X3 * bgRect3.width;
	bgRect3.top = frame_Y3 * bgRect3.height;

	bgRect4.left = frame_X4 * bgRect4.width;
	bgRect4.top = frame_Y4 * bgRect4.height;

	sfSprite_setTextureRect(bgSprite, bgRect1);
	sfSprite_setTextureRect(bg2Sprite, bgRect2);
	sfSprite_setTextureRect(bg3Sprite, bgRect3);
	sfSprite_setTextureRect(bg4Sprite, bgRect4);

	frameXselec = lastSelec;
	selecRect.left = frameXselec * selecRect.width;
	sfSprite_setTextureRect(selecSprite, selecRect);

	if (sfIntRect_contains(&bg1Global, mousePosMenu.x, mousePosMenu.y)) // Bouton advenrue
	{
		cursorHover();
		frame_X1 = 1;
		bgRect1.left = frame_X1 * bgRect1.width;
		sfSprite_setTextureRect(bgSprite, bgRect1);

		frame_X2 = 0;
		bgRect2.left = frame_X2 * bgRect2.width;
		sfSprite_setTextureRect(bg2Sprite, bgRect2);

		frame_X3 = 0;
		bgRect3.left = frame_X3 * bgRect3.width;
		sfSprite_setTextureRect(bg3Sprite, bgRect3);

		frame_X4 = 0;
		bgRect4.left = frame_X4 * bgRect4.width;
		sfSprite_setTextureRect(bg4Sprite, bgRect4);

		if (lClick(_window))
		{
			isAnimMenuAdvenruePlayed = sfTrue;
			cursorGrab();
			
		}

		frameXselec = 0;
		lastSelec = 0;
		selecRect.left = frameXselec * selecRect.width;
		sfSprite_setTextureRect(selecSprite, selecRect);
		

	}
	else if (sfIntRect_contains(&bg2Global, mousePosMenu.x, mousePosMenu.y)) // Bouton réglage
	{
		cursorHover();
		frame_X1 = 0;
		bgRect1.left = frame_X1 * bgRect1.width;
		sfSprite_setTextureRect(bgSprite, bgRect1);

		frame_X2 = 1;
		bgRect2.left = frame_X2 * bgRect2.width;
		sfSprite_setTextureRect(bg2Sprite, bgRect2);

		frame_X3 = 0;
		bgRect3.left = frame_X3 * bgRect3.width;
		sfSprite_setTextureRect(bg3Sprite, bgRect3);

		frame_X4 = 0;
		bgRect4.left = frame_X4 * bgRect4.width;
		sfSprite_setTextureRect(bg4Sprite, bgRect4);
			
		frameXselec = 1;
		lastSelec = 1;
		selecRect.left = frameXselec * selecRect.width;
		sfSprite_setTextureRect(selecSprite, selecRect);
			
		if (lClick(_window) && timer > 0.2f) {
			cursorGrab();
			selecRect.left = frameXselec * selecRect.width;
			sfSprite_setTextureRect(selecSprite, selecRect);
			if (!isOption) toggleOptions();

			frameXselec = -1;
			selecRect.left = frameXselec * selecRect.width;
			sfSprite_setTextureRect(selecSprite, selecRect);

			timer = 0.f;
		}

	}
	else if (sfIntRect_contains(&bg3Global, mousePosMenu.x, mousePosMenu.y)) // Bouton Bonus
	{
		cursorHover();
		frame_X1 = 0;
		bgRect1.left = frame_X1 * bgRect1.width;
		sfSprite_setTextureRect(bgSprite, bgRect1);

		frame_X2 = 0;
		bgRect2.left = frame_X2 * bgRect2.width;
		sfSprite_setTextureRect(bg2Sprite, bgRect2);

		frame_X3 = 1;
		bgRect3.left = frame_X3 * bgRect3.width;
		sfSprite_setTextureRect(bg3Sprite, bgRect3);

		frame_X4 = 0;
		bgRect4.left = frame_X4 * bgRect4.width;
		sfSprite_setTextureRect(bg4Sprite, bgRect4);

		if (lClick(_window)) cursorGrab();

		frameXselec = 2;
		lastSelec = 2;
		selecRect.left = frameXselec * selecRect.width;
		sfSprite_setTextureRect(selecSprite, selecRect);
		
	}
	else if (sfIntRect_contains(&bg4Global, mousePosMenu.x, mousePosMenu.y)) // Bouton Quitter
	{
		cursorHover();
		frame_X1 = 0;
		bgRect1.left = frame_X1 * bgRect1.width;
		sfSprite_setTextureRect(bgSprite, bgRect1);

		frame_X2 = 0;
		bgRect2.left = frame_X2 * bgRect2.width;
		sfSprite_setTextureRect(bg2Sprite, bgRect2);

		frame_X3 = 0;
		bgRect3.left = frame_X3 * bgRect3.width;
		sfSprite_setTextureRect(bg3Sprite, bgRect3);
		
		frame_X4 = 1;
		bgRect4.left = frame_X4 * bgRect4.width;
		sfSprite_setTextureRect(bg4Sprite, bgRect4);

		if (lClick(_window)) {
			cursorGrab();
			isAnimMenuQuitPlayed = sfTrue;
		}
		frameXselec = 3;
		lastSelec = 3;
		selecRect.left = frameXselec * selecRect.width;
		sfSprite_setTextureRect(selecSprite, selecRect);
	}
	
	if (isAnimMenuAdvenruePlayed || isAnimMenuQuitPlayed) animEnd();

	if (isMainThemePlaying == sfFalse) {
		sfMusic_play(getMainThemeMusic());
		isMainThemePlaying = sfTrue;
	}

	sfMusic_setVolume(getMainThemeMusic(), config.volumeMusic);
		
}

void animStart() {
	static float timer = 0.0f;
	char path[128] = "e";
	fadeInOpacityMenu(selecSprite);

	timer += GetDeltaTime();
	if (timer >= 0.08f && animCountStartMenu <= 16) {
		if (getLanguage() == ENGLISH) sprintf(path, PATH_MENU"animation_menu\\start_en\\open\\%d.png", animCountStartMenu);
		else if (getLanguage() == FRENCH) sprintf(path, PATH_MENU"animation_menu\\start_fr\\open\\%d.png", animCountStartMenu);
		if (sfSprite_getTexture(animMenu) != NULL) sfTexture_destroy(sfSprite_getTexture(animMenu));
		animStartGameUnfinished = (sfTexture_createFromFile(path, NULL));
		sfSprite_setTexture(animMenu, animStartGameUnfinished, sfTrue);
		timer = 0.f;
		animCountStartMenu++;
	}
}

void animEnd() {
	static float timer = 0.0f;
	char path[128] = "e";
	//fadeOutOpacityMenu(selecSprite);
	//fadeOutMenu(animMenuEnd);
	fadeInBlackScreenMenu(blackScreenSprite);
	fadeOutMenu(bgSprite);
	fadeOutMenu(bandeauSprite);
	fadeOutMenu(logoStartSprite);
	fadeOutMenu(bgSprite);
	fadeOutMenu(bg2Sprite);
	fadeOutMenu(bg3Sprite);
	fadeOutMenu(bg4Sprite);

	timer += GetDeltaTime();
	if (timer >= 0.08f && animCountEndMenu <= 16) {
		if (getLanguage() == ENGLISH) sprintf(path, PATH_MENU"animation_menu\\start_en\\close\\%d.png", animCountEndMenu);
		else if (getLanguage() == FRENCH) sprintf(path, PATH_MENU"animation_menu\\start_fr\\close\\%d.png", animCountEndMenu);
		if (sfSprite_getTexture(animMenuEnd) != NULL) sfTexture_destroy(sfSprite_getTexture(animMenuEnd));
		animEndGameUnfinished = (sfTexture_createFromFile(path, NULL));
		sfSprite_setTexture(animMenuEnd, animEndGameUnfinished, sfTrue);
		timer = 0.f;
		animCountEndMenu++;
	}
}

void displayMenu(Window* _window) {
	sfRenderWindow_drawSprite(_window->renderWindow, bgSprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, bandeauSprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, logoStartSprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, bgSprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, bg2Sprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, bg3Sprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, bg4Sprite, NULL);
	if (animCountStartMenu < 16) sfRenderWindow_drawSprite(_window->renderWindow, animMenu, NULL);
	if (animCountEndMenu < 16) sfRenderWindow_drawSprite(_window->renderWindow, animMenuEnd, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, selecSprite, NULL);
	sfRenderWindow_drawSprite(_window->renderWindow, blackScreenSprite, NULL);
}

void deinitMenu() {
	sfMusic_stop(getMainThemeMusic());
	sfMusic_destroy(getMainThemeMusic());

	sfSprite_destroy(bgSprite);
	sfSprite_destroy(bandeauSprite);
	sfSprite_destroy(logoStartSprite);
	sfSprite_destroy(bgSprite);
	sfSprite_destroy(bg2Sprite);
	sfSprite_destroy(bg3Sprite);
	sfSprite_destroy(bg4Sprite);
	sfSprite_destroy(selecSprite);
	sfSprite_destroy(animMenu);
	sfSprite_destroy(animMenuEnd);
	
	sfTexture_destroy(bgTexture);
	sfTexture_destroy(bandeauTexture);
	sfTexture_destroy(logoStartTexture);
	sfTexture_destroy(bgTexture);
	sfTexture_destroy(selecTexture);
}

// Tools
void fadeInOpacityMenu(sfSprite* _sprite) {
	static float timerOpacityFinalScene = 0.f;
	static int opacityFade = 0;
	timerOpacityFinalScene += GetDeltaTime();
	if (timerOpacityFinalScene >= 0.0128f && opacityFade < 255) {
		opacityFade++;
		colorFade = sfColor_fromRGBA(255, 255, 255, opacityFade);
		sfSprite_setColor(_sprite, colorFade);
		timerOpacityFinalScene = 0.f;
	}
}

void fadeInBlackScreenMenu(sfSprite* _sprite) {
	static float timerOpacityFinalScene = 0.f;
	static int opacityFade = 0;
	timerOpacityFinalScene += GetDeltaTime();
	if (timerOpacityFinalScene >= 0.00128f) {
		if (opacityFade < 255) {
			opacityFade++;
			colorFade = sfColor_fromRGBA(255, 255, 255, opacityFade);
			sfSprite_setColor(_sprite, colorFade);
			timerOpacityFinalScene = 0.f;
		}
	}
}

void fadeOutOpacityMenu(sfSprite* _sprite) {
	static float timerOpacityFinalScene = 0.f;
	static int opacityFade = 255;
	timerOpacityFinalScene += GetDeltaTime();
	if (timerOpacityFinalScene >= 0.00128f && opacityFade > 0) {
		opacityFade--;
		colorFade = sfColor_fromRGBA(255, 255, 255, opacityFade);
		sfSprite_setColor(_sprite, colorFade);
		timerOpacityFinalScene = 0.f;
	}
}

void fadeInMenu(sfSprite* _sprite) {
	static float timerOpacityFinalScene = 0.f;
	static int blackFade = 0;
	timerOpacityFinalScene += GetDeltaTime();
	if (timerOpacityFinalScene >= 0.016f && blackFade < 255) {
		blackFade++;
		colorFade = sfColor_fromRGBA(blackFade, blackFade, blackFade, 255);
		sfSprite_setColor(_sprite, colorFade);
		timerOpacityFinalScene = 0.f;
	}
}

void fadeOutMenu(sfSprite* _sprite) {
	static float timerOpacityFinalScene = 0.f;
	static int blackFade = 255;
	timerOpacityFinalScene += GetDeltaTime();
	if (timerOpacityFinalScene >= 0.016f && blackFade > 0) {
		blackFade--;
		colorFade = sfColor_fromRGBA(blackFade, blackFade, blackFade, 255);
		sfSprite_setColor(_sprite, colorFade);
		timerOpacityFinalScene = 0.f;
	}
}

*/