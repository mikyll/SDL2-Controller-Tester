#include "init.h"

void initSDL(void)
{
	int i;
	
	// Initializing SDL with Joystick support (Joystick, game controller and haptic subsystems)
	if(SDL_Init( SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC ) < 0) // SDL_INIT_GAMECONTROLLER flag for gamecontroller.h 
	{
		fprintf(stderr, "Error: Couldn't initialize SDL. %s\n", SDL_GetError());
		exit(1);
	}
	
	fprintf(stdout, "Joystick currently attached: %i.\n\n", SDL_NumJoysticks());
	if(SDL_NumJoysticks() == 0)
		fprintf(stdout, "Check the joystick is properly connected.\nIf the problem persist, you can check the connected USB device with 'lsusb' and the logs in /var/logs/syslog\n"); 
	
	/* according to the docs this is needed to automatically receive joystick events, but it works fine 
	even without, so it's probably already enabled by default. */	
	SDL_JoystickEventState(SDL_ENABLE);
	
	// joysticks opening
	/* SDL_gamecontroller.h (https://www.libsdl.org/release/SDL-1.2.15/docs/html/joystick.html,
	https://github.com/libsdl-org/SDL/blob/main/include/SDL_gamecontroller.h,
	https://stackoverflow.com/questions/50022316/what-is-sdl-joystick-and-what-is-sdl-gamecontroller-what-are-the-relationships - difference between game controller and joystick)*/
	for(i = 0; i < SDL_NumJoysticks() && i < MAX_NUM_JOYSTICKS; i++)
	{
		if((app.joysticks[i] = SDL_JoystickOpen(i)) == NULL)
		{
			fprintf(stderr, "Error: Couldn't open the joystick(%i) SDL. %s\n", i, SDL_GetError());
			continue;
		}
		
		fprintf(stdout, "Opened Joystick:\t#%i\n", i);
		fprintf(stdout, "  Name:\t\t\t%s\n", SDL_JoystickName(app.joysticks[i]));
		fprintf(stdout, "  Number of Axes:\t%i\n", SDL_JoystickNumAxes(app.joysticks[i]));
		fprintf(stdout, "  Number of Buttons:\t%i\n", SDL_JoystickNumButtons(app.joysticks[i]));
		fprintf(stdout, "  Number of Balls:\t%i\n", SDL_JoystickNumBalls(app.joysticks[i]));
		
		// joystick rumble enabling (wiki: https://wiki.libsdl.org/CategoryForceFeedback)
		if(SDL_JoystickIsHaptic(app.joysticks[i]) < 0)
		{
			fprintf(stderr, "Error: Joystick #%i is not haptic, rumble can't be enabled. %s\n", i, SDL_GetError());
			continue;
		}
		
		if((app.haptics[i] = SDL_HapticOpenFromJoystick(app.joysticks[i])) == NULL)
		{
			fprintf(stderr, "Error: Joystick #%i haptic opening failed. %s\n", i, SDL_GetError());
			continue;
		}
		
		// check whether rumble is supported on a haptic device
		if(SDL_HapticRumbleSupported(app.haptics[i]) < 0)
		{
			fprintf(stderr, "Error: Joystick #%i doesn't support rumble. %s\n", i, SDL_GetError());
			SDL_HapticClose(app.haptics[i]);
			app.haptics[i] = NULL;
			continue;
		}
		
		// Initialize a haptic device for simple rumble playback
		if(SDL_HapticRumbleInit(app.haptics[i]) < 0)
		{
			fprintf(stderr, "Error: Joystick #%i haptic rumble initialization failed. %s\n\n", i, SDL_GetError());
			SDL_HapticClose(app.haptics[i]);
			app.haptics[i] = NULL;
			continue;
		}
		fprintf(stdout, "  Haptic rumble:\tenabled\n\n");
	}
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
