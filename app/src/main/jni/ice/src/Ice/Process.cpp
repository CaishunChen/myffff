// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `Process.ice'

#include <Ice/Process.h>
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

static const ::std::string __Ice__Process__shutdown_name = "shutdown";

static const ::std::string __Ice__Process__writeMessage_name = "writeMessage";

void
IceInternal::incRef(::Ice::Process* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Ice::Process* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Ice::Process* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Ice::Process* p)
{
    p->__decRef();
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::ProcessPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Ice::__read(::IceInternal::BasicStream* __is, ::Ice::ProcessPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Ice::Process;
        v->__copyFrom(proxy);
    }
}

void
Ice::__write(::IceInternal::BasicStream* __os, const ::Ice::ProcessPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
Ice::__addObject(const ProcessPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Ice::__usesClasses(const ProcessPtr& p)
{
    return p->__usesClasses();
}

void
Ice::__decRefUnsafe(const ProcessPtr& p)
{
    p->__decRefUnsafe();
}

void
Ice::__clearHandleUnsafe(ProcessPtr& p)
{
    p.__clearHandleUnsafe();
}

void
Ice::AMI_Process_shutdown::__invoke(const ::Ice::ProcessPrx& __prx, const ::Ice::Context* __ctx)
{
    try
    {
        __prepare(__prx, __Ice__Process__shutdown_name, ::Ice::Normal, __ctx);
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
Ice::AMI_Process_shutdown::__response(bool __ok)
{
    try
    {
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
        __finished(__ex);
        return;
    }
    ice_response();
}

void
IceProxy::Ice::Process::shutdown(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Process* __del = dynamic_cast< ::IceDelegate::Ice::Process*>(__delBase.get());
            __del->shutdown(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Ice::Process::shutdown_async(const ::Ice::AMI_Process_shutdownPtr& __cb)
{
    __cb->__invoke(this, 0);
}

void
IceProxy::Ice::Process::shutdown_async(const ::Ice::AMI_Process_shutdownPtr& __cb, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, &__ctx);
}

void
IceProxy::Ice::Process::writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::Ice::Process* __del = dynamic_cast< ::IceDelegate::Ice::Process*>(__delBase.get());
            __del->writeMessage(message, fd, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Ice::Process::ice_staticId()
{
    return ::Ice::Process::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Ice::Process::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Ice::Process);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Ice::Process::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Ice::Process);
}

bool
IceProxy::Ice::operator==(const ::IceProxy::Ice::Process& l, const ::IceProxy::Ice::Process& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator!=(const ::IceProxy::Ice::Process& l, const ::IceProxy::Ice::Process& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<(const ::IceProxy::Ice::Process& l, const ::IceProxy::Ice::Process& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Ice::operator<=(const ::IceProxy::Ice::Process& l, const ::IceProxy::Ice::Process& r)
{
    return l < r || l == r;
}

bool
IceProxy::Ice::operator>(const ::IceProxy::Ice::Process& l, const ::IceProxy::Ice::Process& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Ice::operator>=(const ::IceProxy::Ice::Process& l, const ::IceProxy::Ice::Process& r)
{
    return !(l < r);
}

void
IceDelegateM::Ice::Process::shutdown(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Process__shutdown_name, ::Ice::Normal, __context, __compress);
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

void
IceDelegateM::Ice::Process::writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Ice__Process__writeMessage_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(fd);
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

void
IceDelegateD::Ice::Process::shutdown(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Process__shutdown_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Ice::Process* __servant = dynamic_cast< ::Ice::Process*>(__direct.servant().get());
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
                __servant->shutdown(__current);
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

void
IceDelegateD::Ice::Process::writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Ice__Process__writeMessage_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Ice::Process* __servant = dynamic_cast< ::Ice::Process*>(__direct.servant().get());
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
                __servant->writeMessage(message, fd, __current);
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

::Ice::ObjectPtr
Ice::Process::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Ice__Process_ids[2] =
{
    "::Ice::Object",
    "::Ice::Process"
};

bool
Ice::Process::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Ice__Process_ids, __Ice__Process_ids + 2, _s);
}

::std::vector< ::std::string>
Ice::Process::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Ice__Process_ids[0], &__Ice__Process_ids[2]);
}

const ::std::string&
Ice::Process::ice_id(const ::Ice::Current&) const
{
    return __Ice__Process_ids[1];
}

const ::std::string&
Ice::Process::ice_staticId()
{
    return __Ice__Process_ids[1];
}

::IceInternal::DispatchStatus
Ice::Process::___shutdown(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    shutdown(__current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Ice::Process::___writeMessage(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::Ice::Int fd;
    __is->read(message);
    __is->read(fd);
    writeMessage(message, fd, __current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __Ice__Process_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown",
    "writeMessage"
};

::IceInternal::DispatchStatus
Ice::Process::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Ice__Process_all, __Ice__Process_all + 6, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Ice__Process_all)
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
            return ___shutdown(in, current);
        }
        case 5:
        {
            return ___writeMessage(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Ice::Process::__write(::IceInternal::BasicStream* __os) const
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
Ice::Process::__read(::IceInternal::BasicStream* __is, bool __rid)
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
Ice::Process::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::Process was not generated with stream support";
    throw ex;
}

void
Ice::Process::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Ice::Process was not generated with stream support";
    throw ex;
}

void ICE_API 
Ice::__patch__ProcessPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Ice::ProcessPtr* p = static_cast< ::Ice::ProcessPtr*>(__addr);
    assert(p);
    *p = ::Ice::ProcessPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Ice::Process::ice_staticId();
        throw e;
    }
}

bool
Ice::operator==(const ::Ice::Process& l, const ::Ice::Process& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator!=(const ::Ice::Process& l, const ::Ice::Process& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<(const ::Ice::Process& l, const ::Ice::Process& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Ice::operator<=(const ::Ice::Process& l, const ::Ice::Process& r)
{
    return l < r || l == r;
}

bool
Ice::operator>(const ::Ice::Process& l, const ::Ice::Process& r)
{
    return !(l < r) && !(l == r);
}

bool
Ice::operator>=(const ::Ice::Process& l, const ::Ice::Process& r)
{
    return !(l < r);
}
