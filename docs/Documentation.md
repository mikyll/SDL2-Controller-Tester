# Documentation

The project allows to test the input of a controller, printing on the standard output the button code (integer) and the value on different axis in case of the analogic controls. It also detect when a controller is connected or disconnected and it allows to test the rumble support, if the controller has one.
<p align="center">
	<a href="https://github.com/mikyll/SDL2-Controller-Tester">Home page</a>
</p>

<!-- TABLE OF CONTENTS -->
<details open="open">
	<summary><h2 style="display: inline-block">Index</h2></summary>
	<ol>
		<li><a href="#main-features">Main Features</a></li>
		<li><a href="#project-build">Project Build</a></li>
		<li><a href="#execution-flow">Execution Flow</a></li>
		<li><a href="#code">Code</a>
			<ul>
				<li><a href="#main-mainc">Main</a></li>
				<li><a href="#initialization-initc">Initialization</a></li>
				<li><a href="#input-inputc">Input</a></li>		
			</ul>
		</li>
		<li><a href="#references">References</a>
			<ul>
				<li><a href="#documentation">Documentation</a></li>
				<li><a href="#github-repositories">GitHub Repositories</a></li>
				<li><a href="#tutorials">Tutorials</a></li>
				<li><a href="#extra">Extra</a></li>
			</ul>
		</li>
	</ol>
</details>


## Main Features

<table>
	<tr>
		<td><b>Feature</b></td>
		<td width="60%"><b>Demo</b></td>
	</tr>
	<tr>
		<td>Joystick Button Event</td>
		<td width="60%"><img src="https://github.com/mikyll/SDL2-Controller-Tester/blob/main/gfx/SDL_JOYBUTTON.png" alt="SDL_JoyButtonEvent"/></td>
	</tr>
	<tr>
		<td>Joystic Axis Event</td>
		<td width="60%"><img src="https://github.com/mikyll/SDL2-Controller-Tester/blob/main/gfx/SDL_JOYAXISMOTION.png" alt="SDL_JoyAxisEvent"/></td>
	</tr>
	<tr>
		<td>Joystick Device Event</td>
		<td width="60%"><img src="https://github.com/mikyll/SDL2-Controller-Tester/blob/main/gfx/SDL_JOYDEVICE.png" alt="SDL_JoyDeviceEvent"/></td>
	</tr>
	<tr>
		<td>Haptic Rumble</td>
		<td width="60%"><img src="https://github.com/mikyll/SDL2-Controller-Tester/blob/main/gfx/Haptic Rumble.png" alt="Haptic Rumble"/></td>
	</tr>
</table>


## Project Build

### Linux

Simply open a terminal in the root directory of the project and run `make`.

### Windows

If MinGW and SDL2 are correctly installed, open a cmd window in the root directory of the project and run `gcc -o controllerTester src\main.c src\init.c src\input.c -lmingw32 -lSDL2main -lSDL2`.


## Execution Flow

1. When the application starts, we initialize the App structure, where we're going to store our joystick pointers.
2. Then we call the function InitSDL(), located in [init.c](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/init.c), which initializes the SDL subsystems required for the application to work (SDL_INIT_JOYSTICK and SDL_INIT_HAPTIC).
3. With atexit() we set the callback function to be called at the end of the execution, where we free all the resources used by the controllers.
4. Then we begin our program loop, calling doInput() to receive events from the connected joysticks, and making them rumble if SELECT and START are pressed.
5. When a new controller is detected, inside doInput() we initialize the joystick, and if it supports haptic (it does in the case it is a PS3 Controller), we initialize the respective haptic structure too and we increment the counter of the controllers currently connected and initialized.
6. Whenever a joystick sends an input, we print on the standard output it's values.


## Code
### Files
* [common.h](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/common.h) - contains the common headers.
* [defs.h](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/defs.h) - contains definitions.
* [init.c](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/init.c) - functions to initialize and set up SDL.
* [init.h](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/init.h) - header file for init.c.
* [input.c](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/input.c) - handles the user input.
* [input.h](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/input.h) - header file for input.c.
* [main.c](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/main.c) - main loop of the application.
* [main.h](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/main.h) - header file for main.c.
* [struct.h](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/src/struct.h) - type definitions.

### Main (main.c)
<details>

