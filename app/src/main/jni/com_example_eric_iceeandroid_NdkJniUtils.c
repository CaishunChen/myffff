#include "com_example_eric_iceeandroid_NdkJniUtils.h"
/*
 * Class:     io_github_yanbober_ndkapplication_NdkJniUtils
 * Method:    getCLanguageString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_eric_iceeandroid_NdkJniUtils_getCLanguageString
  (JNIEnv *env, jobject obj)
  {
     return (*env)->NewStringUTF(env,"This just a test for Android Studio NDK JNI developer!");
  }