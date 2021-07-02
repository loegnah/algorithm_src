import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
  static final long M = 24L * 60L * 60L;

  static long gcd(long x, long y) {
    while(y > 0) {
      long z = x % y;
      x = y;
      y = z;
    }
    return x;
  }
  
  static long exp(long x, long e, long m) {
    if(e == 0) return 1L;
    if(e == 1) return x;
    long ans = exp(x, e/2L, m);
    ans = (ans * ans) % m;
    if(e % 2 == 1) ans = (ans * x) % m;
    return ans;
  }
  
  static long inv(long aa, long mm) {
    long phi = 1L, m_org = mm;
    for(long dv = 2; dv <= 5; dv++) {
      int cp = 0;
      while(m_org > 1 && m_org % dv == 0) {
        m_org /= dv;
        cp++;
      }
      if(cp > 0) {
        for(int k = 0; k < cp; k++) phi *= dv;
        phi *= dv - 1;
      }
    }
    return exp(aa, phi-1, mm);
  }
  
  static int solve(long[] dat, long[] tim) {
    int n = dat.length;
    int[] val = new int[(int) M+1], nv = new int[(int) M+1], cnt = new int[(int) M+1];
    for(int i = 0; i <= M; i++) {
      val[i] = -1;
      nv[i] = 0;
      cnt[i] = 0;
    }
    for(int i = 1; i < n; i++) {
      long a = ((dat[i] - dat[0]) + M ) % M;
      long  b = ((tim[0] - tim[i]) + M ) % M;
      long g = gcd(a, M);
      if(b % g != 0) return 0;
      long aa = a/g, bb = b/g, mm = M/g;
      long x = (bb * inv(aa, mm)) % mm;
      if(val[(int) mm] != -1 && val[(int) mm] != x) return 0;
      val[(int) mm] = (int) x;
      nv[(int) mm]++;
    }
    int ans = 0;
    for(int mm = 1; mm <= M; mm++) {
      if(val[mm] != -1) {
        for(int x = val[mm]; x < M; x += mm) {
          cnt[x] += nv[mm];
          if(cnt[x] == n-1) ans++;
        }
      }
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
      int n = in.nextInt();
      long[] dat = new long[n], tim = new long[n];
      for(int i = 0; i < n; i++) {
        String[] time = in.next().split(":");
        tim[i] = Long.parseLong(time[0])*3600L
          + Long.parseLong(time[1])*60L
            + Long.parseLong(time[2])*1L;
      }
      for(int i = 0; i < n; i++) {
        dat[i] = (in.nextLong() % M + M)%M;
      }

      int ans = solve(dat, tim);
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

