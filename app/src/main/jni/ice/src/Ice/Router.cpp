// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Router.ice'

#include <Ice/Router.h>
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

static const ::std::string __Ice__Router__getClientProxy_name = "getClientProxy";

static const ::std::string __Ice__Router__getServerProxy_name = "getServerProxy";

static const ::std::string __Ice__Router__addProxy_name = "addProxy";

static const ::std::string __Ice__Router__addProxies_name = "addProxies";

void
IceInternal::incRef(::Ice::Router* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Ice::Router* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Ice::Router* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Ice::Router* p)
{
    p->__decRef();
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::RouterPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::RouterPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Ice::Router;
        v->__copyFrom(proxy);
    }
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::RouterPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
Ice::__addObject(const RouterPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Ice::__usesClasses(const RouterPtr& p)
{
    return p->__usesClasses();
}

void
Ice::__decRefUnsafe(const RouterPtr& p)
{
    p->__decRefUnsafe();
}

void
Ice::__clearHandleUnsafe(RouterPtr& p)
{
    p.__clearHandleUnsafe();
}

::Ice::ObjectPrx
IceProxy::Ice::Router::getClientProxy(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__Router__getClientProxy_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Router* __del = dynamic_cast< ::IceDelegate::Ice::Router*>(__delBase.get());
            return __del->getClientProxy(__ctx);
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
IceProxy::Ice::Router::getServerProxy(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__Router__getServerProxy_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Router* __del = dynamic_cast< ::IceDelegate::Ice::Router*>(__delBase.get());
            return __del->getServerProxy(__ctx);
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
IceProxy::Ice::Router::addProxy(const ::Ice::ObjectPrx& proxy, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Router* __del = dynamic_cast< ::IceDelegate::Ice::Router*>(__delBase.get());
            __del->addProxy(proxy, __ctx);
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

::Ice::ObjectProxySeq
IceProxy::Ice::Router::addProxies(const ::Ice::ObjectProxySeq& proxies, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Ice__Router__addProxies_name);
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Router* __del = dynamic_cast< ::IceDelegate::Ice::Router*>(__delBase.get());
            return __del->addProxies(proxies, __ctx);
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
IceProxy::Ice::Router::ice_staticId()
{
    return ::Ice::Router::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Ice::Router::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Ice::Router);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Ice::Router::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Ice::Router);
}

bool
IceProxy::Ice::operator==(const ::IceProxy::Ice::Router& l, const ::IceProxy::Ice::Router& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator!=(const ::IceProxy::Ice::Router& l, const ::IceProxy::Ice::Router& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<(const ::IceProxy::Ice::Router& l, const ::IceProxy::Ice::Router& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<=(const ::IceProxy::Ice::Router& l, const ::IceProxy::Ice::Router& r)
{
    return l < r || l == r;
}

bool
IceProxy::Ice::operator>(const ::IceProxy::Ice::Router& l, const ::IceProxy::Ice::Router& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Ice::operator>=(const ::IceProxy::Ice::Router& l, const ::IceProxy::Ice::Router& r)
{
    return !(l < r);
}

::Ice::ObjectPrx
IceDelegateM::Ice::Router::getClientProxy(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Router__getClientProxy_name, ::Ice::Nonmutating, __context, __compress);
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
IceDelegateM::Ice::Router::getServerProxy(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Router__getServerProxy_name, ::Ice::Nonmutating, __context, __compress);
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
        ::Ice::ObjectPrx __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Ice::Router::addProxy(const ::Ice::ObjectPrx& proxy, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Router__addProxy_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
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

::Ice::ObjectProxySeq
IceDelegateM::Ice::Router::addProxies(const ::Ice::ObjectProxySeq& proxies, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Router__addProxies_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        if(proxies.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Ice::__write(__os, &proxies[0], &proxies[0] + proxies.size(), ::Ice::__U__ObjectProxySeq());
        }
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
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::ObjectProxySeq __ret;
        ::Ice::__read(__is, __ret, ::Ice::__U__ObjectProxySeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::ObjectPrx
IceDelegateD::Ice::Router::getClientProxy(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Router__getClientProxy_name, ::Ice::Nonmutating, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::ObjectPrx __ret;
        try
        {
            ::Ice::Router* __servant = dynamic_cast< ::Ice::Router*>(__direct.servant().get());
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
                __ret = __servant->getClientProxy(__current);
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

::Ice::ObjectPrx
IceDelegateD::Ice::Router::getServerProxy(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Router__getServerProxy_name, ::Ice::Nonmutating, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::ObjectPrx __ret;
        try
        {
            ::Ice::Router* __servant = dynamic_cast< ::Ice::Router*>(__direct.servant().get());
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
                __ret = __servant->getServerProxy(__current);
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
IceDelegateD::Ice::Router::addProxy(const ::Ice::ObjectPrx& proxy, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Router__addProxy_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Ice::Router* __servant = dynamic_cast< ::Ice::Router*>(__direct.servant().get());
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
                __servant->addProxy(proxy, __current);
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
        return;
    }
}

::Ice::ObjectProxySeq
IceDelegateD::Ice::Router::addProxies(const ::Ice::ObjectProxySeq& proxies, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Router__addProxies_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::ObjectProxySeq __ret;
        try
        {
            ::Ice::Router* __servant = dynamic_cast< ::Ice::Router*>(__direct.servant().get());
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
                __ret = __servant->addProxies(proxies, __current);
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

::Ice::ObjectPtr
Ice::Router::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Ice__Router_ids[2] =
{
    "::Ice::Object",
    "::Ice::Router"
};

bool
Ice::Router::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Ice__Router_ids, __Ice__Router_ids + 2, _s);
}

::std::vector< ::std::string>
Ice::Router::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Ice__Router_ids[0], &__Ice__Router_ids[2]);
}

const ::std::string&
Ice::Router::ice_id(const ::Ice::Current&) const
{
    return __Ice__Router_ids[1];
}

const ::std::string&
Ice::Router::ice_staticId()
{
    return __Ice__Router_ids[1];
}

::IceInternal::DispatchStatus
Ice::Router::___getClientProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::ObjectPrx __ret = getClientProxy(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Ice::Router::___getServerProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::ObjectPrx __ret = getServerProxy(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Ice::Router::___addProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    addProxy(proxy, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Ice::Router::___addProxies(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::ObjectProxySeq proxies;
    ::Ice::__read(__is, proxies, ::Ice::__U__ObjectProxySeq());
    ::Ice::ObjectProxySeq __ret = addProxies(proxies, __current);
    if(__ret.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::Ice::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Ice::__U__ObjectProxySeq());
    }
    return ::IceInternal::DispatchOK;
}

static ::std::string __Ice__Router_all[] =
{
    "addProxies",
    "addProxy",
    "getClientProxy",
    "getServerProxy",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
Ice::Router::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Ice__Router_all, __Ice__Router_all + 8, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Ice__Router_all)
    {
        case 0:
        {
            return ___addProxies(in, current);
        }
        case 1:
        {
            return ___addProxy(in, current);
        }
        case 2:
        {
            return ___getClientProxy(in, current);
        }
        case 3:
        {
            return ___getServerProxy(in, current);
        }
        case 4:
        {
            return ___ice_id(in, current);
        }
        case 5:
        {
            return ___ice_ids(in, current);
        }
        case 6:
        {
            return ___ice_isA(in, current);
        }
        case 7:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Ice::Router::__write(::IceInternal::BasicStream* __os) const
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
Ice::Router::__read(::IceInternal::BasicStream* __is, bool __rid)
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
Ice::Router::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::Router was not generated with stream support";
    throw ex;
}

void
Ice::Router::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::Router was not generated with stream support";
    throw ex;
}

void ICE_API 
Ice::__patch__RouterPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Ice::RouterPtr* p = static_cast< ::Ice::RouterPtr*>(__addr);
    assert(p);
    *p = ::Ice::RouterPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Ice::Router::ice_staticId();
        throw e;
    }
}

bool
Ice::operator==(const ::Ice::Router& l, const ::Ice::Router& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator!=(const ::Ice::Router& l, const ::Ice::Router& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<(const ::Ice::Router& l, const ::Ice::Router& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<=(const ::Ice::Router& l, const ::Ice::Router& r)
{
    return l < r || l == r;
}

bool
Ice::operator>(const ::Ice::Router& l, const ::Ice::Router& r)
{
    return !(l < r) && !(l == r);
}

bool
Ice::operator>=(const ::Ice::Router& l, const ::Ice::Router& r)
{
    return !(l < r);
}
