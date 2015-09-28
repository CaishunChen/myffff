// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Identity.ice'

#include <Ice/Identity.h>
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

bool
Ice::Identity::operator==(const Identity& __rhs) const
{
    return !operator!=(__rhs);
}

bool
Ice::Identity::operator!=(const Identity& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(name != __rhs.name)
    {
        return true;
    }
    if(category != __rhs.category)
    {
        return true;
    }
    return false;
}

bool
Ice::Identity::operator<(const Identity& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(category < __rhs.category)
    {
        return true;
    }
    else if(__rhs.category < category)
    {
        return false;
    }
    return false;
}

void
Ice::Identity::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(name);
    __os->write(category);
}

void
Ice::Identity::__read(::IceInternal::BasicStream* __is)
{
    __is->read(name);
    __is->read(category);
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::Identity* begin, const ::Ice::Identity* end, ::Ice::__U__IdentitySeq)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::IdentitySeq& v, ::Ice::__U__IdentitySeq)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 2);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}
