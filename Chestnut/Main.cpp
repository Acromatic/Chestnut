// Main.cpp

#include "PluginManager.h"
#include "PluginLoader.h"
#include "PluginTypes.h"

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void watchDirectory(fs::path path) {
    fs::path directoryPath(path);

    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "Invalid directory path: " << path << std::endl;
        return;
    }

    fs::directory_entry directory(directoryPath);
    fs::file_time_type lastWriteTime = fs::last_write_time(directoryPath);

    while (true) {
        fs::file_time_type currentWriteTime = fs::last_write_time(directoryPath);

        if (currentWriteTime != lastWriteTime) {
            std::cout << "Directory changed!" << std::endl;
            lastWriteTime = currentWriteTime;
        }

        // Sleep for some time before checking again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Delta timing 
using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double>;

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {

    // Check available threads
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " core threads available." << std::endl;

    // Get the plugins folder path
    fs::path pluginsFolder = fs::current_path() / "plugins/";

    // Create PluginManager Register plugins
    PluginManager pluginManager;
    std::vector<CreatePluginFunc> pluginFuncs;

    // Load plugins
    std::cout << " scanning " << pluginsFolder << " directory for plugins to load. " << std::endl;
    pluginFuncs = PluginLoader::loadPlugins(pluginsFolder);

    for (auto& pluginFunc : pluginFuncs) {
        std::unique_ptr<IPlugin> plugin = pluginFunc();
        if (plugin) {
            pluginManager.registerPlugin(std::move(plugin));
        }
    }

    // The Main Loop of Your_Application, This will be your implemention
    // You make your own plugins or get the code and build them in your environment
    int frame_counter = 1;
    while (frame_counter <= 24)
    {
        auto startTime = Clock::now();

        // Print the number of loaded plugins this frame
        auto count = 0;
        pluginManager.getPluginsCount(count);
        std::cout << "Total plugins count: " << count << std::endl;

        // Print the number of application frames
        std::cout << " Ending frame number: " << frame_counter << std::endl;
        std::cout << " ------------------------------------------- " << std::endl;

        // pause the frame for 1 second in case no plugins exist we can see it works
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // Run plugins
        pluginManager.runPlugins();
        frame_counter++;

        auto endTime = Clock::now();
        Duration delta = endTime - startTime;
        std::cout << "Delta time: this frame took " << delta.count() << " seconds" << std::endl;
    }
    return 0;
}
