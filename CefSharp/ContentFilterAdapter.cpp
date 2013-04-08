#include "stdafx.h"
#include "ContentFilterAdapter.h"

using namespace System::Runtime::InteropServices;

namespace CefSharp
{
    void ContentFilterAdapter::ProcessData(const void* data, int data_size,
		CefRefPtr<CefStreamReader>& substitute_data)
    {
        array<Byte>^ bytes = gcnew array<Byte>(data_size);
        Marshal::Copy(IntPtr((void *)data), bytes, 0, data_size);

        _handler->ProcessData(bytes);
    }

    void ContentFilterAdapter::Drain(CefRefPtr<CefStreamReader>& remainder)
    {
        _handler->Drain();
    }
}