// Copyright (c) 2019 Aaron R Robinson

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __cplusplus
#error Requires C++ compiler support
#endif

#ifndef _PPDB_INC_XPLAT_CORSYM_HPP_
#define _PPDB_INC_XPLAT_CORSYM_HPP_

#include "platform.hpp"
#include <cstdint>

#if !defined(NO_DEF_WINDOWS_PRIMITIVES)
    using HRESULT = uint32_t;

    using BYTE = uint8_t;
    using BOOL = int32_t;
    using USHORT = uint16_t;
    using WCHAR = uint16_t;
    using INT32 = int32_t;
    using DWORD = uint32_t;
    using ULONG = uint32_t;
    using ULONG32 = uint32_t;
    using ULONGLONG = uint64_t;
    using SIZE_T = size_t;

    using BSTR = WCHAR * ;
#endif

#ifndef EXTERN_C
    #define EXTERN_C extern "C"
#endif

#ifndef DECLSPEC_UUID
    #define DECLSPEC_UUID(s) 
#endif

#ifndef interface
    #define interface struct
#endif

#ifndef MIDL_INTERFACE
    #define MIDL_INTERFACE(s) interface
#endif

#ifndef EXTERN_GUID
    #if defined(DECLARE_EXPORTS)
        #define EXTERN_GUID(sym, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11) \
            EXTERN_C const IID sym = {d1, d2, d3, { d4, d5, d6, d7, d8, d9, d10, d11 }}
    #else
        #define EXTERN_GUID(sym, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11) \
            EXTERN_C const IID sym
    #endif
#endif

#ifndef MAKE_HRESULT
    #define FACILITY_ITF 4
    #define MAKE_HRESULT(e, f, v) ((HRESULT) ((uint32_t)e << 31) | ((uint32_t)f << 16) | ((uint32_t)v))
#endif

#ifndef STDMETHODCALLTYPE
    #if defined(_WIN32)
        #define STDMETHODCALLTYPE __stdcall
    #else
        #define STDMETHODCALLTYPE 
    #endif
#endif

#if !defined(NO_DEF_COM_IDS)
    using IID = GUID;
    using REFIID = const IID &;
    using CLSID = GUID;
#endif

#if !defined(NO_DEF_IMAGE_DEBUG_DIRECTORY)
    using IMAGE_DEBUG_DIRECTORY = void *;
#endif

#if !defined(NO_DEF_COM_VARIANT)
    using VARIANT = void *;
#endif

#if !defined(NO_DEF_COR_PRIMITIVES)
    using mdMethodDef = mdToken;
    using mdTypeDef = mdToken;
#endif

#if !defined(NO_DEF_IUNKNOWN)
    MIDL_INTERFACE("00000000-0000-0000-C000-000000000046")
    IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID, void **) = 0;
        virtual ULONG STDMETHODCALLTYPE AddRef(void) = 0;
        virtual ULONG STDMETHODCALLTYPE Release(void) = 0;
    };
#endif

#if !defined(NO_DEF_ISTREAM)
    using IStream = void *;
#endif

#define COM_NO_WINDOWS_H
#include "internal/corsym.h"

#endif // _PPDB_INC_XPLAT_CORSYM_HPP_