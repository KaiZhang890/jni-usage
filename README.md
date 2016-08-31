# jni-usage
JSN c++ callback string array object  
```
javah com.calle.TestNative

// jni.h jni_md.h
g++ "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include" "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include/darwin" -c source.cpp

g++ -dynamiclib -o libhelloworld.jnilib source.o

javac com/calle/TestNative.java

java com/calle/TestNative