<pre>
memset(&app, 0, sizeof(App));
</pre>
The first thing the program does is setting up a structure containing an array of joysticks, one with the respective haptic device and another one with integer values which we will use for the rumble setting. The index of those arrays identifies a controller.
#### `App` structure (struct.h)
<pre>
typedef struct {
	SDL_Joystick *joysticks[MAX_NUM_JOYSTICKS];
	SDL_Haptic *haptics[MAX_NUM_JOYSTICKS];
	int rumble[MAX_NUM_JOYSTICKS]; // 2 -> play rumble
	int connected; // connected joysticks number
} App;
</pre>
`SDL_Joystick` represents a controller, `SDL_haptic` represents the haptic device which will eventually enable the vibration.
After setting up the structure, we proceed with SDL initialization by calling `initSDL()` and we set up a function to be called when the program ends, with `atexit()`.
Once the initialization is done, we start the actual main loop, where we call doInput() and check if the vibration is enabled to play the rumble support.
`SDL_Delay(16)` makes the program wait for 16 milliseconds. We do that to limit the loop to around 62 frames per second and also prevent the application from running at full tilt and consuming far too much CPU time.

#### Vibration
<pre>
if(app.haptics[i] != NULL && app.rumble[i] == 2)
{
	SDL_HapticRumblePlay(app.haptics[i], 1.0f, 1000);
}
if(app.haptics[i] != NULL && app.rumble[i] < 2)
	SDL_HapticRumbleStop(app.haptics[i]);
</pre>
The joystick vibration is enabled when we pressing 2 specific buttons at the same time (0 and 3) and, obviously, when the corresponding haptic device is enabled (! = NULL).
To do this we use the `app.rumble` array: each element corresponds to a joystick (the index is the same for the different arrays) and it's initially set to 0;
when button 0 or 3 is pressed, we increment the element corresponding to the joystick that sent the event by 1, and we decrement it when the button is released;
when `app.rumble` value is 2, since a button cannot be pressed multiple times without releasing it, we know both 0 and 3 are pressed and we can enable the vibration.
</details>

### Initialization (init.c)
<details>

#### `initSDL()` function
This function purpose is to initialize the SDL subsystems we need for our program to work. 
By doing calling `SDL_Init( SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC )` we tell SDL we want to use the Joystick and Haptic subsystems.
Then we enable the joystick event polling with `SDL_JoystickEventState(SDL_ENABLE)`, to automatically receive joystick events.

#### `cleanup()` function
This function cleans all the resources used by joystick and haptic structures by calling `SDL_JoystickClose()` and `SDL_HapticClose()`.

</details>

### Input (input.c)
<details>

#### `doInput()` function
We loop on `SDL_PollEvent()` which returns 1 if there's an event in the queue, and updates its parameter with that event. Then we check if that event is of our interest, that is a Joystick event and for each one we call a different function:

#### `doJoystickAdded()` function
<pre>
if(app.connected == MAX_NUM_JOYSTICKS)
{
	fprintf(stdout, "Maximum number of connected joysticks reached.\n\n");
	return;
}
for(i = 0; i < MAX_NUM_JOYSTICKS; i++)
{
	if(app.joysticks[i] == NULL) // found free spot
		break;
}
if((app.joysticks[i] = SDL_JoystickOpen(event->which)) == NULL)
{
	fprintf(stderr, "Error: Couldn't open the joystick(%i) SDL. %s\n\n", event->which, SDL_GetError());
	return;
}
app.connected++;
</pre>
this one is called when a controller is attached at runtime: we firstly check if the number of connected joysticks is equal to our `MAX_NUM_JOYSTICKS` value, if not we continue with the setup of the controller. We then search for the first available position in `app.joysticks` array and we open the joystick with `SDL_JoystickOpen()`, which returns a `SDL_Joystick` structure, so we save that inside our array.
Since everytime a joystick is connected (even if it has been already connected during the same execution of the program), the ID is incremented from the previous one, we cannot use the ID as index for our `app.joysticks` array. If we have done this we would have put our just connected joystick in a new position everytime, not using the previous ones.
Once the joystick is correctly initialized, we increment `app.connected` variable, which tells how many joysticks are currently opened. We have to use this variable because `SDL_NumJoysticks()` returns the number of every connected device, while we only want the initialized ones.
<pre>
if(SDL_JoystickIsHaptic(app.joysticks[i]) < 0)
{
	fprintf(stderr, "Error: Joystick #%i(%i) is not haptic, rumble can't be enabled. %s\n\n", i, event->which, SDL_GetError());
	return;
}
if((app.haptics[i] = SDL_HapticOpenFromJoystick(app.joysticks[i])) == NULL)
{
	fprintf(stderr, "Error: Joystick #%i(%i) haptic opening failed. %s\n\n", i, event->which, SDL_GetError());
	return;
}
if(SDL_HapticRumbleSupported(app.haptics[i]) < 0)
{
	fprintf(stderr, "Error: Joystick #%i(%i) doesn't support rumble. %s\n\n", i, event->which, SDL_GetError());
	SDL_HapticClose(app.haptics[i]);
	app.haptics[i] = NULL;
	return;
}

