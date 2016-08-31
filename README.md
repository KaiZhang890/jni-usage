# jni-usage
Max OS X: JSN c++ callback string array object  
```
javah com.calle.TestNative

// jni.h jni_md.h
g++ "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include" "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include/darwin" -c source.cpp

g++ -dynamiclib -o libhelloworld.jnilib source.o

/System/Library/Frameworks/JavaVM.framework/JavaVM

g++ "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include" "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include/darwin" "-L/System/Library/Frameworks/JavaVM.framework/JavaVM" -c Sample2.cpp
javac com/calle/TestNative.java

java com/calle/TestNative
```

http://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html

http://www.codeproject.com/Articles/993067/Calling-Java-from-Cplusplus-with-JNI
