// 0.170s in UVa Online Judge!
// I have a better version in Python 3 which runs in 0.010s
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
 
public class UVa787 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> nums = new ArrayList<Integer>();
	BigInteger DUMMY = BigInteger.valueOf(-100000);
        while(sc.hasNext()) {
            int cur = sc.nextInt();
            if(cur == -999999) {
                BigInteger max = BigInteger.valueOf(cur);
                BigInteger p = DUMMY, n = DUMMY, t = DUMMY;
		// ArrayList<BigInteger> data = new ArrayList<BigInteger>(nums.size());

		for( int a : nums ){
		    BigInteger tmpA = BigInteger.valueOf(a);
		    if( a == 0 ){
			if( max.compareTo(tmpA) == -1 ) max = tmpA;
			p = DUMMY;
			n = DUMMY;
			continue;
		    }
		    else if( a < 0 ){
			t = n;
			if( p.compareTo(DUMMY) == 0 ) n = tmpA;
			else n = p.multiply(tmpA);
			if( t.compareTo(DUMMY) == 0 ) p = DUMMY;
			else p = t.multiply(tmpA);
		    }
		    else{
			if( n.compareTo(DUMMY) != 0 ) n = n.multiply(tmpA);
			if( p.compareTo(DUMMY) == 0 ) p = tmpA;
			else p = p.multiply(tmpA);
		    }
		    if( max.compareTo(n) == -1 ) max = n;
		    if( max.compareTo(p) == -1 ) max = p;
		}
                // for(int i = 0; i < nums.size(); i++) {
                //     prod = BigInteger.valueOf(1);
                //     for(int j = i; j < nums.size(); j++) {
                //         prod = prod.multiply(BigInteger.valueOf(nums.get(j)));
                //         if(prod.compareTo(max) == 1)
                //             max = prod;
                //     }
                // }
                System.out.println(max.toString());
                nums.clear();
                continue;
            }
            nums.add(cur);
        }
    }
}
