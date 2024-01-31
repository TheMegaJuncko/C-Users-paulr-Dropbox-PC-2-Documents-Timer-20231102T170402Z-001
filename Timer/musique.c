#include "musique.h"
#include "SFML/Audio.h"

sfMusic* music;
sfMusic* music2;
sfBool* loop;

void sonVille() {
	music = sfMusic_createFromFile("x64\\Debug\\Bonaugure.ogg");

	sfMusic_play(music);

	sfSoundStatus sfMusic_getStatus(const sfMusic * music);
	void sfMusic_setLoop(sfMusic * music, sfBool loop);
	sfMusic_setLoop(music, sfTrue);
}
void sonMenu() {
	music2 = sfMusic_createFromFile("x64\\Debug\\Pokemon Platinum Opening.mp4");

	sfMusic_play(music);
}