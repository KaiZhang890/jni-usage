#include "Native.h"
#include "unistd.h"

static void* native_thread_exec(void *arg) {
  JNIEnv *env;
  gJavaVM->AttachCurrentThread((void **)&env, NULL);

  jclass javaClass = env->GetObjectClass(gJavaObj);
  if (javaClass == NULL) {
    printf("Fail to find javaClass\n");
    return 0;
  }

  jmethodID callback = env->GetMethodID(javaClass, "onNativeCallback", "(I)V");
  if (callback == NULL) {
    printf("Fail to find method\n");
    return 0;
  }

  printf("native_thread_exec loop enter\n");
  int count = 0;
  while (!gIsThreadExit) {
    env->CallVoidMethod(gJavaObj, callback, count++);
    sleep(1);
  }

  gJavaVM->DetachCurrentThread();
  printf("native_thread_exec loop leave\n");
}

/*
 * Class:     Native
 * Method:    nativeInitialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Native_nativeInitialize(JNIEnv *env, jobject obj) {
  env->GetJavaVM(&gJavaVM);
  gJavaObj = env->NewGlobalRef(obj);
}

/*
 * Class:     Native
 * Method:    nativeThreadStart
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Native_nativeThreadStart(JNIEnv *env, jobject obj) {
  gIsThreadExit = 0;

  pthread_t threadId;
  if(pthread_create(&threadId, NULL, native_thread_exec, NULL) != 0) {
    printf("pthread_create fail !\n");
    return;
  }

  printf("pthread_create success\n");
}

/*
 * Class:     Native
 * Method:    nativeThreadStop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Native_nativeThreadStop(JNIEnv *env, jobject obj) {
  gIsThreadExit = 1;
  printf("Java_Native_nativeThreadStop success\n");
}
