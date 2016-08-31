package com.calle;

public class TestNative {
  public native void sayHello();

  static {
    System.loadLibrary("HelloWorld");
  }

  public static void main(String[] args) {
    new TestNative().sayHello();
  }
}
