// ExampleStringBuilder.java
public class ExampleStringBuilder {
    public static void main(String []args) {
    	// example of insert a sub string 
    	String str = "whatever.mp4";
        StringBuilder sb = new StringBuilder(str);
        String mp4 = ".mp4";
        int pos = sb.lastIndexOf(mp4);
        System.out.println("pos = " + pos);

        sb.insert(pos, 3);
        System.out.println("final string = " + sb);
    }
}
