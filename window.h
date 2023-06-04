#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>

class window
{
private:
	//Screen name
	const char* WINDOW_NAME = "CAD Blueprint Project";
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//Key Press Constants
	enum KeyPressSurfaces
	{
		KEY_PRESS_SURFACE_DEFAULT,
		KEY_PRESS_SURFACE_UP,
		KEY_PRESS_SURFACE_DOWN,
		KEY_PRESS_SURFACE_LEFT,
		KEY_PRESS_SURFACE_RIGHT,
		KEY_PRESS_SURFACE_TOTAL
	};

	

	
	
	bool success = true;

public:
	//Main render window **gWindow
	SDL_Window* mainWindow = NULL;

	//The surface for an image **gHelloWorld
	SDL_Surface* imageSurface = NULL;

	//The surface that is contained by the main window **gScreenSurface
	SDL_Surface* mainSurface = NULL;

	//Image that correstponds to keypress
	SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

	//Current displayed image
	SDL_Surface* currentSurface = NULL;

	//Loads individual image
	SDL_Surface* loadSurface(std::string path);

	bool init();
	bool loadMedia();
	void makeWindow(int w, int h);
	void destroyWindow();
	void mainLoop();
};

