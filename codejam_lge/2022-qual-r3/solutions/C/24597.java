import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
  static int r, c, n;
  static int[] pref;
  static int[][][] sum, dp;
  static final int MOD = 1000000000 + 7;
  static final int S = 0, R = 1, B = 2;
  
  static boolean satisfied(int p, int x1, int y1, int x2, int y2) {
    int t = pref[p];
    int cnt = sum[t][x2][y2] + sum[t][x1-1][y1-1] - sum[t][x1-1][y2] - sum[t][x2][y1-1];
    return cnt >= 1;
  }
  
  static int doit(int x, int y, int k) {
    if(x > r || y > c) return 0;
    int ret = dp[x][y][k];
    if(ret != -1) return ret;

    if(k == n-1) {
      ret = satisfied(k, x, y, r, c) ? 1 : 0;
      return dp[x][y][k] = ret;
    }
    
    ret = 0;
    for(int i = x; i < r; i++) {
      if(!satisfied(k, x, y, i, c)) continue;
      ret += doit(i+1, y, k+1);
      ret %= MOD;
    }
    
    for(int j = y; j < c; j++) {
      if(!satisfied(k, x, y, r, j)) continue;
      ret += doit(x, j+1, k+1);
      ret %= MOD;
    }
    
    return dp[x][y][k] = ret;
  }

  static int solve() {
    for(int k = 0; k < 3; k++) {
      for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
          sum[k][i][j] += sum[k][i-1][j];
          sum[k][i][j] += sum[k][i][j-1];
          sum[k][i][j] -= sum[k][i-1][j-1];
        }
      }
    }
    dp = new int[r+1][c+1][n];
    for(int i = 1; i <= r; i++) 
      for(int j = 1; j <= c; j++) 
        for(int k = 0; k < n; k++)
          dp[i][j][k] = -1;
    
    return doit(1, 1, 0);
  }
  
  public static void main(String[] args) throws IOException {
    OutputStreamWriter ow = new OutputStreamWriter(System.out);
    BufferedWriter writer = new BufferedWriter(ow);
    
		FastScanner in = new FastScanner();
		int t = in.nextInt();

    // -----------------------------------------------------
    while (t > 0) { t--;
      r = in.nextInt();
      c = in.nextInt();
      n = in.nextInt();
      
      sum = new int[3][r+1][c+1];
      
      String buff;
      for(int i = 1; i <= r; i++) {
        buff = in.nextLine();
        for(int j = 1; j <= c; j++) {
          int cell = -1;
          if(buff.charAt(j-1) == 'S') cell = S;
          else if(buff.charAt(j-1) == 'R') cell = R;
          else if(buff.charAt(j-1) == 'B') cell = B;
          if(cell != -1) {
            sum[cell][i][j] = 1;
          }
        }
      }
      
      pref = new int[n];
      buff = in.nextLine();
      for(int i = 0; i < n; i++) {
        if(buff.charAt(i) == 'S') pref[i] = S;
        else if(buff.charAt(i) == 'R') pref[i] = R;
        else if(buff.charAt(i) == 'B') pref[i] = B;
      } 

      int ans = solve();
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
  }
}
