//example of array as a parameter
public class ExampleArrayParam {
    public static void main(String []args) {
        int[] nArray = new int[5];
        func1(nArray);
        for (int i=0; i<5; i++) {
            System.out.println("nArray[" + i + "] =" + nArray[i] );
        }
    }
    private static void func0(int[] narray) {
        func1(narray);
    }

    private static void func1(int[] narray) {
        narray[0] = 20;
        narray[1] = 11;
        narray[2] = 12;
        narray[3] = 13;
        narray[4] = 14;
    }
}
