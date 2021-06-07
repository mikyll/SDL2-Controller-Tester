#include "input.h"

void doJoystickAxisMotion(SDL_JoyAxisEvent *event)
{	
	if((event->value < -3200) || (event->value > 3200)) 
	{
		if(event->axis == 0) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t%i\n  Axis:\t\t%i (ANALOG_L)\n  Value:\t%i ", event->timestamp, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(LEFT)\n\n");
			else
				fprintf(stdout, "(RIGHT)\n\n");
		}

		if(event->axis == 1) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t%i\n  Axis:\t\t%i (ANALOG_L)\n  Value:\t%i ", event->timestamp, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(UP)\n\n");
			else
				fprintf(stdout, "(DOWN)\n\n");
		}
		if(event->axis == 2) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t%i\n  Axis:\t\t%i (ANALOG_R)\n  Value:\t%i ", event->timestamp, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(LEFT)\n\n");
			else
				fprintf(stdout, "(RIGHT)\n\n");
		}

		if(event->axis == 3) 
		{
			fprintf(stdout, "[%zu] SDL_JOYAXISMOTION\n  Joystick:\t%i\n  Axis:\t\t%i (ANALOG_R)\n  Value:\t%i ", event->timestamp, event->which, event->axis, event->value);
			if(event->value < 0)
				fprintf(stdout, "(UP)\n\n");
			else
				fprintf(stdout, "(DOWN)\n\n");
		}
	}
}

void doJoystickButtonDown(SDL_JoyButtonEvent *event)
{
	fprintf(stdout, "[%zu] SDL_JOYBUTTONDOWN\n  Joystick:\t%i\n  Button:\t%i\n\n", event->timestamp, event->which, event->button);
	
	if(app.haptics[event->which] != NULL && (event->button == 0 || event->button == 3)) 
	{
		app.rumble[event->which]++;
		if(app.rumble[event->which] == 2)
			fprintf(stdout, "[%zu] RUMBLE_ON\n  Joystick:\t%i\n\n", event->timestamp, event->which);
	}
}

void doJoystickButtonUp(SDL_JoyButtonEvent *event)
{
	fprintf(stdout, "[%zu] SDL_JOYBUTTONUP\n  Joystick:\t%i\n  Button:\t%i\n\n", event->timestamp, event->which, event->button);
	
	if(app.haptics[event->which] != NULL && (event->button == 0 || event->button == 3)) 
	{
		if(app.rumble[event->which] == 2)
			fprintf(stdout, "[%zu] RUMBLE_OFF\n  Joystick:\t%i\n\n", event->timestamp, event->which);
		app.rumble[event->which]--;
	}
}

void doJoystickAdded(SDL_JoyDeviceEvent *event)
{
	if(app.joysticks[event->which] != NULL)
		return;
	
	fprintf(stdout, "[%zu] SDL_JOYDEVICEADDED\n", event->timestamp);
	if((app.joysticks[event->which] = SDL_JoystickOpen(event->which)) == NULL)
	{
		fprintf(stderr, "Error: Couldn't open the joystick(%i) SDL. %s\n\n", event->which, SDL_GetError());
		return;
	}
	
	fprintf(stdout, "  Opened Joystick:\t#%i\n", event->which);
	fprintf(stdout, "  Name:\t\t\t%s\n", SDL_JoystickName(app.joysticks[event->which]));
	fprintf(stdout, "  Number of Axes:\t%i\n", SDL_JoystickNumAxes(app.joysticks[event->which]));
	fprintf(stdout, "  Number of Buttons:\t%i\n", SDL_JoystickNumButtons(app.joysticks[event->which]));
	fprintf(stdout, "  Number of Balls:\t%i\n", SDL_JoystickNumBalls(app.joysticks[event->which]));
	
	// check if the joystick is a haptic device
	if(SDL_JoystickIsHaptic(app.joysticks[event->which]) < 0)
	{
		fprintf(stderr, "Error: Joystick #%i is not haptic, rumble can't be enabled. %s\n\n", event->which, SDL_GetError());
		return;
	}
	
	// haptic opening
	if((app.haptics[event->which] = SDL_HapticOpenFromJoystick(app.joysticks[event->which])) == NULL)
	{
		fprintf(stderr, "Error: Joystick #%i haptic opening failed. %s\n\n", event->which, SDL_GetError());
		return;
	}
	
	// check whether rumble is supported on a haptic device
	if(SDL_HapticRumbleSupported(app.haptics[event->which]) < 0)
	{
		fprintf(stderr, "Error: Joystick #%i doesn't support rumble. %s\n\n", event->which, SDL_GetError());
		SDL_HapticClose(app.haptics[event->which]);
		app.haptics[event->which] = NULL;
		return;
	}
	
	// Initialize a haptic device for simple rumble playback
	if(SDL_HapticRumbleInit(app.haptics[event->which]) < 0);
	{
		fprintf(stderr, "Error: Joystick #%i haptic rumble initialization failed. %s\n\n", event->which, SDL_GetError());
		SDL_HapticClose(app.haptics[event->which]);
		app.haptics[event->which] = NULL;
		return;
	}
	fprintf(stdout, "  Haptic rumble:\tenabled\n\n");
}

void doJoystickRemoved(SDL_JoyDeviceEvent *event)
{
	fprintf(stdout, "[%zu] SDL_JOYDEVICEREMOVED\n", event->timestamp, event->which);
	
	// clear joystick
	SDL_JoystickClose(app.joysticks[event->which]);
	app.joysticks[event->which] = NULL;
	fprintf(stdout, "  Closed joystick:\t#%i\n", event->which);
	
	// clear haptic
	SDL_HapticClose(app.haptics[event->which]);
	app.haptics[event->which] = NULL;
	fprintf(stdout, "  Closed haptic device:\t#%i\n\n", event->which);
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
