// pluginloader.cpp

#include "PluginLoader.h"
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <mutex>
//#include <wtypes.h>

namespace fs = std::filesystem;

std::vector<std::function<std::unique_ptr<IPlugin>()>> PluginLoader::loadPlugins(const fs::path& pluginsFolder) {
    std::vector<std::function<std::unique_ptr<IPlugin>()>> pluginFuncs;
    std::mutex mutex;  // Mutex for synchronizing access to pluginFuncs

    for (const auto& entry : fs::directory_iterator(pluginsFolder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".dll") {
            HMODULE dllHandle = LoadLibraryW(entry.path().c_str());
            if (dllHandle) {
                auto createFunc = reinterpret_cast<IPlugin * (*)()>(GetProcAddress(dllHandle, "createPlugin"));

                if (createFunc) {
                    std::function<std::unique_ptr<IPlugin>()> pluginFunc = [createFunc]() -> std::unique_ptr<IPlugin> {
                        std::unique_ptr<IPlugin> plugin(createFunc());
                        if (plugin) {
                            return plugin;
                        }
                        else {
                            std::cerr << "Failed to create plugin" << std::endl;
                            return nullptr;
                        }
                    };

                    std::lock_guard<std::mutex> lock(mutex);  // Lock the mutex before modifying pluginFuncs
                    pluginFuncs.push_back(std::move(pluginFunc));
                }
                else {
                    std::cerr << "Failed to load createPlugin function" << std::endl;
                    FreeLibrary(dllHandle);
                }
            }
            else {
                std::cerr << "Failed to load plugin: " << entry.path() << std::endl;
            }
        }
    }

    return pluginFuncs;
}
