all: jnatest2.class libtest.dylib
	java -cp .:jna.jar jnatest2

jnatest2.class: MyStruct.class
	javac -cp .:jna.jar jnatest2.java

MyStruct.class:
	javac -cp .:jna.jar MyStruct.java

libtest.dylib: test.o
	gcc -shared -fPIC -o libtest.dylib test.o

test.o:
	gcc -c test.c -fPIC

clean:
	rm -f *.class *.o *.dylib
