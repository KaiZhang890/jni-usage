#include "com_calle_TestNative.h"
#include <iostream>

using namespace std;

JNIEXPORT void JNICALL Java_com_calle_TestNative_sayHello(JNIEnv *, jobject) {
  cout<<"Oh JNI, how silly you are!"<<endl;
  return;
}
