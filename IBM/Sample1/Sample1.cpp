#include "Sample1.h"
#include <string.h>

static JNIEnv *jniEnv;
// 回调函数
void TestCallback() {
    jclass cls = jniEnv->FindClass("Sample1");
    if (cls != 0) {
      jmethodID mid = jniEnv->GetStaticMethodID(cls, "saySomething", "()V");
      if (mid != 0) {
        jniEnv->CallStaticVoidMethod(cls, mid);
        printf("Call saySomething");
      }
    }
}

JNIEXPORT jint JNICALL Java_Sample1_intMethod(JNIEnv *env, jobject obj, jint num) {
  printf("Address of env is %p\n", env);
  jniEnv = env;
  return num * num;
}

JNIEXPORT jboolean JNICALL Java_Sample1_booleanMethod(JNIEnv *env, jobject obj, jboolean boolean) {
  printf("Address of jniEnv is %p\n", jniEnv);
  return !boolean;
}

JNIEXPORT jstring JNICALL Java_Sample1_stringMethod(JNIEnv *env, jobject obj, jstring string) {
  printf("Address of jniEnv is %p\n", jniEnv);
  const char *str = env->GetStringUTFChars(string, 0);
  char cap[128];
  strcpy(cap, str);
  strcat(cap, " from cpp");
  env->ReleaseStringUTFChars(string, str);
  return env->NewStringUTF(cap);
}

JNIEXPORT jint JNICALL Java_Sample1_intArrayMethod(JNIEnv *env, jobject obj, jintArray array) {
  printf("Address of jniEnv is %p\n", jniEnv);
  int i, sum = 0;
  jsize len = env->GetArrayLength(array);
  jint *body = env->GetIntArrayElements(array, 0);
  for (i = 0; i < len; i++) {
    sum += body[i];
  }
  env->ReleaseIntArrayElements(array, body, 0);
  TestCallback();
  return sum;
}
