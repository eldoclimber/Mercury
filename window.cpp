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
		makeWindow(imageSurface->w, imageSurface->h); // w and h are member variables in the surface object defined in the header 
	
	}
	return success;
}

// ********This is inital loadMedia state. Updated below
//bool window::loadMedia()
//{
//	//Loading success flag
//	bool success = true;
//
//	//Load splash image
//	imageSurface = SDL_LoadBMP("hello.bmp");
//	if (imageSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL Error: %s\n", "hello.bmp", SDL_GetError());
//		success = false;
//	}
//
//	return success;
//}

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

	
	void window::mainLoop()
	{
		//Function to keep window open
		SDL_Event e;	//SDL event object
		bool quit = false;	//Main function flag

		//Set default current surface
		currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)	// Process though event queue before repeating
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_UP:
						currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
						break;

					case SDLK_DOWN:
						currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
						break;

					case SDLK_LEFT:
						currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
						break;

					case SDLK_RIGHT:
						currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
						break;

					default:
						currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
						break;
					}
				}
				//Apply the current image
				SDL_BlitSurface(currentSurface, NULL, mainSurface, NULL);

				//Trying to dynamically resize the window
				/*imageSurface->w = currentSurface->w;
				imageSurface->h = currentSurface->h;
				SDL_SetWindowSize(mainWindow, imageSurface->w, imageSurface->h);*/

				//Update the surface
				SDL_UpdateWindowSurface(mainWindow);
			}
		}
	}

	
	SDL_Surface* window::loadSurface(std::string path)
	{
		//Load image at specified path
		SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		return loadedSurface;
	}

	bool window::loadMedia()
	{
		//Loading success flag
		bool success = true;

		//Load default surface
		keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("hello.bmp");
		if (keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
		{
			printf("Failed to load default image!\n");
			success = false;
		}

		//Load up surface
		keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("up.bmp");
		if (keyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
		{
			printf("Failed to load up image!\n");
			success = false;
		}

		//Load down surface
		keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("down.bmp");
		if (keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
		{
			printf("Failed to load down image!\n");
			success = false;
		}

		//Load left surface
		keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("left.bmp");
		if (keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
		{
			printf("Failed to load left image!\n");
			success = false;
		}

		//Load right surface
		keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right.bmp");
		if (keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
		{
			printf("Failed to load right image!\n");
			success = false;
		}

		return success;
	}