if(SDL_HapticRumbleInit(app.haptics[i]) < 0)
{
	fprintf(stdout, "  Haptic rumble:\tdisabled\n\n");
	fprintf(stderr, "Error: Joystick #%i(%i) haptic rumble initialization failed. %s\n\n", i, event->which, SDL_GetError());
	SDL_HapticClose(app.haptics[i]);
	app.haptics[i] = NULL;
	return;
}
</pre>
The previous code check if the joystick supports the vibration and, in that case, we obtain a `SDL_Haptic` structure, which we save in our `app.haptics` array, at the same index of the corresponding joystick in `app.joysticks`.

#### `doJoystickRemoved` function
This function is called when a joystick is disconnected, so we have to clear all the resources it was using (something similiar to cleanup() function), by calling `SDL_JoystickClose()` and `SDL_HapticClose()`, and setting to NULL the App arrays. To do this we need to know the index of the controller, but since the `SDL_Event` obviously doesn't contain it, we use the auxiliary function `getJoyIndex()`. this function finds the index of the controller that has the same ID of the event one.
Finally we decrement `app.connected` variable.

#### `doJoystickButtonDown` function
This function is called when a joystick button is pressed. We simply print to standard output the event values and in case it was 0 or 3, we increment the element `app.rumble` value with the index of the joystick who sent the event. 

#### `doJoystickButtonUp` function
This function is basically the dual of the previous one: if the button pressed are 0 and 3 we decrement `app.rumble` value.

#### `doJoystickAxisMotion` function
This function is similiar to the two previous ones, except before printing the event values we check if the value is outside a certain threshold `(event->value < -3200) || (event->value > 3200)`. If we had ommitted that check, the output would have spammed event values even when we didn't touch the controller. 
</details>






## References
	
### Documentation
* [SDL Joystick Support](https://wiki.libsdl.org/CategoryJoystick)
* SDL [Joystick](https://www.libsdl.org/release/SDL-1.2.15/docs/html/joystick.html) and [Joystick Input Handling](https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinput.html)
* [SDL_Event](https://wiki.libsdl.org/SDL_Event), [SDL_JoyButtonEvent](https://wiki.libsdl.org/SDL_JoyButtonEvent), [SDL_JoyAxisEvent](https://wiki.libsdl.org/SDL_JoyAxisEvent), [SDL_JoyDeviceEvent](https://wiki.libsdl.org/SDL_JoyDeviceEvent)

### GitHub Repositories
* [SDL official repository](https://github.com/libsdl-org/SDL)
* [SDL_joystick.h](https://github.com/libsdl-org/SDL/blob/main/include/SDL_joystick.h)
* [SDL_haptic.h](https://github.com/libsdl-org/SDL/blob/main/include/SDL_haptic.h)

### Tutorials
* [LazyFoo](https://lazyfoo.net/) - [SDL2 installation guide](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php) and many other useful [SDL tutorial](https://lazyfoo.net/tutorials/SDL/index.php).
* [Parallel Realities ](https://www.parallelrealities.co.uk/) - wonderful [C game tutorials](https://www.parallelrealities.co.uk/tutorials/) (starting from SDL basics).

### Extra
* [SDL Game Controller Support](https://wiki.libsdl.org/CategoryGameController)
* [Difference between Joystick and GameController](https://stackoverflow.com/questions/50022316/what-is-sdl-joystick-and-what-is-sdl-gamecontroller-what-are-the-relationships)
