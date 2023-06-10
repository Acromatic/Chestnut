 
[![Watch the video](https://img.youtube.com/vi/T-D1KVIuvjA/maxresdefault.jpg)](https://youtu.be/T-D1KVIuvjA)

![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white) 
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Microsoft](https://img.shields.io/badge/Microsoft-0078D4?style=for-the-badge&logo=microsoft&logoColor=white)
![Windows 11](https://img.shields.io/badge/Windows%2011-%230079d5.svg?style=for-the-badge&logo=Windows%2011&logoColor=white) 
![Windows Terminal](https://img.shields.io/badge/Windows%20Terminal-%234D4D4D.svg?style=for-the-badge&logo=windows-terminal&logoColor=white) 
![ChatGPT](https://img.shields.io/badge/chatGPT-74aa9c?style=for-the-badge&logo=openai&logoColor=white) 
--------------------

   CHESTNUT - Begins with a story, a month long story about a chatGPT adventure into C++20 after a long break from coding (years). I started wanting basic file operations, what you see today is iteration 6 (0 day version) of a plugin framework(s) that me and chatGPT learned to program together. I started with something simple and in trying to write a C++ plugin library learned the hard way about doing that in C++, which is notoriously not good at doing such things like putting one into a library. And how C++23 could reduce compile times making large plugin solutions much easier to manage. To make a long story short this was a huge success in my education and for the open source and free code communities, as well as for chatGPT and if it learns from me that's even better. It still took a lot of skill and effort on my part but the atomation it provides is invaluable and I'm already hooked. As for why it's named Chestnut will become obvious with Walnut and Hazel2D integration. But overall this is a hard nut to crack so I've done it for everyone to share, enjoy and Happy Coding!

--------------------
A minimal Win64 C++20 Multi-threaded Plugin-Framework Application,
--------------------
Includes the following features: 
--------------------

"On-The-Fly" Dynamic Loading and Unloading. DLL deleted, no problem, moved, taken out and put back in, heck I'm pretty sure it'll even reload it right now, if not, it will soon. This thing is locked down for 1.0 but improvements will continue just like how I recently added a total rebuilt management system that's thread and type safe, and super minimal, which is perfect.

Multithreading:  The framework utilizes multiple threads to run the loaded plugins concurrently, maximizing the utilization of available CPU cores and improving performance. It's supposedly thread safe but with plugins everyone is in control so it depends what plugins you add I guess. For now it's safe enough and will continue to improve as long as I still breath.

Dynamic Loading:  The code dynamically loads plugins at runtime from a specified folder. It uses the PluginLoader class to load plugins from shared libraries (DLLs) and obtain the necessary function pointers to create and destroy plugin instances.

Plugin Management:  The PluginManager class provides the functionality to register and unregister plugins. It maintains a collection of loaded plugins and ensures thread-safe access to the collection using a mutex.

--------------------
HOW TO INSTALL
--------------------

Download the code in whatever medieval way you can and build your own projects for now. The functionality of the plugins themselves will be aiding in the construction of this project over time.
A plugins repository is planned but I have no such repository link to give at this time. You're on your own for now! Use at your own risk!

Note: Build in release mode because HMODULE depends on it for now, I need fallback devices and a build config to make the framework fully cross platform. (as well as a linux and mac machine)

--------------------
PLANS FOR THE FUTURE
--------------------
Well thread pooling was the first concept, but that turned into thread queues and interface design, which I feel is more flexible. But have better control over the threads and safty is core to this project.
Also, the framework is based on the concept of speed, so you can always expect that if I get major speed gains I'll go that direction. But I honestly believe the 1.0 version of this is as minimal as you can do it for the most part, without optimizations. I plan to make the framework cross platform via compile config someday but with no way to test and build on those machines, it's a no go. If you're wonder though for $1000 an individual with skills like mine could purchase the hardware necessary to get the job done. just an FYI, I'm not even accepting donations until my taxes get done this year. I may even consider collaborators but honestly just fork it and submit pull requests or something. Email works, I love it old school! Don't fix what isn't broken and always fix what needs to be done. Good luck and keep up the good fight! Without openAI this wasn't even possible!


FEEDBACK
--------------------
I'm an autodidact (self taught) hobbiest c++ programmer, and I provide these libraries free for everyone in my spare time.
Please lend a hand and report well thought out and written issues here on github, and have a nice day! Viva La Free Code!
