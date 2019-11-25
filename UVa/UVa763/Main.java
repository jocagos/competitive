import java.util.Scanner;
import java.math.BigInteger;
import java.lang.StringBuffer;

public class Main{
    private static int lowerBound( BigInteger[] list, int low, int high, BigInteger val ){
	while( low < high ){
	    int mid = low + (high - low)/2;
	    int cmp = val.compareTo( list[mid] );
	    if( cmp == 1 )
		low = mid + 1;
	    else
		high = mid;
	}
	return low;
    }
    
    private static BigInteger to_bi( String s, BigInteger[] fibos ){
	BigInteger ans = BigInteger.ZERO;
	for( int i = s.length() - 1; i >= 0; i -- ){
	    if( s.charAt(i) == '1' ){
		// System.err.println("Char at " + i + " is 1 so we add " + fibos[s.length() - i]);
		ans = ans.add(fibos[s.length() - i]);
	    }
	}
	// System.err.println("String " + s + " yielded BigInteger " + ans);
	return ans;
    }

    private static String to_fib( BigInteger bi, BigInteger[] fibos ){
	StringBuffer sb = new StringBuffer();
	int max_idx;
	int idx = lowerBound( fibos, 0, 110, bi ); // check this part
	max_idx = idx;
	System.err.println("Fibos[" + idx + "] = " + fibos[idx]);
	System.err.println("BI = " + bi);
	bi = bi.add(fibos[idx].negate());
	System.err.println("AFTER SUBS BI = " + bi);
	sb.append('1');
	while( bi != BigInteger.ZERO ){
	    if( idx < 0 ){
		System.err.println("Bi ended up as " + bi );
	    }
	    int cmp = fibos[idx].compareTo( bi );
	    if( cmp == 1 ){
		idx --;
		sb.append('0');
	    }
	    else{
		bi = bi.add(fibos[idx].negate());
		sb.append('1');
	    }
	}
	
	return sb.toString();
    }
    
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int first = 0;
	// Fibonacci
	BigInteger[] fibo = new BigInteger[110];
	fibo[0] = BigInteger.ONE;
	fibo[1] = fibo[0];
	fibo[1].add( fibo[0] );
	for( int i = 2; i < 110; ++ i ){
	    fibo[i] = fibo[i - 1].add( fibo[i - 2] );
	}
	while( sc.hasNext() ){
	    if( first == 0 ) first = 1;
	    else System.out.println();
	    String lhs = sc.next();
	    String rhs = sc.next();

	    // Get value of both numbers
	    System.err.println("LHS is " + lhs + "\nRHS is " + rhs);
	    System.err.println("to_bi(" + lhs + ") = " + to_bi( lhs, fibo ) );
	    System.err.println("to_bi(" + rhs + ") = " + to_bi( rhs, fibo ) );
	    BigInteger ans = to_bi( lhs, fibo );
	    ans.add( to_bi( rhs, fibo ) );
	    System.out.println( to_fib( ans, fibo ) );
	}
    }
}
