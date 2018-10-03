import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;

class Asumab {
    public static void main( String[] args ){
	Scanner sc = new Scanner( System.in );
	int n = sc.nextInt();
	for( int i = 0; i < n; ++ i ){
	    String line = sc.nextLine();
	    String left = line.substring( 0, line.length() - 1);
	    String right = line.substring( line.length() - 1 );
	    char arr[] = left.toCharArray();
	    Arrays.sort( arr );
	    BigInteger p = new BigInteger( new String( arr ) );
	    BigInteger last = new BigInteger( right );
	    p = p.add( last );
	    System.out.println( p );
	}	
    }
}
