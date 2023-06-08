![ChatGPT](https://img.shields.io/badge/chatGPT-74aa9c?style=for-the-badge&logo=openai&logoColor=white) ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Microsoft](https://img.shields.io/badge/Microsoft-0078D4?style=for-the-badge&logo=microsoft&logoColor=white) ![Windows 11](https://img.shields.io/badge/Windows%2011-%230079d5.svg?style=for-the-badge&logo=Windows%2011&logoColor=white) ![Windows Terminal](https://img.shields.io/badge/Windows%20Terminal-%234D4D4D.svg?style=for-the-badge&logo=windows-terminal&logoColor=white) ![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white) ![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)

--------------------
   CHESTNUT       
--------------------
--------------------
A Win64 C++20 Multi-threaded Plugin-Framework Application,
--------------------
with "On-The-Fly" Dynamic Loading and Unloading.    
--------------------

Uniquely the 1.0 version of this was written almost entirely by chatGPT4, with a lot of guidance of course. I did the leg work but chatGPT4 handled fixing the code until we got the necessary ground work finished. Which is kind of how this project started.


Includes the following features: 
--------------------

Multithreading: 
--------------------
 The framework utilizes multiple threads to run the loaded plugins concurrently, maximizing the utilization of available CPU cores and improving performance.

Dynamic Loading: 
--------------------
 The code dynamically loads plugins at runtime from a specified folder. It uses the PluginLoader class to load plugins from shared libraries (DLLs) and obtain the necessary function pointers to create and destroy plugin instances.

On-the-fly Loading:
--------------------
 The framework allows you to load plugins on-the-fly, meaning you can add or remove plugins from the plugins folder without restarting the application. The PluginLoader class scans the plugins folder and loads any valid plugins it finds. ( Known issues: it currently handles unloading safely using mutex which is atomic and captures the code, even unloading a plugin will not stop it's execution yet, it will finish whatever has currently accessed it before unlocking the mutex and unloading the plugin DLL. TODO: feature is proper unloading plugins ASAP when they are removed from the /plugins folder)

Plugin Management:
--------------------
 The PluginManager class provides the functionality to register and unregister plugins. It maintains a collection of loaded plugins and ensures thread-safe access to the collection using a mutex.



--------------------
HOW TO INSTALL
--------------------

Download the code in whatever medieval way you can and build your own projects for now. The functionality of the plugins themselves will be aiding in the construction of this project over time.
A plugins repository is planned but I have no such repository link to give at this time. You're on your own for now! Use at your own risk!



FEEDBACK
--------------------
I'm an autodidact (self taught) hobbiest c++ programmer, and I provide these libraries free for everyone in my spare time.
Please lend a hand and report well thought out and written issues here on github, and have a nice day! Viva La Free Code!
