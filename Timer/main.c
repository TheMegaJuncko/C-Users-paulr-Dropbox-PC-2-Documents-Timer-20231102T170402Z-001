#include "map.h"
#include "player.h"
#include "musique.h"
#include "tools.h"
#include "background.h"
#include "state.h"

sfBool keepBothOpen = sfTrue;

void init() {
	initTools();
	initPlayer();
	initCamera();
	initMap();

	sonVille();
}

int main()
{
	init();
	sfEvent event;
	sfEvent event2;
	sfVideoMode mode = { 640, 320, 32 };
	sfVideoMode mode2 = { 640, 320, 32 };
	sfRenderWindow* window;
	sfRenderWindow* window2;
	window = sfRenderWindow_create(mode, "1", sfDefaultStyle, NULL);
	window2 = sfRenderWindow_create(mode, "2", sfDefaultStyle, NULL);
	sfRenderWindow_setPosition(window, vector2i(640, 200));
	sfRenderWindow_setPosition(window2, vector2i(640, 600));
	initBackground(window2);

	state = BATTLE;

	while (keepBothOpen == sfTrue) {

		if (sfRenderWindow_isOpen(window)) {

			restartClock();

			while (sfRenderWindow_pollEvent(window, &event)) {
				if (event.type == sfEvtClosed) {
					sfRenderWindow_close(window);
					keepBothOpen = sfFalse;
				}
			}
			if (state == PLAY) {
				updatePlayer();

				sfRenderWindow_clear(window, sfBlack);

				updateMap(window);

				displayMap(window);

				displayPlayer(window);

				displayCamera(window);
			}

			if (state == BATTLE) {
				updateBackground(window);

				displayBackground(window);
			}
			sfRenderWindow_display(window);
		}

		if (sfRenderWindow_isOpen(window2)) {
			restartClock();

			while (sfRenderWindow_pollEvent(window2, &event2)) {
				if (event2.type == sfEvtClosed) {
					sfRenderWindow_close(window2);
					keepBothOpen = sfFalse;
				}
			}

			sfRenderWindow_display(window2);
		}
	}
}