#pragma once

#include "main.h"

class PythonRuntime;
class PythonResource : public alt::IResource::Impl{
    PythonRuntime* runtime;
    alt::IResource* resource;

public:
    PythonResource(PythonRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource) {};

    alt::IResource* GetIResource() const
    {
        return resource;
    }

    PythonRuntime* GetRuntime() const
    {
        return runtime;
    }
};