#include "stdafx.h"
#pragma once

#include "include/cef_content_filter.h"
#include "IContentFilterHandler.h"

namespace CefSharp
{
    class ContentFilterAdapter : public CefContentFilter
    {
        gcroot<IContentFilterHandler^> _handler;

    public:
        ContentFilterAdapter(IContentFilterHandler^ handler) : _handler(handler) { }

        virtual void ProcessData(const void* data, int data_size,
			CefRefPtr<CefStreamReader>& substitute_data);
        virtual void Drain(CefRefPtr<CefStreamReader>& remainder);

        IMPLEMENT_REFCOUNTING(ContentFilterAdapter);
    };
}