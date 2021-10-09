#pragma once

#include <SDK.h>

class PythonScriptRuntime : public alt::IScriptRuntime {

    pythonIScriptEngine* engine;
    std::unordered_map<alt::IResource*, PythonResource*> resources;

public:
    PythonScriptRuntime();

    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
    void DestroyImpl(alt::IResource* resource) override;
    void OnTick() override;
    void OnDispose() override;

    pythonIScriptEngine* GetEngine()
    {
        return engine;
    }

    PythonResource* GetResource(alt::IResource* resource)
    {
        auto result = resources.find(resource);
        if (result == resources.end()) return nullptr;
        return result->second;
    }

    static PythonScriptRuntime& Instance()
    {
        static PythonScriptRuntime _instance;
        return _instance;
    }
};