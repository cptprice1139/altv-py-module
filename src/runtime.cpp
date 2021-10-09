#include "runtime.h"

PythonRuntime* PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime()
{
    python::initialize_interpreter(false);

    instance = this;
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl)
{
    auto* resource = new PythonResource(this, impl);
    resources.insert({ impl, resource });
    return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl *impl)
{
    auto* resource = dynamic_cast<PythonResource*>(impl);

    if (resource != nullptr)
    {
        //resources.erase(resource->GetIResource(););
        delete resource;
    }
}

void PythonRuntime::OnTick()
{
    IScriptRuntime::OnTick();
}

void PythonRuntime::OnDispose()
{
    python::finalize_interpreter();

    IScriptRuntime::OnDispose();
}
