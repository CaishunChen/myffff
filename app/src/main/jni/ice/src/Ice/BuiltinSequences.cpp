// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `BuiltinSequences.ice'

#include <Ice/BuiltinSequences.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/DisableWarnings.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 302
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::ObjectPtr* begin, const ::Ice::ObjectPtr* end, ::Ice::__U__ObjectSeq)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        __os->write(begin[i]);
    }
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::ObjectSeq& v, ::Ice::__U__ObjectSeq)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 4);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        __is->read(::Ice::__patch__ObjectPtr, &v[i]);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::ObjectPrx* begin, const ::Ice::ObjectPrx* end, ::Ice::__U__ObjectProxySeq)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        __os->write(begin[i]);
    }
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::ObjectProxySeq& v, ::Ice::__U__ObjectProxySeq)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 2);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        __is->read(v[i]);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}
