// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Connection.ice'

#include <Ice/Connection.h>
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

static const ::std::string __Ice__Connection__close_name = "close";

static const ::std::string __Ice__Connection__createProxy_name = "createProxy";

static const ::std::string __Ice__Connection__setAdapter_name = "setAdapter";

static const ::std::string __Ice__Connection__getAdapter_name = "getAdapter";

static const ::std::string __Ice__Connection__flushBatchRequests_name = "flushBatchRequests";

static const ::std::string __Ice__Connection__type_name = "type";

static const ::std::string __Ice__Connection__timeout_name = "timeout";

static const ::std::string __Ice__Connection__toString_name = "toString";

void
IceInternal::incRef(::Ice::Connection* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Ice::Connection* p)
{
    p->__decRef();
}

bool
Ice::operator==(const ::Ice::Connection& l, const ::Ice::Connection& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) == static_cast<const ::Ice::LocalObject&>(r);
}

bool
Ice::operator!=(const ::Ice::Connection& l, const ::Ice::Connection& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) != static_cast<const ::Ice::LocalObject&>(r);
}

bool
Ice::operator<(const ::Ice::Connection& l, const ::Ice::Connection& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) < static_cast<const ::Ice::LocalObject&>(r);
}

bool
Ice::operator<=(const ::Ice::Connection& l, const ::Ice::Connection& r)
{
    return l < r || l == r;
}

bool
Ice::operator>(const ::Ice::Connection& l, const ::Ice::Connection& r)
{
    return !(l < r) && !(l == r);
}

bool
Ice::operator>=(const ::Ice::Connection& l, const ::Ice::Connection& r)
{
    return !(l < r);
}
