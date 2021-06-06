


<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo_name, twitter_handle, email, project_title, project_description
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]




<!-- PROJECT LOGO -->
<br />
<p align="center">
  <!--<a href="https://github.com/mikyll/SDL2-Controller-Tester">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>-->

  <h1 align="center">SDL2 Controller Tester</h1>

  <p align="center">
This little application has been made while I was attending a tutorial to make games in C using SDL2. Since my purpose will be to implement a game with both keyboard or controller input, I wanted to test which of my PS3 controller feature I could use (spoiler: each one).</i>
<br />
	<a href="https://github.com/mikyll/SDL2-Controller-Tester/blob/main/Documentation.md"><strong>Explore the docs »</strong></a>
	<br />
	<br />
	<a href="https://github.com/mikyll/SDL2-Controller-Tester/issues">Report Bug</a>
	·
	<a href="https://github.com/mikyll/SDL2-Controller-Tester/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#sdl2-installation">SDL2 Installation</a></li>
        <li><a href="#project-build">Project Build</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Demo GIF

### Built With

#### Written:
* in C
* using [SDL2](https://www.libsdl.org/)
#### Tested:
* on UNIX system (Debian 9.8 running on a VM)
* with a PS3 Official Controller: Sony® DualShock 3



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

* Git
* SDL2
* At least one controller compatible with your OS

### SDL2 Installation
#### Windows (MinGW)
1. Download SDL2 source code .zip from [there](https://www.libsdl.org/release/SDL2-2.0.14.zip) and extract the content.
2. Inside SDL2-2.0.14, depending on your OS, open the 32bit or 64bit directory, respectively **i686-w64-mingw32** or **x86_64-w64-mingw32**.
3. Then copy the content of the lib subdirectory to the MinGW lib directory (which should be at C:\MinGW\lib).
4. Then, going back to our SDL2 directory, open the include subdirectory and copy the folder **SDL2** to the MinGW include subdirectory.
**NB**: to compile a project which uses SLD2 libraries, you also need SDL2.dll, which can be found inside the bin subdirectory of the 32 or 64 bit version of the SDL2 root directory (SDL2-2.0.14, the one extracted from the archive). This one has to be put in the directory from which you compile the application.

#### Linux (Debian)
The easiest way is to open a terminal and use Advanced Packaging Tool to install only the modules required using ```apt-get install libsdl2-dev``` or every one using ```apt-get install libsdl2-*```.
Otherwise download the source code from [there](https://www.libsdl.org/release/SDL2-2.0.14.tar.gz), extract the content and cd to the main directory. Then run  ```./configure``` to configure the installation, ```make all``` to compile the source, and finally ```make install``` to install the package.

### Project Build

1. Clone the repo.
   ```sh
   git clone https://github.com/mikyll/SDL2-Controller-Tester
   ```
2. Install SDL2 (example with Advanced Packaging Tool, otherwise you can follow [this tutorial](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php) ).
   ```sh
   sudo apt-get install sdl2-*
   ```
3. Compile the project using the makefile.
   ```sh
   make
   ```



<!-- USAGE EXAMPLES -->
## Usage

To use the application, simply connect one or more joystick via cable and run the executable. Each controller input will print on the standard output device the joystick ID and the button code or the direction in case of the analogic levers.
To make the joystick rumble press the button 0 and 3 (respectively SELECT and START in the case of a PS3 controller) at the same time.
The application even shows when a controlles is disconnected or when a new one is connected.

for more detailed information, please refer to the [Documentation](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/Documentation/Prototype%20Documentation.md).



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/mikyll/SDL2-Controller-Tester/issues) for the full list of proposed features (and known issues).

### Open Issues
* Haptic rumble initialization problem when connecting a new device at runtime.

### Future developments
* Sound effects when connecting or disconnecting a device.
* GUI with text for details.
* Interactive demo.


<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project.
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`).
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the Branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.



<!-- LICENSE -->
## License

Distributed under the GNU v3.0 License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Michele Righi - <!-- [@twitter_handle](https://twitter.com/twitter_handle) - -->righi.michy@gmail.com

Project Link: [https://github.com/mikyll/SDL2-Controller-Tester](https://github.com/mikyll/SDL2-Controller-Tester)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* [Parallel Realities](https://www.parallelrealities.co.uk) for the lovely and super detailed tutorials involving game development in C using SDL2, from which I "stole" (actually I bought some of the tutorial, they're extremely cheap -just 1$ each one-) the project structure and the makefile.
* [Othneil Drew](https://github.com/othneildrew) for the amazing [README template](https://github.com/othneildrew/Best-README-Template).

## References
* SDL2 installation tutorial (a bit outdated, so be careful) - [LazyFoo SDL installation](http://lazyfoo.net/SDL_tutorials/lesson01/windows/index.php)
* Wonderful C game tutorials (starting from SDL basics) - [Parallel Realities Tutorials](https://www.parallelrealities.co.uk/)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/mikyll/SDL2-Controller-Tester
[contributors-url]: https://github.com/mikyll/SDL2-Controller-Tester/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/mikyll/SDL2-Controller-Tester
[forks-url]: https://github.com/mikyll/SDL2-Controller-Tester/network/members
[stars-shield]: https://img.shields.io/github/stars/mikyll/SDL2-Controller-Tester
[stars-url]: https://github.com/mikyll/SDL2-Controller-Tester/stargazers
[issues-shield]: https://img.shields.io/github/issues/mikyll/SDL2-Controller-Tester
[issues-url]: https://github.com/mikyll/SDL2-Controller-Tester/issues
[license-shield]: https://img.shields.io/github/license/mikyll/SDL2-Controller-Tester
[license-url]: https://github.com/mikyll/SDL2-Controller-Tester/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/michele-righi-095283195/?locale=en_US
