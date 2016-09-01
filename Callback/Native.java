public class Native {
  public native void nativeInitialize();
  public native void nativeThreadStart();
  public native void nativeThreadStop();

  public void onNativeCallback(int count) {
    System.out.println("count=" + count);
  }

  static {
    System.loadLibrary("native");
  }

  public static void main(String[] args) {
    Native n1 = new Native();
    n1.nativeInitialize();
    n1.nativeThreadStart();

    Thread t1 = new Thread(new Runnable() {
      public void run() {
        try {
            Thread.sleep(5000);
            n1.nativeThreadStop();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
      }
    });
    t1.start();

    synchronized(t1){
      try {
        t1.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
