import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	final static BigInteger mod = BigInteger.valueOf(258280327);
	public static void main(String [] args){
		BigInteger f[] = new BigInteger [1010];
		f[1] = f[2] = BigInteger.ONE; f[0] = BigInteger.ZERO;
		Scanner cin = new Scanner(System.in);
		for(int i = 3; i < 1001; i ++)
			f[i] = f[i-1].add(f[i-2]);
		while(cin.hasNext()) {
		int cas = cin.nextInt();
		for(int j = 0; j < cas;j ++){
			int n = cin.nextInt();
			BigInteger m = cin.nextBigInteger();

			if(m.compareTo(BigInteger.valueOf(3)) < 0) {
				System.out.println(0);
				continue;
			}

			if(m.compareTo(BigInteger.valueOf(3)) == 0) {
				System.out.println(1);
				continue;
			}

			m.add(BigInteger.ONE);
			for(int i = 4; i < 1001; i ++)
				if(m.compareTo(f[i]) < 0) {
					System.out.println(m.subtract(f[i-2]).mod(mod));
					break;
				}
			}
		}
	}
}
