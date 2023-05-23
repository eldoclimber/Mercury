#include "window.h"





int main(int argc, char* args[])
{
	//Window Object
	window* mainWindow= new window;

	if (!mainWindow->init())
	{
		printf("Failed to initialized!\n");
	}
	else
	{
		if (!mainWindow->loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply Image
			SDL_BlitSurface(mainWindow->imageSurface, NULL, mainWindow->mainSurface, NULL);
			//Update the surface
			SDL_UpdateWindowSurface(mainWindow->mainWindow);
		}
		
	}
	mainWindow->keepOpen();
	mainWindow->destroyWindow();
	return 0;
}

