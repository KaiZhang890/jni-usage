import com.sun.jna.Structure;
import com.sun.jna.Pointer;

public class MyStruct extends Structure implements Structure.ByReference {
    public int a;
    public int b;

    public MyStruct() {
    }

    public MyStruct(Pointer p) {
        super(p);
        read();
    }
}
