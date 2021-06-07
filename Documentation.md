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
				<li><a href="#initialization">Initialization</a></li>
				<li><a href="#input">Input</a></li>
				<li><a href="#main">Main</a></li>
			</ul>
		</li>
		<li><a href="#references">References</a>
			<ul><a href="#documentation">Documentation</a></ul>
			<ul><a href="#github-repositories">GitHub Repositories</a></ul>
			<ul><a href="#tutorials">Tutorials</a></ul>
			<ul><a href="#extra">Extra</a></ul>
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
3. Inside InitSDL() we initialize the joysticks one by one, and if they support haptic (they do in the case of PS3 Controllers), we initialize the respective haptic structure too.
4. With atexit() we set the callback function to be called at the end of the execution, where we free all the resources used by the controllers.
5. Then we begin our program loop, calling doInput() to receive events from the connected joysticks, and making them rumble if SELECT and START are pressed.


## Code
https://wiki.libsdl.org/SDL_PollEvent
### Initialization
<details>
</details>

### Input
<details>
</details>

### Main
<details>
</details>



## References
	
### Documentation
* [SDL Joystick Support](https://wiki.libsdl.org/CategoryJoystick)
* [SDL Joystick Input Handling](https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinput.html)
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
