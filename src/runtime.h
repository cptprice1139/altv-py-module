#pragma once

#include <SDK.h>
#include "main.h"
#include "resource.h"

class PythonScriptRuntime : public alt::IScriptRuntime {

    static PythonScriptRuntime* instance;
    std::unordered_map<alt::IResource*, PythonResource*> resources;

public:
    PythonScriptRuntime();

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

    static PythonScriptRuntime* Instance()
    {
        return instance;
    }
};