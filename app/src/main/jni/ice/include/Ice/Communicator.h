// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Communicator.ice'

#ifndef __Ice_Communicator_h__
#define __Ice_Communicator_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/LoggerF.h>
#include <Ice/StatsF.h>
#include <Ice/ObjectAdapterF.h>
#include <Ice/PropertiesF.h>
#include <Ice/ObjectFactoryF.h>
#include <Ice/RouterF.h>
#include <Ice/LocatorF.h>
#include <Ice/PluginF.h>
#include <Ice/ImplicitContextF.h>
#include <Ice/Current.h>
#include <Ice/UndefSysMacros.h>

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

#ifndef ICE_API
#   ifdef ICE_API_EXPORTS
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

}

namespace Ice
{

class Communicator;
ICE_API bool operator==(const Communicator&, const Communicator&);
ICE_API bool operator!=(const Communicator&, const Communicator&);
ICE_API bool operator<(const Communicator&, const Communicator&);
ICE_API bool operator<=(const Communicator&, const Communicator&);
ICE_API bool operator>(const Communicator&, const Communicator&);
ICE_API bool operator>=(const Communicator&, const Communicator&);

}

namespace IceInternal
{

ICE_API void incRef(::Ice::Communicator*);
ICE_API void decRef(::Ice::Communicator*);

}

namespace Ice
{

typedef ::IceInternal::Handle< ::Ice::Communicator> CommunicatorPtr;

}

namespace Ice
{

}

namespace IceProxy
{

}

namespace IceDelegate
{

}

namespace IceDelegateM
{

}

namespace IceDelegateD
{

}

namespace Ice
{

class ICE_API Communicator : virtual public ::Ice::LocalObject
{
public:

    typedef CommunicatorPtr PointerType;
    

    virtual void destroy() = 0;

    virtual void shutdown() = 0;

    virtual void waitForShutdown() = 0;

    virtual bool isShutdown() const = 0;

    virtual ::Ice::ObjectPrx stringToProxy(const ::std::string&) const = 0;

    virtual ::std::string proxyToString(const ::Ice::ObjectPrx&) const = 0;

    virtual ::Ice::ObjectPrx propertyToProxy(const ::std::string&) const = 0;

    virtual ::Ice::Identity stringToIdentity(const ::std::string&) const = 0;

    virtual ::std::string identityToString(const ::Ice::Identity&) const = 0;

    virtual ::Ice::ObjectAdapterPtr createObjectAdapter(const ::std::string&) = 0;

    virtual ::Ice::ObjectAdapterPtr createObjectAdapterWithEndpoints(const ::std::string&, const ::std::string&) = 0;

    virtual ::Ice::ObjectAdapterPtr createObjectAdapterWithRouter(const ::std::string&, const ::Ice::RouterPrx&) = 0;

    virtual void addObjectFactory(const ::Ice::ObjectFactoryPtr&, const ::std::string&) = 0;

    virtual ::Ice::ObjectFactoryPtr findObjectFactory(const ::std::string&) const = 0;

    ICE_DEPRECATED_API virtual ::Ice::Context getDefaultContext() const = 0;

    ICE_DEPRECATED_API virtual void setDefaultContext(const ::Ice::Context&) = 0;

    virtual ::Ice::ImplicitContextPtr getImplicitContext() const = 0;

    virtual ::Ice::PropertiesPtr getProperties() const = 0;

    virtual ::Ice::LoggerPtr getLogger() const = 0;

    virtual ::Ice::StatsPtr getStats() const = 0;

    virtual ::Ice::RouterPrx getDefaultRouter() const = 0;

    virtual void setDefaultRouter(const ::Ice::RouterPrx&) = 0;

    virtual ::Ice::LocatorPrx getDefaultLocator() const = 0;

    virtual void setDefaultLocator(const ::Ice::LocatorPrx&) = 0;

    virtual ::Ice::PluginManagerPtr getPluginManager() const = 0;

    virtual void flushBatchRequests() = 0;
};

}

#endif
