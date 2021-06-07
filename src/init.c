#include "init.h"

void initSDL(void)
{
	int i;
	
	// Initializing SDL with Joystick support (Joystick, game controller and haptic subsystems)
	if(SDL_Init( SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC ) < 0)
	{
		fprintf(stderr, "Error: Couldn't initialize SDL. %s\n", SDL_GetError());
		exit(1);
	}
	
	fprintf(stdout, "Joystick currently attached: %i.\n\n", SDL_NumJoysticks());
	if(SDL_NumJoysticks() == 0)
		fprintf(stdout, "Check the joystick is properly connected.\nIf the problem persist, you can check the connected USB device with 'lsusb' and the logs in /var/logs/syslog\n"); 
	
	SDL_JoystickEventState(SDL_ENABLE);
}

// clean joysticks and haptic stuff
void cleanup(void)
{
	int i;
	
	fprintf(stdout, "\n\n");
	for(i = 0; app.joysticks[i] != NULL && i < MAX_NUM_JOYSTICKS; i++)
	{
		if(SDL_JoystickGetAttached(app.joysticks[i]) == SDL_TRUE)
		{
			SDL_JoystickClose(app.joysticks[i]);
			app.joysticks[i] = NULL;
			fprintf(stdout, "Closed joystick:\t#%i\n", i);
		}
		if(app.haptics[i] != NULL)
		{
			SDL_HapticClose(app.haptics[i]);
			app.haptics[i] = NULL;
			fprintf(stdout, "Closed haptic:\t\t#%i\n", i);
		}
	}
	
	SDL_Quit();
}
