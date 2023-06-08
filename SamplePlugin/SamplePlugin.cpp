// SamplePlugin.cpp

#include "IPlugin.h"
#include <iostream>

class SamplePlugin : public IPlugin {
public:
    void process() override {
        // Plugins process on their own threads.
        std::cout << "Processing plugin: SamplePlugin\n";
    }
};

// Export the plugin instance
extern "C" {
    __declspec(dllexport) IPlugin* createPlugin() {
        return new SamplePlugin();
    }

    __declspec(dllexport) void destroyPlugin(IPlugin* plugin) {
        delete plugin;
    }
}
