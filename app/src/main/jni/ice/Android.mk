
#
# Compile with support for the Ice router facility.
#
HAS_ROUTER				:= yes

#
# Compile with support for the Ice locator facility.
#
HAS_LOCATOR				:= no

#
# Compile with support for batch invocations.
#
HAS_BATCH				:= no

#
# Compile with support for wstring and string conversion.
#
HAS_WSTRING				:= no

#
# Compile with support for opaque endpoints.
#
HAS_OPAQUE_ENDPOINTS	:= no

#
# Compile with support for asynchronous method invocation (AMI).
#
HAS_AMI					:= no

#
# Default Mutex protocol: one of PrioNone or PrioInherit.
#
# DEFAULT_MUTEX_PROTOCOL	:= PrioNone 
LOCAL_PATH := $(call my-dir)



include $(CLEAR_VARS)

GLOBAL_C_INCLUDES := $(LOCAL_PATH)/include $(LOCAL_PATH)/include/Ice $(LOCAL_PATH)/include/IceUtil $(LOCAL_PATH)/src $(LOCAL_PATH)/../bzip2


ICE_DIR			:= src/Ice

ICE_UTIL_DIR    := src/IceUtil

ICE_UTIL_SRCS   :=\
				$(ICE_UTIL_DIR)/ArgVector.cpp\
				$(ICE_UTIL_DIR)/Base64.cpp\
				$(ICE_UTIL_DIR)/Cond.cpp\
				$(ICE_UTIL_DIR)/ConvertUTF.cpp\
				$(ICE_UTIL_DIR)/CountDownLatch.cpp\
				$(ICE_UTIL_DIR)/Exception.cpp\
				$(ICE_UTIL_DIR)/InputUtil.cpp\
				$(ICE_UTIL_DIR)/MD5.cpp\
				$(ICE_UTIL_DIR)/MD5I.cpp\
				$(ICE_UTIL_DIR)/Options.cpp\
				$(ICE_UTIL_DIR)/OutputUtil.cpp\
				$(ICE_UTIL_DIR)/Random.cpp\
				$(ICE_UTIL_DIR)/RecMutex.cpp\
				$(ICE_UTIL_DIR)/RWRecMutex.cpp\
				$(ICE_UTIL_DIR)/Shared.cpp\
				$(ICE_UTIL_DIR)/StaticMutex.cpp\
				$(ICE_UTIL_DIR)/StringUtil.cpp\
				$(ICE_UTIL_DIR)/Thread.cpp\
				$(ICE_UTIL_DIR)/ThreadException.cpp\
				$(ICE_UTIL_DIR)/Time.cpp\
				$(ICE_UTIL_DIR)/Unicode.cpp\
				$(ICE_UTIL_DIR)/UUID.cpp\
				

ICE_SRCS		:= \
				$(ICE_DIR)/Acceptor.cpp\
				$(ICE_DIR)/Application.cpp\
				$(ICE_DIR)/BasicStream.cpp\
				$(ICE_DIR)/Buffer.cpp\
				$(ICE_DIR)/CommunicatorI.cpp\
				$(ICE_DIR)/ConnectionFactory.cpp\
				$(ICE_DIR)/ConnectionI.cpp\
				$(ICE_DIR)/ConnectionMonitor.cpp\
				$(ICE_DIR)/Connector.cpp\
				$(ICE_DIR)/DefaultsAndOverrides.cpp\
				$(ICE_DIR)/Direct.cpp\
				$(ICE_DIR)/DynamicLibrary.cpp\
				$(ICE_DIR)/EndpointFactory.cpp\
				$(ICE_DIR)/EndpointFactoryManager.cpp\
				$(ICE_DIR)/EndpointI.cpp\
				$(ICE_DIR)/EventHandler.cpp\
				$(ICE_DIR)/Exception.cpp\
				$(ICE_DIR)/FactoryTable.cpp\
				$(ICE_DIR)/FactoryTableDef.cpp\
				$(ICE_DIR)/GC.cpp\
				$(ICE_DIR)/IdentityUtil.cpp\
				$(ICE_DIR)/ImplicitContextI.cpp\
				$(ICE_DIR)/Incoming.cpp\
				$(ICE_DIR)/IncomingAsync.cpp\
				$(ICE_DIR)/Initialize.cpp\
				$(ICE_DIR)/Instance.cpp\
				$(ICE_DIR)/LocalObject.cpp\
				$(ICE_DIR)/LocatorInfo.cpp\
				$(ICE_DIR)/LoggerI.cpp\
				$(ICE_DIR)/LoggerUtil.cpp\
				$(ICE_DIR)/Network.cpp\
				$(ICE_DIR)/Object.cpp\
				$(ICE_DIR)/ObjectAdapterFactory.cpp\
				$(ICE_DIR)/ObjectAdapterI.cpp\
				$(ICE_DIR)/ObjectFactoryManager.cpp\
				$(ICE_DIR)/Outgoing.cpp\
				$(ICE_DIR)/OutgoingAsync.cpp\
				$(ICE_DIR)/PluginManagerI.cpp\
				$(ICE_DIR)/PropertiesI.cpp\
				$(ICE_DIR)/PropertyNames.cpp\
				$(ICE_DIR)/Protocol.cpp\
				$(ICE_DIR)/ProtocolPluginFacade.cpp\
				$(ICE_DIR)/Proxy.cpp\
				$(ICE_DIR)/ProxyFactory.cpp\
				$(ICE_DIR)/Reference.cpp\
				$(ICE_DIR)/ReferenceFactory.cpp\
				$(ICE_DIR)/RouterInfo.cpp\
				$(ICE_DIR)/ServantManager.cpp\
				$(ICE_DIR)/Service.cpp\
				$(ICE_DIR)/SliceChecksums.cpp\
				$(ICE_DIR)/Stream.cpp\
				$(ICE_DIR)/StreamI.cpp\
				$(ICE_DIR)/StringConverter.cpp\
				$(ICE_DIR)/SysLoggerI.cpp\
				$(ICE_DIR)/TcpAcceptor.cpp\
				$(ICE_DIR)/TcpConnector.cpp\
				$(ICE_DIR)/TcpEndpointI.cpp\
				$(ICE_DIR)/TcpTransceiver.cpp\
				$(ICE_DIR)/ThreadPool.cpp\
				$(ICE_DIR)/TraceLevels.cpp\
				$(ICE_DIR)/TraceUtil.cpp\
				$(ICE_DIR)/Transceiver.cpp\
				$(ICE_DIR)/UdpEndpointI.cpp\
				$(ICE_DIR)/UdpTransceiver.cpp\
				$(ICE_DIR)/ifaddrs.c\
				$(ICE_DIR)/UnknownEndpointI.cpp


				
LOCAL_SRC_FILES := $(ICE_UTIL_SRCS) $(ICE_SRCS)

LOCAL_MODULE := Ice

GLOBAL_CFLAGS  := -DICE_API_EXPORTS -D_REENTRANT -DNDEBUG  -ICE_UTIL_API_EXPORTS\
		-DPAGE_SIZE=0x400 -ftemplate-depth-128 -Wall -O2 \
		 -D_REENTRANT -Wunused-but-set-variable\
		-fdata-sections -ffunction-sections -isystem $(SYSROOT)/usr/include/
		
		
LOCAL_SHARED_LIBRARIES := gnustl_shared  bz2 ssl expat Ice		
		

LOCAL_CFLAGS := $(GLOBAL_CFLAGS)
LOCAL_C_INCLUDES := $(GLOBAL_C_INCLUDES)

include $(BUILD_SHARED_LIBRARY)
