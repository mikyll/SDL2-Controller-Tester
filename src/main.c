#include "main.h"

int main(int argc, char *argv[])
{
	int i;
	
	memset(&app, 0, sizeof(App));
	
	initSDL();
	
	atexit(cleanup);
	
	//fprintf(stdout, "USAGE:\nConnect the joystick and press the buttons to see which events are generated and the related button code. To enable the rumble (only available if the device supports haptic), press 'select' and 'start' at the same time.\n\n");
	
	while (1)
	{
		doInput();
		
		for(i = 0; i < MAX_NUM_JOYSTICKS; i++)
		{
			if(app.haptics[i] != NULL && app.rumble[i] == 2)
			{
				SDL_HapticRumblePlay(app.haptics[i], 1.0f, 1000);
			}
			if(app.haptics[i] != NULL && app.rumble[i] < 2)
				SDL_HapticRumbleStop(app.haptics[i]);
		}
		
		SDL_Delay(16);
	}

	return 0;
}
