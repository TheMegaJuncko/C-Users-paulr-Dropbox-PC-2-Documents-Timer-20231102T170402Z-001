#pragma once
#include "SFML/Graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "camera.h"

void initTools();
float getDeltaTime();
void restartClock();
sfVector2f vector2f(float _x, float _y);