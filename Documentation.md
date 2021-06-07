
# Documentation

The project allows to test the input of a controller, printing on the standard output the button code (integer) and .
Rileva input di bottoni e leve analogiche che si muovono su diversi "assi";
rileva connessione e disconnessione di controller diversi;
se il controller dispone di motorini per la vibrazione, permette di testare la vibrazione.
<!--1. Connect the controller via cable.
2. Run the application.
3. Spam buttons.
4. Press SELECT (0) and START (3) at the same time to make the controller rumble.-->
<br/>
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
			<ul><a href="#forum">Forum</a></ul>
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
<!--* <a href="https://docs.unity3d.com/Manual/index.html">Unity Manual</a>
* <a href="https://docs.unity3d.com/Packages/com.unity.entities@0.17">Unity Entities</a>
* <a href="https://docs.unity3d.com/Packages/com.unity.physics@0.6">Unity Physics</a>
* <a href="https://docs.unity3d.com/Packages/com.unity.netcode@0.6">Unity NetCode</a>
* <a href="https://youtube.com/playlist?list=PLX2vGYjWbI0S1wHRTyDiPtKLEP-->

### GitHub Repositories
<!--* <a href="https://github.com/Unity-Technologies/DOTSSample">DOTS Sample</a> - a third-person shooter demo showcasing the various new DOTS technologies in action together (including Unity Physics, NetCode, Hybrid Renderer, and Conversion Workflow).
* <a href="https://github.com/Unity-Technologies/EntityComponentSystemSamples">EntityComponentSystemSamples</a> - it contains some sub-repository, including UnityPhysicsSamples, with useful examples, demos and use cases.
* <a href="https://github.com/Unity-Technologies/DOTS-training-samples">DOTS training samples</a> - it contains small simulations/games implemented in classic (non-DOTS) Unity. It's a useful repository for training using DOTS.
* <a href="https://github.com/Unity-Technologies/multiplayer">Unity Real-time Multiplayer Alpha</a> - it contains an example project that uses NetCode to implement the networking.
* <a href="https://github.com/Unity-Technologies/FPSSample">FPS Sample</a> - an obsolete but interesting project.
* <a href="https://github.com/UnityTechnologies/AngryBots_ECS">AngryBots ECS</a> - simple third-person shooter, which shows improvements in gameplay when switching to DOTS implementation.-->

### Forum
<!--Click <a href="https://forum.unity.com/forums/data-oriented-technology-stack.147/">here</a> to visit the forum.-->
