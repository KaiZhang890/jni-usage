all: libSample1.jnilib Sample1.class
	java Sample1

Sample1.class:
	javac Sample1.java

libSample1.jnilib: Sample1.o
	g++ -dynamiclib -o libSample1.jnilib Sample1.o

Sample1.o:
	g++ "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include" "-I/Library/Java/JavaVirtualMachines/jdk1.8.0_25.jdk/Contents/Home/include/darwin" -c Sample1.cpp

clean:
	rm -f *.class *.o *.jnilib
