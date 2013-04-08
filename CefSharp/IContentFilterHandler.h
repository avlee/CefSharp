#include "stdafx.h"
#pragma once

namespace CefSharp
{
    public interface class IContentFilterHandler
    {
    public:
        void ProcessData(array<Byte>^ data);
        void Drain();
    };
}