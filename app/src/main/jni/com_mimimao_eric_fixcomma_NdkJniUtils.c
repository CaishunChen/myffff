#ifndef _WIN32

#include "com_mimimao_eric_fixcomma_NdkJniUtils.h"

#include "fixcom_bridge.h"

/*
 * Class:     io_github_yanbober_ndkapplication_NdkJniUtils
 * Method:    getCLanguageString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_mimimao_eric_fixcomma_NdkJniUtils_getCLanguageString
  (JNIEnv *env, jobject obj)
  {
	 int lnRet = 0;
	 
	 lnRet = test();
	 
	 if(lnRet>0)
	 {
		return (*env)->NewStringUTF(env,"Succeed"); 
	 }else
	 {
		 return (*env)->NewStringUTF(env,"Failed");
	 }
     
  }

#endif
