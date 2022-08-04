import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
  static final long MOD = 1000000000 + 7;
  

  static long pow_mod(long x, long e) {
    if(e == 0) return 1L;
    if(e == 1) return x;
    long x2 = pow_mod(x, e/2);
    x2 = (x2 * x2) % MOD;
    if(e % 2 == 1) {
      x2 = (x2 * x) % MOD;
    }
    return x2;
  }

  static long binom_mod(long nn, long kk) {
    if(kk < 0 || kk > nn || nn < 0) return 0;
    if(nn == kk || kk == 0) return 1;

    long ans = 1;
    for(long num = nn; num >= nn-kk+1; num--) {
      ans = (ans * num)%MOD;
    }
    for(long num = 1; num <= kk; num++) {
      ans = (ans * pow_mod(num, MOD-2)) % MOD;
    }
    return ans;
  }  

  static long solve(int n, int k, String arr) {
    int cnt = 0;
    int[] ind = new int[n+1];
    for(int i = 0; i < n; i++) {
      if(arr.charAt(i) == '1') {
        cnt++;
        ind[cnt] = i;
      }
    }
    if(cnt % k != 0) return 0L;
    if(cnt == 0) return binom_mod(n-1, k-1);
    
    int unit = cnt / k;
    long ans = 1;
    for(int i = 1; i < k; i++) {
      int i1 = ind[unit*i];
      int i2 = ind[unit*i + 1];
      long v = (i2 - i1);
      ans = ans * v;
      ans %= MOD;
    }
    
    return ans;
  }
  
  public static void main(String[] args) throws IOException {
    OutputStreamWriter ow = new OutputStreamWriter(System.out);
    BufferedWriter writer = new BufferedWriter(ow);
    
		FastScanner in = new FastScanner();
		int t = in.nextInt();

    // -----------------------------------------------------
    while (t > 0) { t--;
      int n, k;
      n = in.nextInt();
      k = in.nextInt();
      String arr = in.next();
      long ans = solve(n, k, arr);
      writer.write(String.format("%d\n", ans));
      writer.flush();
    }
  }
// --------------------------------------
  static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    FastScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextLine() {
      try {
        return br.readLine();
      } catch (IOException e) {
        return "";
      }
    }

    String next() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }
  }
}
