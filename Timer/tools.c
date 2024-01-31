#include "tools.h"

sfTime sftime;
sfClock* sfclock;

void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}

float getDeltaTime()
{
	return sfTime_asSeconds(sftime);
}

void restartClock()
{
	sftime = sfClock_restart(sfclock);
}

sfVector2f vector2f(float _x, float _y)
{
	sfVector2f v = { _x, _y };
	return v;
}

sfVector2i vector2i(int _x, int _y)
{
	sfVector2i i = { _x, _y };
	return i;
}