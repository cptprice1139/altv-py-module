#include "main.h"
#include "runtime.h"

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);

    auto runtime = new PythonRuntime();
    core->RegisterScriptRuntime("python", runtime);

    core->LogColored("~g~Python module was loaded. Version 1.0.0");

    return true;
}

EXPORT uint32_t GetSDKVersion()
{
    return alt::ICore::SDK_VERSION;
}