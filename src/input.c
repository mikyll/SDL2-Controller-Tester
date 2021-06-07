#include "input.h"

int getJoyIndex(int id);

void doJoystickAxisMotion(SDL_JoyAxisEvent *event)
{
	int i = getJoyIndex(event->which);
	
	if((event->value < -3200) || (event->value > 3200)) 
	{
		if(event->axis == 0) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t#%i(%i)\n  Axis:\t\t%i (ANALOG_L)\n  Value:\t%i ", event->timestamp, i, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(LEFT)\n\n");
			else
				fprintf(stdout, "(RIGHT)\n\n");
		}

		if(event->axis == 1) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t#%i(%i)\n  Axis:\t\t%i (ANALOG_L)\n  Value:\t%i ", event->timestamp, i, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(UP)\n\n");
			else
				fprintf(stdout, "(DOWN)\n\n");
		}
		if(event->axis == 2) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t#%i(%i)\n  Axis:\t\t%i (ANALOG_R)\n  Value:\t%i ", event->timestamp, i, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(LEFT)\n\n");
			else
				fprintf(stdout, "(RIGHT)\n\n");
		}

		if(event->axis == 3) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t#%i(%i)\n  Axis:\t\t%i (ANALOG_R)\n  Value:\t%i ", event->timestamp, i, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(UP)\n\n");
			else
				fprintf(stdout, "(DOWN)\n\n");
		}
	}
}

void doJoystickButtonDown(SDL_JoyButtonEvent *event)
{
	int i = getJoyIndex(event->which);
	fprintf(stdout, "[%zu] SDL_JOYBUTTONDOWN\n  Joystick:\t#%i(%i)\n  Button:\t%i\n\n", event->timestamp, i, event->which, event->button);
	
	// rumble
	if(app.haptics[i] != NULL && (event->button == 0 || event->button == 3)) 
	{
		app.rumble[i]++;
		if(app.rumble[i] == 2)
			fprintf(stdout, "[%zu] RUMBLE_ON\n  Joystick:\t#%i(%i)\n\n", event->timestamp, i, event->which);
	}
}

void doJoystickButtonUp(SDL_JoyButtonEvent *event)
{
	int i = getJoyIndex(event->which);
	
	fprintf(stdout, "[%zu] SDL_JOYBUTTONUP\n  Joystick:\t#%i(%i)\n  Button:\t%i\n\n", event->timestamp, i, event->which, event->button);
	
	// rumble
	if(app.haptics[i] != NULL && (event->button == 0 || event->button == 3)) 
	{
		if(app.rumble[i] == 2)
			fprintf(stdout, "[%zu] RUMBLE_OFF\n  Joystick:\t#%i(%i)\n\n", event->timestamp, i, event->which);
		app.rumble[i]--;
	}
}

