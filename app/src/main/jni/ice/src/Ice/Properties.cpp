// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Properties.ice'

#include <Ice/Properties.h>
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

static const ::std::string __Ice__Properties__getProperty_name = "getProperty";

static const ::std::string __Ice__Properties__getPropertyWithDefault_name = "getPropertyWithDefault";

static const ::std::string __Ice__Properties__getPropertyAsInt_name = "getPropertyAsInt";

static const ::std::string __Ice__Properties__getPropertyAsIntWithDefault_name = "getPropertyAsIntWithDefault";

static const ::std::string __Ice__Properties__getPropertiesForPrefix_name = "getPropertiesForPrefix";

static const ::std::string __Ice__Properties__setProperty_name = "setProperty";

static const ::std::string __Ice__Properties__getCommandLineOptions_name = "getCommandLineOptions";

static const ::std::string __Ice__Properties__parseCommandLineOptions_name = "parseCommandLineOptions";

static const ::std::string __Ice__Properties__parseIceCommandLineOptions_name = "parseIceCommandLineOptions";

static const ::std::string __Ice__Properties__load_name = "load";

static const ::std::string __Ice__Properties__clone_name = "clone";

void
IceInternal::incRef(::Ice::Properties* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Ice::Properties* p)
{
    p->__decRef();
}

bool
Ice::operator==(const ::Ice::Properties& l, const ::Ice::Properties& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) == static_cast<const ::Ice::LocalObject&>(r);
}

bool
Ice::operator!=(const ::Ice::Properties& l, const ::Ice::Properties& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) != static_cast<const ::Ice::LocalObject&>(r);
}

bool
Ice::operator<(const ::Ice::Properties& l, const ::Ice::Properties& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) < static_cast<const ::Ice::LocalObject&>(r);
}

bool
Ice::operator<=(const ::Ice::Properties& l, const ::Ice::Properties& r)
{
    return l < r || l == r;
}

bool
Ice::operator>(const ::Ice::Properties& l, const ::Ice::Properties& r)
{
    return !(l < r) && !(l == r);
}

bool
Ice::operator>=(const ::Ice::Properties& l, const ::Ice::Properties& r)
{
    return !(l < r);
}
