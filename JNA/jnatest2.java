//Code for calling our library routines
//Save this code in a file jnatest2.java
// This exaple is for linux platform only
// Save the code in a file named jnatest.java
// Keep the jna.jar in the same directory
// Then compile it as
// $javac -cp .:jna.jat MyStruct.java
// $javac -cp .:jna.jar jnatest2.java
//
// Then run it as below:
// $java -cp .:jna.jar jnatest2

import com.sun.jna.Library;
import com.sun.jna.Callback;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.PointerByReference;

interface CallBackFnName extends Callback {
  void callbackImp(MyStruct mys);
}

interface DLibrary extends Library {
  int fun_alloc(PointerByReference p);
  int fun_alloc2(MyStruct mys);
  void set_callback(CallBackFnName fn);
}

public class jnatest2 {

  //private static DLibrary dLib = (DLibrary) Native.loadLibrary("test", DLibrary.class);

  private static CallBackFnName fn = new CallBackFnName() {
    @Override
    public void callbackImp(MyStruct mys) {
      System.out.println("Java got from  native " + mys.a + " " + mys.b);
    }
  };

  public static void main(String[] args) {
    try {
        DLibrary dLib = (DLibrary) Native.loadLibrary("test", DLibrary.class);

        int x;
        PointerByReference pref = new PointerByReference();
        x = dLib.fun_alloc(pref);
        Pointer ptr = pref.getValue();
        MyStruct mys = new MyStruct(ptr);
        System.out.println("Java got from  native " + Pointer.nativeValue(ptr) + "  " + mys.a + " " + mys.b);

        MyStruct mys2 = new MyStruct();
        dLib.fun_alloc2(mys2);
        System.out.println("Java got from  native " + mys2.a + " " + mys2.b);

        dLib.set_callback(fn);

    } catch (UnsatisfiedLinkError e) {
        System.out.println("Exception" + e);
    }
  }
}
