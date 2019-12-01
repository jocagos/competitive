import java.util.Scanner;
import java.math.BigInteger;

class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	while (sc.hasNext()) {
	    String s = sc.next();
	    int f = sc.nextInt();
	    int t = sc.nextInt();
	    s = new BigInteger(s, f).toString(t).toUpperCase();
	    if( s.length() > 7 ){
		s = "ERROR";
	    }
	    System.out.printf("%7s\n", s);
	}
    }
}
