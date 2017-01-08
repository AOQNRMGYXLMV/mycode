import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static BigInteger one = BigInteger.valueOf(1);
	public static BigInteger two = BigInteger.valueOf(2);
	public static BigInteger four = BigInteger.valueOf(4);
	public static BigInteger six = BigInteger.valueOf(6);
	public static HashMap<BigInteger, BigInteger> map = new HashMap<BigInteger, BigInteger>();

	public static BigInteger F(BigInteger n) {
		if(map.containsKey(n)) return map.get(n);
		BigInteger k = n.divide(two);
		BigInteger odd = n.mod(two);
		BigInteger ans;
		if(odd.compareTo(one) == 0) {
			ans = F(k).multiply(four).add(k.multiply(six));
		} else {
			ans = F(k).multiply(two);
			ans = ans.add(F(k.subtract(one)).multiply(two));
			ans = ans.add(k.multiply(four)).subtract(four);
		}
		map.put(n, ans);
		return ans;
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		map.put(BigInteger.ZERO, BigInteger.ZERO);
		map.put(BigInteger.ONE, BigInteger.ZERO);
		while(cin.hasNext()) {
			BigInteger n = cin.nextBigInteger();
			System.out.println(F(n));
		}
		cin.close();
	}
}
