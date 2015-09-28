// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Locator.ice'

#include <Ice/Locator.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
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

static const ::std::string __Ice__Locator__findObjectById_name = "findObjectById";

static const ::std::string __Ice__Locator__findAdapterById_name = "findAdapterById";

static const ::std::string __Ice__Locator__getRegistry_name = "getRegistry";

static const ::std::string __Ice__LocatorRegistry__setAdapterDirectProxy_name = "setAdapterDirectProxy";

static const ::std::string __Ice__LocatorRegistry__setReplicatedAdapterDirectProxy_name = "setReplicatedAdapterDirectProxy";

static const ::std::string __Ice__LocatorRegistry__setServerProcessProxy_name = "setServerProcessProxy";

void
IceInternal::incRef(::Ice::Locator* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Ice::Locator* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Ice::Locator* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Ice::Locator* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::Ice::LocatorRegistry* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Ice::LocatorRegistry* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Ice::LocatorRegistry* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Ice::LocatorRegistry* p)
{
    p->__decRef();
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::LocatorPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::LocatorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Ice::Locator;
        v->__copyFrom(proxy);
    }
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::LocatorPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::LocatorRegistryPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::LocatorRegistryPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Ice::LocatorRegistry;
        v->__copyFrom(proxy);
    }
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::LocatorRegistryPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

Ice::AdapterNotFoundException::~AdapterNotFoundException() throw()
{
}

static const char* __Ice__AdapterNotFoundException_name = "Ice::AdapterNotFoundException";

::std::string
Ice::AdapterNotFoundException::ice_name() const
{
    return __Ice__AdapterNotFoundException_name;
}

::Ice::Exception*
Ice::AdapterNotFoundException::ice_clone() const
{
    return new AdapterNotFoundException(*this);
}

void
Ice::AdapterNotFoundException::ice_throw() const
{
    throw *this;
}

void
Ice::AdapterNotFoundException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Ice::AdapterNotFoundException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
Ice::AdapterNotFoundException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
Ice::AdapterNotFoundException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::AdapterNotFoundException was not generated with stream support";
    throw ex;
}

void
Ice::AdapterNotFoundException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::AdapterNotFoundException was not generated with stream support";
    throw ex;
}

struct __F__Ice__AdapterNotFoundException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Ice::AdapterNotFoundException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Ice__AdapterNotFoundException__Ptr = new __F__Ice__AdapterNotFoundException;

const ::IceInternal::UserExceptionFactoryPtr&
Ice::AdapterNotFoundException::ice_factory()
{
    return __F__Ice__AdapterNotFoundException__Ptr;
}

class __F__Ice__AdapterNotFoundException__Init
{
public:

    __F__Ice__AdapterNotFoundException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Ice::AdapterNotFoundException", ::Ice::AdapterNotFoundException::ice_factory());
    }

    ~__F__Ice__AdapterNotFoundException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Ice::AdapterNotFoundException");
    }
};

static __F__Ice__AdapterNotFoundException__Init __F__Ice__AdapterNotFoundException__i;

#ifdef __APPLE__
extern "C" { void __F__Ice__AdapterNotFoundException__initializer() {} }
#endif

Ice::InvalidReplicaGroupIdException::~InvalidReplicaGroupIdException() throw()
{
}

static const char* __Ice__InvalidReplicaGroupIdException_name = "Ice::InvalidReplicaGroupIdException";

::std::string
Ice::InvalidReplicaGroupIdException::ice_name() const
{
    return __Ice__InvalidReplicaGroupIdException_name;
}

::Ice::Exception*
Ice::InvalidReplicaGroupIdException::ice_clone() const
{
    return new InvalidReplicaGroupIdException(*this);
}

void
Ice::InvalidReplicaGroupIdException::ice_throw() const
{
    throw *this;
}

void
Ice::InvalidReplicaGroupIdException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Ice::InvalidReplicaGroupIdException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
Ice::InvalidReplicaGroupIdException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
Ice::InvalidReplicaGroupIdException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::InvalidReplicaGroupIdException was not generated with stream support";
    throw ex;
}

void
Ice::InvalidReplicaGroupIdException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::InvalidReplicaGroupIdException was not generated with stream support";
    throw ex;
}

