// PluginTypes.h

#pragma once

#include "include/IPlugin.h"
#include <functional>
#include <memory>

// Define custom types related to plugins
using CreatePluginFunc = std::function<std::unique_ptr<IPlugin>()>;
using DestroyPluginFunc = std::function<void(IPlugin*)>;