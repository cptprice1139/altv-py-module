#pragma once

#include "main.h"
#include "resource.h"

class PythonRuntime : public alt::IScriptRuntime {

    static PythonRuntime* instance;
    std::unordered_map<alt::IResource*, PythonResource*> resources;

public:
    PythonRuntime();

    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
    void DestroyImpl(alt::IResource::Impl* impl) override;
    void OnTick() override;
    void OnDispose() override;

    PythonResource* GetResource(alt::IResource* resource)
    {
        auto result = resources.find(resource);
        if (result == resources.end()) return nullptr;
        return result->second;
    }

    static PythonRuntime* GetInstance()
    {
        return instance;
    }
};