struct __F__Ice__InvalidReplicaGroupIdException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Ice::InvalidReplicaGroupIdException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Ice__InvalidReplicaGroupIdException__Ptr = new __F__Ice__InvalidReplicaGroupIdException;

const ::IceInternal::UserExceptionFactoryPtr&
Ice::InvalidReplicaGroupIdException::ice_factory()
{
    return __F__Ice__InvalidReplicaGroupIdException__Ptr;
}

class __F__Ice__InvalidReplicaGroupIdException__Init
{
public:

    __F__Ice__InvalidReplicaGroupIdException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Ice::InvalidReplicaGroupIdException", ::Ice::InvalidReplicaGroupIdException::ice_factory());
    }

    ~__F__Ice__InvalidReplicaGroupIdException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Ice::InvalidReplicaGroupIdException");
    }
};

static __F__Ice__InvalidReplicaGroupIdException__Init __F__Ice__InvalidReplicaGroupIdException__i;

#ifdef __APPLE__
extern "C" { void __F__Ice__InvalidReplicaGroupIdException__initializer() {} }
#endif

Ice::AdapterAlreadyActiveException::~AdapterAlreadyActiveException() throw()
{
}

static const char* __Ice__AdapterAlreadyActiveException_name = "Ice::AdapterAlreadyActiveException";

::std::string
Ice::AdapterAlreadyActiveException::ice_name() const
{
    return __Ice__AdapterAlreadyActiveException_name;
}

::Ice::Exception*
Ice::AdapterAlreadyActiveException::ice_clone() const
{
    return new AdapterAlreadyActiveException(*this);
}

void
Ice::AdapterAlreadyActiveException::ice_throw() const
{
    throw *this;
}

void
Ice::AdapterAlreadyActiveException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Ice::AdapterAlreadyActiveException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
Ice::AdapterAlreadyActiveException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
Ice::AdapterAlreadyActiveException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::AdapterAlreadyActiveException was not generated with stream support";
    throw ex;
}

void
Ice::AdapterAlreadyActiveException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::AdapterAlreadyActiveException was not generated with stream support";
    throw ex;
}

struct __F__Ice__AdapterAlreadyActiveException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Ice::AdapterAlreadyActiveException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Ice__AdapterAlreadyActiveException__Ptr = new __F__Ice__AdapterAlreadyActiveException;

const ::IceInternal::UserExceptionFactoryPtr&
Ice::AdapterAlreadyActiveException::ice_factory()
{
    return __F__Ice__AdapterAlreadyActiveException__Ptr;
}

class __F__Ice__AdapterAlreadyActiveException__Init
{
public:

    __F__Ice__AdapterAlreadyActiveException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Ice::AdapterAlreadyActiveException", ::Ice::AdapterAlreadyActiveException::ice_factory());
    }

    ~__F__Ice__AdapterAlreadyActiveException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Ice::AdapterAlreadyActiveException");
    }
};

static __F__Ice__AdapterAlreadyActiveException__Init __F__Ice__AdapterAlreadyActiveException__i;

#ifdef __APPLE__
extern "C" { void __F__Ice__AdapterAlreadyActiveException__initializer() {} }
#endif

Ice::ObjectNotFoundException::~ObjectNotFoundException() throw()
{
}

static const char* __Ice__ObjectNotFoundException_name = "Ice::ObjectNotFoundException";

::std::string
Ice::ObjectNotFoundException::ice_name() const
{
    return __Ice__ObjectNotFoundException_name;
}

::Ice::Exception*
Ice::ObjectNotFoundException::ice_clone() const
{
    return new ObjectNotFoundException(*this);
}

void
Ice::ObjectNotFoundException::ice_throw() const
{
    throw *this;
}

void
Ice::ObjectNotFoundException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Ice::ObjectNotFoundException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
Ice::ObjectNotFoundException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
Ice::ObjectNotFoundException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::ObjectNotFoundException was not generated with stream support";
    throw ex;
}

void
Ice::ObjectNotFoundException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::ObjectNotFoundException was not generated with stream support";
    throw ex;
}

struct __F__Ice__ObjectNotFoundException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Ice::ObjectNotFoundException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Ice__ObjectNotFoundException__Ptr = new __F__Ice__ObjectNotFoundException;

const ::IceInternal::UserExceptionFactoryPtr&
Ice::ObjectNotFoundException::ice_factory()
{
    return __F__Ice__ObjectNotFoundException__Ptr;
}

