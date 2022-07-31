import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
  static long[] H, W;
  static PriorityQueue<Integer> qu;

  static long solve(int n, long z) {
    long maxi = -1;
    qu = new PriorityQueue<Integer>(n, (a, b) -> Long.compare(W[b], W[a]));

    for(int i = 0; i < n; i++) {
      while(!qu.isEmpty() && H[i] - H[qu.peek()] > z) qu.poll();
      
      if(!qu.isEmpty()) {
        maxi = Math.max(maxi, W[i] + W[qu.peek()]);
      }
      qu.add(i);
    }    
    return maxi;
  }
  
  public static void main(String[] args) throws IOException {
    OutputStreamWriter ow = new OutputStreamWriter(System.out);
    BufferedWriter writer = new BufferedWriter(ow);
    
		FastScanner in = new FastScanner();
		int t = in.nextInt();

    // -----------------------------------------------------
    while (t > 0) { t--;
      int n = in.nextInt();
      int z = in.nextInt();

      long hs = (long) in.nextInt();
      long ha = (long) in.nextInt();
      long hb = (long) in.nextInt();
      long hc = (long) in.nextInt();
      
      long ws = (long) in.nextInt();
      long wa = (long) in.nextInt();
      long wb = (long) in.nextInt();
      long wc = (long) in.nextInt();

      // stdin에서 입력을 받는다.
      H = new long[n];
      W = new long[n];

      H[0] = hs % hc + 1;
      W[0] = ws % wc + 1;
      for(int i = 1; i <= n-1; i++) {
        H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc;
        W[i] = (W[i-1] * wa + wb) % wc + 1;
      }

      for(int i = 0; i < n; i++) {
        W[i] *= H[i];
      }
      
      long ans = solve(n, z);
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
