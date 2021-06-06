


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
        <li><a href="#installation">Installation</a></li>
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

GIF dimostrative

### Built With

#### Written:
* in C
* Using [SDL2](https://www.libsdl.org/)
#### Tested:
* on UNIX system (Debian 9.8 running on a VM)
* With a PS3 Official Controller



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

* Git
* SDL2

### Installation

1. Download SDL2 frp, [Download Git](https://git-scm.com/download).
2. Clone the repo.
   ```sh
   git clone https://github.com/mikyll/SDL2-Controller-Tester
   ```
3. Download Unity Hub at [Download Unity](https://unity3d.com/get-unity/download).
4. Install a proper Unity version (2020.2.1 or higher) at [Download Archive](https://unity3d.com/get-unity/download/archive) or from Unity Hub.
5. Add the project directory on Unity Hub: Projects > Add > Select Directory.



<!-- USAGE EXAMPLES -->
## Usage

To test the prototype in multiplayer you can create a build for a standalone client, then enter PlayMode in the editor and connect the standalone application; otherwise you can create one build for the server and one for the client and connect several clients to the server.

For more examples, please refer to the [Documentation](https://github.com/mikyll/SDL2-Controller-Tester/blob/main/Documentation/Prototype%20Documentation.md).



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/mikyll/SDL2-Controller-Tester/issues) for the full list of proposed features (and known issues).

### Open Issues
* Haptic rumble initialization problem when connecting a new device at runtime.

### Future developments
* Sound effects when connecting or disconnecting a device.
* GUI with text for details and an interactive demo.


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