class __F__Ice__ObjectNotFoundException__Init
{
public:

    __F__Ice__ObjectNotFoundException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Ice::ObjectNotFoundException", ::Ice::ObjectNotFoundException::ice_factory());
    }

    ~__F__Ice__ObjectNotFoundException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Ice::ObjectNotFoundException");
    }
};

static __F__Ice__ObjectNotFoundException__Init __F__Ice__ObjectNotFoundException__i;

#ifdef __APPLE__
extern "C" { void __F__Ice__ObjectNotFoundException__initializer() {} }
#endif

Ice::ServerNotFoundException::~ServerNotFoundException() throw()
{
}

static const char* __Ice__ServerNotFoundException_name = "Ice::ServerNotFoundException";

::std::string
Ice::ServerNotFoundException::ice_name() const
{
    return __Ice__ServerNotFoundException_name;
}

::Ice::Exception*
Ice::ServerNotFoundException::ice_clone() const
{
    return new ServerNotFoundException(*this);
}

void
Ice::ServerNotFoundException::ice_throw() const
{
    throw *this;
}

void
Ice::ServerNotFoundException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Ice::ServerNotFoundException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
Ice::ServerNotFoundException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
Ice::ServerNotFoundException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::ServerNotFoundException was not generated with stream support";
    throw ex;
}

void
Ice::ServerNotFoundException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Ice::ServerNotFoundException was not generated with stream support";
    throw ex;
}

struct __F__Ice__ServerNotFoundException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Ice::ServerNotFoundException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Ice__ServerNotFoundException__Ptr = new __F__Ice__ServerNotFoundException;

const ::IceInternal::UserExceptionFactoryPtr&
Ice::ServerNotFoundException::ice_factory()
{
    return __F__Ice__ServerNotFoundException__Ptr;
}

class __F__Ice__ServerNotFoundException__Init
{
public:

    __F__Ice__ServerNotFoundException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Ice::ServerNotFoundException", ::Ice::ServerNotFoundException::ice_factory());
    }

    ~__F__Ice__ServerNotFoundException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Ice::ServerNotFoundException");
    }
};

static __F__Ice__ServerNotFoundException__Init __F__Ice__ServerNotFoundException__i;

#ifdef __APPLE__
extern "C" { void __F__Ice__ServerNotFoundException__initializer() {} }
#endif

