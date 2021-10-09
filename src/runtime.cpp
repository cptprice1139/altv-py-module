#include "runtime.h"
#include "resource.h"

PythonScriptRuntime* PythonScriptRuntime::instance = nullptr;

PythonScriptRuntime::PythonScriptRuntime()
{
    python::initialize_interpreter(false);

    instance = this;
}

alt::IResource::Impl *PythonScriptRuntime::CreateImpl(alt::IResource *resource)
{
    return nullptr;
}

void PythonScriptRuntime::DestroyImpl(alt::IResource::Impl *impl)
{
    PythonResource* resource = dynamic_cast<PythonResource*>(impl);

    if (resource != nullptr)
    {
        //resources.erase(resource->GetIResource());
        delete resource;
    }
}

void PythonScriptRuntime::OnTick()
{
    IScriptRuntime::OnTick();
}

void PythonScriptRuntime::OnDispose()
{
    IScriptRuntime::OnDispose();
}