void doJoystickAdded(SDL_JoyDeviceEvent *event)
{
	int i;
	
	// check if the array is full
	if(app.connected == MAX_NUM_JOYSTICKS)
	{
		fprintf(stdout, "Maximum number of connected joysticks reached.\n\n");
		return;
	}
	
	// search the first available index
	for(i = 0; i < MAX_NUM_JOYSTICKS; i++)
	{
		if(app.joysticks[i] == NULL) // found free spot
			break;
	}
	
	// joysticks and haptic devices opening
	fprintf(stdout, "[%zu] SDL_JOYDEVICEADDED\n", event->timestamp);
	if((app.joysticks[i] = SDL_JoystickOpen(event->which)) == NULL)
	{
		fprintf(stderr, "Error: Couldn't open the joystick(%i) SDL. %s\n\n", event->which, SDL_GetError());
		return;
	}
	app.connected++;
	
	fprintf(stdout, "  Index:\t\t#%i\n", i);
	fprintf(stdout, "  Joystick ID:\t\t%i\n", SDL_JoystickInstanceID(app.joysticks[i]));
	fprintf(stdout, "  Name:\t\t\t%s\n", SDL_JoystickName(app.joysticks[i]));
	fprintf(stdout, "  Number of Axes:\t%i\n", SDL_JoystickNumAxes(app.joysticks[i]));
	fprintf(stdout, "  Number of Buttons:\t%i\n", SDL_JoystickNumButtons(app.joysticks[i]));
	fprintf(stdout, "  Number of Balls:\t%i\n", SDL_JoystickNumBalls(app.joysticks[i]));
	
	// check if the joystick is a haptic device
	if(SDL_JoystickIsHaptic(app.joysticks[i]) < 0)
	{
		fprintf(stderr, "Error: Joystick #%i(%i) is not haptic, rumble can't be enabled. %s\n\n", i, event->which, SDL_GetError());
		return;
	}
	
	// haptic opening
	if((app.haptics[i] = SDL_HapticOpenFromJoystick(app.joysticks[i])) == NULL)
	{
		fprintf(stderr, "Error: Joystick #%i(%i) haptic opening failed. %s\n\n", i, event->which, SDL_GetError());
		return;
	}
	
	// check whether rumble is supported on a haptic device
	if(SDL_HapticRumbleSupported(app.haptics[i]) < 0)
	{
		fprintf(stderr, "Error: Joystick #%i(%i) doesn't support rumble. %s\n\n", i, event->which, SDL_GetError());
		SDL_HapticClose(app.haptics[i]);
		app.haptics[i] = NULL;
		return;
	}
	
	// Initialize a haptic device for simple rumble playback
	if(SDL_HapticRumbleInit(app.haptics[i]) < 0)
	{
		fprintf(stdout, "  Haptic rumble:\tdisabled\n\n");
		fprintf(stderr, "Error: Joystick #%i(%i) haptic rumble initialization failed. %s\n\n", i, event->which, SDL_GetError());
		SDL_HapticClose(app.haptics[i]);
		app.haptics[i] = NULL;
		return;
	}
	fprintf(stdout, "  Haptic rumble:\tenabled\n\n");
	
	fprintf(stdout, "Joystick currently connected: %i.\n\n", SDL_NumJoysticks());
}

void doJoystickRemoved(SDL_JoyDeviceEvent *event)
{
	int i = getJoyIndex(event->which);
	
	fprintf(stdout, "[%zu] SDL_JOYDEVICEREMOVED\n", event->timestamp);
	
	// clear joystick
	SDL_JoystickClose(app.joysticks[i]);
	app.joysticks[i] = NULL;
	fprintf(stdout, "  Closed joystick:\t#%i(%i)\n", i, event->which);
	
	// clear haptic
	SDL_HapticClose(app.haptics[i]);
	app.haptics[i] = NULL;
	fprintf(stdout, "  Closed haptic device:\t#%i(%i)\n\n", i, event->which);
	
	app.rumble[i] = 0;
	app.connected--;
	fprintf(stdout, "Joystick currently connected: %i.\n\n", SDL_NumJoysticks());
}

void doInput(void)
{
	SDL_Event event;
	
	// reading events from the event queue
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;
			
			case SDL_JOYAXISMOTION:
				doJoystickAxisMotion(&event.jaxis);
				break;
			
			case SDL_JOYBUTTONDOWN:
				doJoystickButtonDown(&event.jbutton);
				break;
			
			case SDL_JOYBUTTONUP:
				doJoystickButtonUp(&event.jbutton);
				break;
			
			case SDL_JOYDEVICEADDED:
				doJoystickAdded(&event.jdevice);
				break;
				
			case SDL_JOYDEVICEREMOVED:
				doJoystickRemoved(&event.jdevice);
				break;
			
			default:
				break;
		}
	}
}

int getJoyIndex(int id)
{
	int i;
	for(i = 0; i < MAX_NUM_JOYSTICKS; i++)
		if(SDL_JoystickInstanceID(app.joysticks[i]) == id)
			return i;
	return -1;
}
