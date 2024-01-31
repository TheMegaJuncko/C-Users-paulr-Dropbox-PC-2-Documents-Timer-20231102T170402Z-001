#pragma once
#include "tools.h"

void initMenu();

void updateMenu(sfRenderWindow* _window);

void displayMenu(sfRenderWindow* _window);

typedef enum {
	EDITOR = 1,
	PLAY,
	MENU,
	BATTLE
} State;
State state;