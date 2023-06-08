// pluginmanager.h

#pragma once

#include "include/IPlugin.h"
#include <vector>
#include <mutex>

class PluginManager {
public:
    void registerPlugin(std::unique_ptr<IPlugin> plugin);
    void unregisterPlugin(IPlugin* plugin);
    void runPlugins();
    virtual void getPluginsCount(int &count);

private:
    std::vector<std::unique_ptr<IPlugin>> plugins_;
    std::mutex mutex_;
};
