// IPlugin.h

#pragma once

// Define the plugin interface
class IPlugin {
public:
    virtual void process() = 0;
    virtual ~IPlugin() = default;
};
