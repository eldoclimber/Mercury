#include "window.h"


bool window::init()
{
	//Init Flag
	success = true;
	imageSurface = SDL_LoadBMP("hello.bmp");
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//Console error printing
		//TODO: Print error to log file
		printf("SDL could not be initialized! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window from object
		makeWindow(imageSurface->w, imageSurface->h);
	
	}
	return success;
}


bool window::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	imageSurface = SDL_LoadBMP("hello.bmp");
	if (imageSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void window::makeWindow(int w, int h) {
		//Create window
		mainWindow = SDL_CreateWindow("Testing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
		if (mainWindow == NULL)
		{
			printf("SDL could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			mainSurface = SDL_GetWindowSurface(mainWindow);

			//Fill surface with white
			//SDL_FillRect(mainSurface, NULL, SDL_MapRGB(mainSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			//SDL_UpdateWindowSurface(mainWindow);


		}
	}

	void window::destroyWindow()
	{
		
		 //Deallocate surface
		SDL_FreeSurface(imageSurface);
		imageSurface = NULL;
		//Destroy window and clean up memory then quit subsystems
		SDL_DestroyWindow(mainWindow);
		SDL_Quit();
	}

	
	void window::keepOpen()
	{
		//Function to keep window open
		SDL_Event e;
		bool quit = false;
		while (quit == false)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
		}
	}