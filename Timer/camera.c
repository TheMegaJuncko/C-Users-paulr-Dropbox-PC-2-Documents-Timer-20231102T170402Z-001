#include "camera.h"

sfView* view;
sfVector2f center;
sfVector2f viewRect;
sfVector2f size;

sfView* miniMapView;

void initCamera()
{
    view = sfView_create();
    center = (sfVector2f){ 340, 160 };
    viewRect = (sfVector2f){ 340, 160 };
    size = (sfVector2f){ 680, 320 };

    //sfFloatRect viewPort = { 0, 0, 1, 1 };
    sfView_setSize(view, viewRect);

    /*miniMapView = sfView_create();
    sfFloatRect miniMapViewPort = { 0.75, 0, 0.25, 0.25 };
    sfView_setViewport(miniMapView, miniMapViewPort);*/
}

void updateCamera(sfVector2f _playerpos)
{
    sfView_setCenter(view, _playerpos);
}

void displayCamera(sfRenderWindow* _window)
{
    sfRenderWindow_setView(_window, view);
}
