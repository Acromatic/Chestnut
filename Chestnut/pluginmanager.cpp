// pluginmanager.cpp

#include "PluginManager.h"
#include <algorithm>
#include <thread>

void PluginManager::registerPlugin(std::unique_ptr<IPlugin> plugin) {
    std::lock_guard<std::mutex> lock(mutex_);
    plugins_.push_back(std::move(plugin));
}

void PluginManager::unregisterPlugin(IPlugin* plugin) {
    std::lock_guard<std::mutex> lock(mutex_);
    plugins_.erase(std::remove_if(plugins_.begin(), plugins_.end(), [plugin](const auto& p) {
        return p.get() == plugin;
        }), plugins_.end());
}

void PluginManager::runPlugins() {
    std::vector<std::jthread> threads;
    for (const auto& plugin : plugins_) {
        threads.emplace_back([plugin = plugin.get()]() {
            plugin->process();
            });
    }
}

void PluginManager::getPluginsCount(int& count) {
    std::lock_guard<std::mutex> lock(mutex_);
    count = plugins_.size();
}

