#pragma once
#include <SDL.h>
#include <stdio.h>

class window
{
private:
	//Screen name
	const char* WINDOW_NAME = "CAD Blueprint Project";
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;



	

	
	
	bool success = true;

public:
	//Main render window
	SDL_Window* mainWindow = NULL;

	//The surface for the image
	SDL_Surface* imageSurface = NULL;

	//The surface that is contained by the main window
	SDL_Surface* mainSurface = NULL;

	bool init();
	bool loadMedia();
	void makeWindow(int w, int h);
	void destroyWindow();
	void keepOpen();
};