void
Ice::__addObject(const LocatorPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Ice::__usesClasses(const LocatorPtr& p)
{
    return p->__usesClasses();
}

void
Ice::__decRefUnsafe(const LocatorPtr& p)
{
    p->__decRefUnsafe();
}

void
Ice::__clearHandleUnsafe(LocatorPtr& p)
{
    p.__clearHandleUnsafe();
}

void
Ice::__addObject(const LocatorRegistryPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Ice::__usesClasses(const LocatorRegistryPtr& p)
{
    return p->__usesClasses();
}

void
Ice::__decRefUnsafe(const LocatorRegistryPtr& p)
{
    p->__decRefUnsafe();
}

void
Ice::__clearHandleUnsafe(LocatorRegistryPtr& p)
{
    p.__clearHandleUnsafe();
}

void
Ice::AMI_LocatorRegistry_setAdapterDirectProxy::__invoke(const ::Ice::LocatorRegistryPrx& __prx, const ::std::string& id, const ::Ice::ObjectPrx& proxy, const ::Ice::Context* __ctx)
{
    try
    {
        __prepare(__prx, __Ice__LocatorRegistry__setAdapterDirectProxy_name, ::Ice::Idempotent, __ctx);
        __os->write(id);
        __os->write(proxy);
        __os->endWriteEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __finished(__ex);
        return;
    }
    __send();
}

void
Ice::AMI_LocatorRegistry_setAdapterDirectProxy::__response(bool __ok)
{
    try
    {
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::AdapterAlreadyActiveException& __ex)
            {
                ice_exception(__ex);
                return;
            }
            catch(const ::Ice::AdapterNotFoundException& __ex)
            {
                ice_exception(__ex);
                return;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __finished(__ex);
        return;
    }
    ice_response();
}

void
Ice::AMI_LocatorRegistry_setReplicatedAdapterDirectProxy::__invoke(const ::Ice::LocatorRegistryPrx& __prx, const ::std::string& adapterId, const ::std::string& replicaGroupId, const ::Ice::ObjectPrx& p, const ::Ice::Context* __ctx)
{
    try
    {
        __prepare(__prx, __Ice__LocatorRegistry__setReplicatedAdapterDirectProxy_name, ::Ice::Idempotent, __ctx);
        __os->write(adapterId);
        __os->write(replicaGroupId);
        __os->write(p);
        __os->endWriteEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __finished(__ex);
        return;
    }
    __send();
}

void
Ice::AMI_LocatorRegistry_setReplicatedAdapterDirectProxy::__response(bool __ok)
{
    try
    {
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::AdapterAlreadyActiveException& __ex)
            {
                ice_exception(__ex);
                return;
            }
            catch(const ::Ice::AdapterNotFoundException& __ex)
            {
                ice_exception(__ex);
                return;
            }
            catch(const ::Ice::InvalidReplicaGroupIdException& __ex)
            {
                ice_exception(__ex);
                return;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __finished(__ex);
        return;
    }
    ice_response();
}

IceAsync::Ice::AMD_Locator_findObjectById::AMD_Locator_findObjectById(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Ice::AMD_Locator_findObjectById::ice_response(const ::Ice::ObjectPrx& __ret)
{
    try
    {
        ::IceInternal::BasicStream* __os = this->__os();
        __os->write(__ret);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
        return;
    }
    __response(true);
}

void
IceAsync::Ice::AMD_Locator_findObjectById::ice_exception(const ::Ice::Exception& ex)
{
    try
    {
        ex.ice_throw();
    }
    catch(const ::Ice::ObjectNotFoundException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
    }
}

void
IceAsync::Ice::AMD_Locator_findObjectById::ice_exception(const ::std::exception& ex)
{
    __exception(ex);
}

void
IceAsync::Ice::AMD_Locator_findObjectById::ice_exception()
{
    __exception();
}

IceAsync::Ice::AMD_Locator_findAdapterById::AMD_Locator_findAdapterById(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Ice::AMD_Locator_findAdapterById::ice_response(const ::Ice::ObjectPrx& __ret)
{
    try
    {
        ::IceInternal::BasicStream* __os = this->__os();
        __os->write(__ret);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
        return;
    }
    __response(true);
}

void
IceAsync::Ice::AMD_Locator_findAdapterById::ice_exception(const ::Ice::Exception& ex)
{
    try
    {
        ex.ice_throw();
    }
    catch(const ::Ice::AdapterNotFoundException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
    }
}

void
IceAsync::Ice::AMD_Locator_findAdapterById::ice_exception(const ::std::exception& ex)
{
    __exception(ex);
}

void
IceAsync::Ice::AMD_Locator_findAdapterById::ice_exception()
{
    __exception();
}

IceAsync::Ice::AMD_LocatorRegistry_setAdapterDirectProxy::AMD_LocatorRegistry_setAdapterDirectProxy(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Ice::AMD_LocatorRegistry_setAdapterDirectProxy::ice_response()
{
    __response(true);
}

void
IceAsync::Ice::AMD_LocatorRegistry_setAdapterDirectProxy::ice_exception(const ::Ice::Exception& ex)
{
    try
    {
        ex.ice_throw();
    }
    catch(const ::Ice::AdapterAlreadyActiveException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::AdapterNotFoundException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
    }
}

void
IceAsync::Ice::AMD_LocatorRegistry_setAdapterDirectProxy::ice_exception(const ::std::exception& ex)
{
    __exception(ex);
}

void
IceAsync::Ice::AMD_LocatorRegistry_setAdapterDirectProxy::ice_exception()
{
    __exception();
}

IceAsync::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy::ice_response()
{
    __response(true);
}

void
IceAsync::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy::ice_exception(const ::Ice::Exception& ex)
{
    try
    {
        ex.ice_throw();
    }
    catch(const ::Ice::AdapterAlreadyActiveException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::AdapterNotFoundException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::InvalidReplicaGroupIdException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
    }
}

void
IceAsync::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy::ice_exception(const ::std::exception& ex)
{
    __exception(ex);
}

void
IceAsync::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy::ice_exception()
{
    __exception();
}

IceAsync::Ice::AMD_LocatorRegistry_setServerProcessProxy::AMD_LocatorRegistry_setServerProcessProxy(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Ice::AMD_LocatorRegistry_setServerProcessProxy::ice_response()
{
    __response(true);
}

void
IceAsync::Ice::AMD_LocatorRegistry_setServerProcessProxy::ice_exception(const ::Ice::Exception& ex)
{
    try
    {
        ex.ice_throw();
    }
    catch(const ::Ice::ServerNotFoundException& __ex)
    {
        __os()->write(__ex);
        __response(false);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __exception(__ex);
    }
}

void
IceAsync::Ice::AMD_LocatorRegistry_setServerProcessProxy::ice_exception(const ::std::exception& ex)
{
    __exception(ex);
}

void
IceAsync::Ice::AMD_LocatorRegistry_setServerProcessProxy::ice_exception()
{
    __exception();
}

::Ice::ObjectPrx
IceProxy::Ice::Locator::findObjectById(const ::Ice::Identity& id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__Locator__findObjectById_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Locator* __del = dynamic_cast< ::IceDelegate::Ice::Locator*>(__delBase.get());
            return __del->findObjectById(id, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::ObjectPrx
IceProxy::Ice::Locator::findAdapterById(const ::std::string& id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__Locator__findAdapterById_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Locator* __del = dynamic_cast< ::IceDelegate::Ice::Locator*>(__delBase.get());
            return __del->findAdapterById(id, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::LocatorRegistryPrx
IceProxy::Ice::Locator::getRegistry(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__Locator__getRegistry_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Locator* __del = dynamic_cast< ::IceDelegate::Ice::Locator*>(__delBase.get());
            return __del->getRegistry(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Ice::Locator::ice_staticId()
{
    return ::Ice::Locator::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Ice::Locator::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Ice::Locator);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Ice::Locator::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Ice::Locator);
}

bool
IceProxy::Ice::operator==(const ::IceProxy::Ice::Locator& l, const ::IceProxy::Ice::Locator& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator!=(const ::IceProxy::Ice::Locator& l, const ::IceProxy::Ice::Locator& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<(const ::IceProxy::Ice::Locator& l, const ::IceProxy::Ice::Locator& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<=(const ::IceProxy::Ice::Locator& l, const ::IceProxy::Ice::Locator& r)
{
    return l < r || l == r;
}

bool
IceProxy::Ice::operator>(const ::IceProxy::Ice::Locator& l, const ::IceProxy::Ice::Locator& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Ice::operator>=(const ::IceProxy::Ice::Locator& l, const ::IceProxy::Ice::Locator& r)
{
    return !(l < r);
}

void
IceProxy::Ice::LocatorRegistry::setAdapterDirectProxy(const ::std::string& id, const ::Ice::ObjectPrx& proxy, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__LocatorRegistry__setAdapterDirectProxy_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::LocatorRegistry* __del = dynamic_cast< ::IceDelegate::Ice::LocatorRegistry*>(__delBase.get());
            __del->setAdapterDirectProxy(id, proxy, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Ice::LocatorRegistry::setAdapterDirectProxy_async(const ::Ice::AMI_LocatorRegistry_setAdapterDirectProxyPtr& __cb, const ::std::string& id, const ::Ice::ObjectPrx& proxy)
{
    __cb->__invoke(this, id, proxy, 0);
}

void
IceProxy::Ice::LocatorRegistry::setAdapterDirectProxy_async(const ::Ice::AMI_LocatorRegistry_setAdapterDirectProxyPtr& __cb, const ::std::string& id, const ::Ice::ObjectPrx& proxy, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, id, proxy, &__ctx);
}

void
IceProxy::Ice::LocatorRegistry::setReplicatedAdapterDirectProxy(const ::std::string& adapterId, const ::std::string& replicaGroupId, const ::Ice::ObjectPrx& p, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__LocatorRegistry__setReplicatedAdapterDirectProxy_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::LocatorRegistry* __del = dynamic_cast< ::IceDelegate::Ice::LocatorRegistry*>(__delBase.get());
            __del->setReplicatedAdapterDirectProxy(adapterId, replicaGroupId, p, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Ice::LocatorRegistry::setReplicatedAdapterDirectProxy_async(const ::Ice::AMI_LocatorRegistry_setReplicatedAdapterDirectProxyPtr& __cb, const ::std::string& adapterId, const ::std::string& replicaGroupId, const ::Ice::ObjectPrx& p)
{
    __cb->__invoke(this, adapterId, replicaGroupId, p, 0);
}

void
IceProxy::Ice::LocatorRegistry::setReplicatedAdapterDirectProxy_async(const ::Ice::AMI_LocatorRegistry_setReplicatedAdapterDirectProxyPtr& __cb, const ::std::string& adapterId, const ::std::string& replicaGroupId, const ::Ice::ObjectPrx& p, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, adapterId, replicaGroupId, p, &__ctx);
}

void
IceProxy::Ice::LocatorRegistry::setServerProcessProxy(const ::std::string& id, const ::Ice::ProcessPrx& proxy, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__LocatorRegistry__setServerProcessProxy_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::LocatorRegistry* __del = dynamic_cast< ::IceDelegate::Ice::LocatorRegistry*>(__delBase.get());
            __del->setServerProcessProxy(id, proxy, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Ice::LocatorRegistry::ice_staticId()
{
    return ::Ice::LocatorRegistry::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Ice::LocatorRegistry::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Ice::LocatorRegistry);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Ice::LocatorRegistry::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Ice::LocatorRegistry);
}

bool
IceProxy::Ice::operator==(const ::IceProxy::Ice::LocatorRegistry& l, const ::IceProxy::Ice::LocatorRegistry& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator!=(const ::IceProxy::Ice::LocatorRegistry& l, const ::IceProxy::Ice::LocatorRegistry& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<(const ::IceProxy::Ice::LocatorRegistry& l, const ::IceProxy::Ice::LocatorRegistry& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<=(const ::IceProxy::Ice::LocatorRegistry& l, const ::IceProxy::Ice::LocatorRegistry& r)
{
    return l < r || l == r;
}

bool
IceProxy::Ice::operator>(const ::IceProxy::Ice::LocatorRegistry& l, const ::IceProxy::Ice::LocatorRegistry& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Ice::operator>=(const ::IceProxy::Ice::LocatorRegistry& l, const ::IceProxy::Ice::LocatorRegistry& r)
{
    return !(l < r);
}

::Ice::ObjectPrx
IceDelegateM::Ice::Locator::findObjectById(const ::Ice::Identity& id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Locator__findObjectById_name, ::Ice::Nonmutating, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        id.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::ObjectNotFoundException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::ObjectPrx __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::ObjectPrx
IceDelegateM::Ice::Locator::findAdapterById(const ::std::string& id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Locator__findAdapterById_name, ::Ice::Nonmutating, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::AdapterNotFoundException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::ObjectPrx __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::LocatorRegistryPrx
IceDelegateM::Ice::Locator::getRegistry(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Locator__getRegistry_name, ::Ice::Nonmutating, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::LocatorRegistryPrx __ret;
        ::Ice::__read(__is, __ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Ice::LocatorRegistry::setAdapterDirectProxy(const ::std::string& id, const ::Ice::ObjectPrx& proxy, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__LocatorRegistry__setAdapterDirectProxy_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
        __os->write(proxy);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::AdapterAlreadyActiveException&)
            {
                throw;
            }
            catch(const ::Ice::AdapterNotFoundException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Ice::LocatorRegistry::setReplicatedAdapterDirectProxy(const ::std::string& adapterId, const ::std::string& replicaGroupId, const ::Ice::ObjectPrx& p, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__LocatorRegistry__setReplicatedAdapterDirectProxy_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(adapterId);
        __os->write(replicaGroupId);
        __os->write(p);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::AdapterAlreadyActiveException&)
            {
                throw;
            }
            catch(const ::Ice::AdapterNotFoundException&)
            {
                throw;
            }
            catch(const ::Ice::InvalidReplicaGroupIdException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Ice::LocatorRegistry::setServerProcessProxy(const ::std::string& id, const ::Ice::ProcessPrx& proxy, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__LocatorRegistry__setServerProcessProxy_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
        ::Ice::__write(__os, proxy);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::ServerNotFoundException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::ObjectPrx
IceDelegateD::Ice::Locator::findObjectById(const ::Ice::Identity&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::ObjectPrx(); // to avoid a warning with some compilers;
}

::Ice::ObjectPrx
IceDelegateD::Ice::Locator::findAdapterById(const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::ObjectPrx(); // to avoid a warning with some compilers;
}

::Ice::LocatorRegistryPrx
IceDelegateD::Ice::Locator::getRegistry(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Locator__getRegistry_name, ::Ice::Nonmutating, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::LocatorRegistryPrx __ret;
        try
        {
            ::Ice::Locator* __servant = dynamic_cast< ::Ice::Locator*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getRegistry(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::Ice::LocatorRegistry::setAdapterDirectProxy(const ::std::string&, const ::Ice::ObjectPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Ice::LocatorRegistry::setReplicatedAdapterDirectProxy(const ::std::string&, const ::std::string&, const ::Ice::ObjectPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Ice::LocatorRegistry::setServerProcessProxy(const ::std::string&, const ::Ice::ProcessPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Ice::ObjectPtr
Ice::Locator::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Ice__Locator_ids[2] =
{
    "::Ice::Locator",
    "::Ice::Object"
};

bool
Ice::Locator::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Ice__Locator_ids, __Ice__Locator_ids + 2, _s);
}

::std::vector< ::std::string>
Ice::Locator::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Ice__Locator_ids[0], &__Ice__Locator_ids[2]);
}

const ::std::string&
Ice::Locator::ice_id(const ::Ice::Current&) const
{
    return __Ice__Locator_ids[0];
}

const ::std::string&
Ice::Locator::ice_staticId()
{
    return __Ice__Locator_ids[0];
}

::IceInternal::DispatchStatus
Ice::Locator::___findObjectById(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Identity id;
    id.__read(__is);
    ::Ice::AMD_Locator_findObjectByIdPtr __cb = new IceAsync::Ice::AMD_Locator_findObjectById(__inS);
    try
    {
        findObjectById_async(__cb, id, __current);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::IceInternal::DispatchAsync;
}

::IceInternal::DispatchStatus
Ice::Locator::___findAdapterById(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string id;
    __is->read(id);
    ::Ice::AMD_Locator_findAdapterByIdPtr __cb = new IceAsync::Ice::AMD_Locator_findAdapterById(__inS);
    try
    {
        findAdapterById_async(__cb, id, __current);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::IceInternal::DispatchAsync;
}

::IceInternal::DispatchStatus
Ice::Locator::___getRegistry(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::LocatorRegistryPrx __ret = getRegistry(__current);
    ::Ice::__write(__os, __ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __Ice__Locator_all[] =
{
    "findAdapterById",
    "findObjectById",
    "getRegistry",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
Ice::Locator::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Ice__Locator_all, __Ice__Locator_all + 7, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Ice__Locator_all)
    {
        case 0:
        {
            return ___findAdapterById(in, current);
        }
        case 1:
        {
            return ___findObjectById(in, current);
        }
        case 2:
        {
            return ___getRegistry(in, current);
        }
        case 3:
        {
            return ___ice_id(in, current);
        }
        case 4:
        {
            return ___ice_ids(in, current);
        }
        case 5:
        {
            return ___ice_isA(in, current);
        }
        case 6:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Ice::Locator::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Ice::Locator::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Ice::Locator::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::Locator was not generated with stream support";
    throw ex;
}

void
Ice::Locator::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::Locator was not generated with stream support";
    throw ex;
}

void ICE_API 
Ice::__patch__LocatorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Ice::LocatorPtr* p = static_cast< ::Ice::LocatorPtr*>(__addr);
    assert(p);
    *p = ::Ice::LocatorPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Ice::Locator::ice_staticId();
        throw e;
    }
}

bool
Ice::operator==(const ::Ice::Locator& l, const ::Ice::Locator& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator!=(const ::Ice::Locator& l, const ::Ice::Locator& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<(const ::Ice::Locator& l, const ::Ice::Locator& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<=(const ::Ice::Locator& l, const ::Ice::Locator& r)
{
    return l < r || l == r;
}

bool
Ice::operator>(const ::Ice::Locator& l, const ::Ice::Locator& r)
{
    return !(l < r) && !(l == r);
}

bool
Ice::operator>=(const ::Ice::Locator& l, const ::Ice::Locator& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
Ice::LocatorRegistry::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Ice__LocatorRegistry_ids[2] =
{
    "::Ice::LocatorRegistry",
    "::Ice::Object"
};

bool
Ice::LocatorRegistry::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Ice__LocatorRegistry_ids, __Ice__LocatorRegistry_ids + 2, _s);
}

::std::vector< ::std::string>
Ice::LocatorRegistry::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Ice__LocatorRegistry_ids[0], &__Ice__LocatorRegistry_ids[2]);
}

const ::std::string&
Ice::LocatorRegistry::ice_id(const ::Ice::Current&) const
{
    return __Ice__LocatorRegistry_ids[0];
}

const ::std::string&
Ice::LocatorRegistry::ice_staticId()
{
    return __Ice__LocatorRegistry_ids[0];
}

::IceInternal::DispatchStatus
Ice::LocatorRegistry::___setAdapterDirectProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string id;
    ::Ice::ObjectPrx proxy;
    __is->read(id);
    __is->read(proxy);
    ::Ice::AMD_LocatorRegistry_setAdapterDirectProxyPtr __cb = new IceAsync::Ice::AMD_LocatorRegistry_setAdapterDirectProxy(__inS);
    try
    {
        setAdapterDirectProxy_async(__cb, id, proxy, __current);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::IceInternal::DispatchAsync;
}

::IceInternal::DispatchStatus
Ice::LocatorRegistry::___setReplicatedAdapterDirectProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string adapterId;
    ::std::string replicaGroupId;
    ::Ice::ObjectPrx p;
    __is->read(adapterId);
    __is->read(replicaGroupId);
    __is->read(p);
    ::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxyPtr __cb = new IceAsync::Ice::AMD_LocatorRegistry_setReplicatedAdapterDirectProxy(__inS);
    try
    {
        setReplicatedAdapterDirectProxy_async(__cb, adapterId, replicaGroupId, p, __current);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::IceInternal::DispatchAsync;
}

::IceInternal::DispatchStatus
Ice::LocatorRegistry::___setServerProcessProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string id;
    ::Ice::ProcessPrx proxy;
    __is->read(id);
    ::Ice::__read(__is, proxy);
    ::Ice::AMD_LocatorRegistry_setServerProcessProxyPtr __cb = new IceAsync::Ice::AMD_LocatorRegistry_setServerProcessProxy(__inS);
    try
    {
        setServerProcessProxy_async(__cb, id, proxy, __current);
    }
    catch(const ::Ice::Exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::IceInternal::DispatchAsync;
}

static ::std::string __Ice__LocatorRegistry_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setAdapterDirectProxy",
    "setReplicatedAdapterDirectProxy",
    "setServerProcessProxy"
};

::IceInternal::DispatchStatus
Ice::LocatorRegistry::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Ice__LocatorRegistry_all, __Ice__LocatorRegistry_all + 7, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Ice__LocatorRegistry_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___setAdapterDirectProxy(in, current);
        }
        case 5:
        {
            return ___setReplicatedAdapterDirectProxy(in, current);
        }
        case 6:
        {
            return ___setServerProcessProxy(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Ice::LocatorRegistry::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Ice::LocatorRegistry::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Ice::LocatorRegistry::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::LocatorRegistry was not generated with stream support";
    throw ex;
}

void
Ice::LocatorRegistry::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::LocatorRegistry was not generated with stream support";
    throw ex;
}

void ICE_API 
Ice::__patch__LocatorRegistryPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Ice::LocatorRegistryPtr* p = static_cast< ::Ice::LocatorRegistryPtr*>(__addr);
    assert(p);
    *p = ::Ice::LocatorRegistryPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Ice::LocatorRegistry::ice_staticId();
        throw e;
    }
}

bool
Ice::operator==(const ::Ice::LocatorRegistry& l, const ::Ice::LocatorRegistry& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator!=(const ::Ice::LocatorRegistry& l, const ::Ice::LocatorRegistry& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<(const ::Ice::LocatorRegistry& l, const ::Ice::LocatorRegistry& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<=(const ::Ice::LocatorRegistry& l, const ::Ice::LocatorRegistry& r)
{
    return l < r || l == r;
}

bool
Ice::operator>(const ::Ice::LocatorRegistry& l, const ::Ice::LocatorRegistry& r)
{
    return !(l < r) && !(l == r);
}

bool
Ice::operator>=(const ::Ice::LocatorRegistry& l, const ::Ice::LocatorRegistry& r)
{
    return !(l < r);
}
