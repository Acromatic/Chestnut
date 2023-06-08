// pluginloader.h

#pragma once

#include "include/IPlugin.h"
#include <filesystem>
#include <vector>
#include <functional>
#include <memory>

namespace fs = std::filesystem;

class PluginLoader {
public:
    static std::vector<std::function<std::unique_ptr<IPlugin>()>> loadPlugins(const fs::path& pluginsFolder);
};
