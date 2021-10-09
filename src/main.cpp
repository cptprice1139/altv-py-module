#include "main.h"

#ifdef ALT_SERVER_MODULE

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);

    auto runtime = PythonScriptRuntime();

    core->RegisterScriptRuntime("myModule", runtime);

    core->LogInfo("Loaded my module!");

    return true;
}

#endif

#ifdef ALT_CLIENT_MODULE

#endif