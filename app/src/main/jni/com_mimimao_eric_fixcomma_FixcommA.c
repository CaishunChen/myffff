#ifndef _WIN32

#include "com_mimimao_eric_fixcomma_FixcommA.h"

#include <string.h> /* memset */
#include <unistd.h> /* close */

#include "fixcom_bridge.h"

/*
 * Class:     io_github_yanbober_ndkapplication_NdkJniUtils
 * Method:    getCLanguageString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1CreateObject
  (JNIEnv *env, jobject obj)
  {
	  ICommInterFaceC * apData = 0;
	  
	  int lnRet = CreateICommInterFaceC(&apData);
	  
	  if(lnRet>0)
	  {
		  return (int)apData;
	  }else
	  {
		  return 0;
	  }		  
	  
  }
  
  JNIEXPORT jint JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1DeleteObject
  (JNIEnv *env, jobject obj, jint anObj)
  {
	   ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	   
	   return DeleteICommInterFaceC(apData);
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1Link
  (JNIEnv *env, jobject obj, jint anObj, jstring astrIP, jint anPort)
  {
	  const char * path = null;
	  
	  path = (*env)->GetStringUTFChars( env, astrIP , NULL ) ;
	  
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	   
	  return  apData->m_pVTable->Link(apData,path,anPort);
	  
  }
  
  JNIEXPORT void JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1CreateHead
  (JNIEnv *env, jobject obj, jint anObj, jint nFunc)
  {
	   ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	   
	   apData->m_pVTable->CreateHead(apData,nFunc);
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1Close
  (JNIEnv *env, jobject obj, jint anObj)
  {
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	   
	  return  apData->m_pVTable->Close(apData);
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1More
  (JNIEnv *env, jobject obj, jint anObj)
  {
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	   
	  return  apData->m_pVTable->More(apData);
  }
  
JNIEXPORT void JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1SetTimeOut
  (JNIEnv *env, jobject obj, jint anObj, jint anSeconds)
  {
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	  
	  return  apData->m_pVTable->SetTimeOut(apData,anSeconds);
  }
  
  JNIEXPORT jdouble JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1GetDouble
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode)
  {
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	  
	  return  apData->m_pVTable->GetDouble(apData,nFixCode);
  }
  
  JNIEXPORT jfloat JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1GetFloat
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode)
  {
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	  
	  return  apData->m_pVTable->GetFloat(apData,nFixCode);
  }
  
  JNIEXPORT jlong JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1GetLong
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode)
  {
		ICommInterFaceC * apData = (ICommInterFaceC *)anObj;
	  
		return  apData->m_pVTable->GetLong(apData,nFixCode);
  }
  
  JNIEXPORT jstring JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1GetString
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode)
  {
		int lnDataSize = 0;
	   
		int lnRet = 0;
	   
		ICommInterFaceC * apData = (ICommInterFaceC *)anObj;	   
	   
		lnRet = apData->m_pVTable->GetString(apData,nFixCode,NULL,&lnDataSize);
	   
		char * lpData = (char *)malloc(lnDataSize);
	   
		memset(lpData,0,lnDataSize);
	   
		lnRet = apData->m_pVTable->GetString(apData,nFixCode,lpData,&lnDataSize);
	   
		return (*env)->NewStringUTF(env,lpData); 
	   
		free(lpData);
  }
  
JNIEXPORT jstring JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1GetItemString
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode)
  {
		int lnDataSize = 0;
	   
		int lnRet = 0;
	   
		ICommInterFaceC * apData = (ICommInterFaceC *)anObj;	   
	   
		lnRet = apData->m_pVTable->GetString(apData,nFixCode,NULL,&lnDataSize);
	   
		char * lpData = (char *)malloc(lnDataSize);
	   
		memset(lpData,0,lnDataSize);
	   
		lnRet = apData->m_pVTable->GetString(apData,nFixCode,lpData,&lnDataSize);
	   
		return (*env)->NewStringUTF(env,lpData); 
	   
		free(lpData);  
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1SetItemDouble
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode, jdouble anValue)
  {
	  bool lnRet = 0;
	  
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;	
	  
	  lnRet = apData->m_pVTable->SetItemDouble(apData,nFixCode,anValue);
	  
	  return lnRet;
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1SetItemInt
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode, jint anValue)
  {
	  bool lnRet = 0;
	  
	  ICommInterFaceC * apData = (ICommInterFaceC *)anObj;	
	  
	  lnRet = apData->m_pVTable->SetItemInt(apData,nFixCode,anValue);
	  
	  return lnRet;  
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1SetItemString
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode, jstring astrValue)
  {
		bool lnRet = 0;
	  
	    const char * path = null;
	  
		ICommInterFaceC * apData = (ICommInterFaceC *)anObj;	  
	  	
	  
		path = (*env)->GetStringUTFChars( env, astrValue , NULL ) ;

	  
		lnRet = apData->m_pVTable->SetItemString(apData,nFixCode,path);
	  
		return lnRet;  
  }
  
  JNIEXPORT jboolean JNICALL Java_com_mimimao_eric_fixcomma_FixcommA__1SetItemBuf
  (JNIEnv *env, jobject obj, jint anObj, jint nFixCode,  jbyteArray apArrayData)
  {
		bool lnRet = 0;
		
		jbyte* bufferPtr = (*env)->GetByteArrayElements(env, apArrayData, NULL);
	  
		jsize lengthOfArray = (*env)->GetArrayLength(env, apArrayData);
		
		ICommInterFaceC * apData = (ICommInterFaceC *)anObj;	  
		
		if(lengthOfArray>0)
		{
			lnRet = apData->m_pVTable->SetItemBuf(apData,nFixCode,(char *)bufferPtr,lengthOfArray);
		}
	  
		(*env)->ReleaseByteArrayElements(env, apArrayData, bufferPtr, 0);
		
		return lnRet;
  }

#endif
