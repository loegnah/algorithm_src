import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {

  static int n, m, SRC, SNK;
  
  static int[][] nei, f, c;
  static int[] nn, qu, fr, path;
  static boolean[] vis;
  static int front, rear, np, tot_flow;
  
  static boolean has_aug() {
    front = rear = 0;
    vis = new boolean[n+2];
    fr = new int[n+2];
    qu = new int[n+2];
    path = new int[n+2];
    fr[SRC] = -1; 
    vis[SRC] = true;
    qu[rear++] = SRC;
    
    for(;front<rear;front++) {
      int x = qu[front];
      for(int j = 0; j < nn[x]; j++) {
        int y = nei[x][j];
        if(!vis[y] && f[x][y] < c[x][y]) {
          vis[y] = true;
          fr[y] = x;
          qu[rear++] = y;
        }
      }
    }
    
    if(!vis[SNK]) return false;
    
    np = 0;
    int x = SNK, aug_val = 1048576;
    while(true) {
      path[np++] = x;
      int y = fr[x];
      if(y == -1) break;
      aug_val = Math.min(aug_val, c[y][x] - f[y][x]);
      x = y;
    }

    tot_flow += aug_val;
    
    for(int i = 1; i < np; i++) {
      int y = path[i-1];
      x = path[i];
      f[x][y] += aug_val;
      f[y][x] -= aug_val;
    }
    
    return true;
  }
  
  static int comp(int[] a, int[] b) {
    return a[0] - b[0];
  }

  static void init(int[] val, int[][] to) {
    Arrays.sort(to, (a, b) -> comp(a, b));
    
    f = new int[n+2][n+2];
    c = new int[n+2][n+2];
    nei = new int[n+2][n+2];
    for(int i = 0; i < m; i++) {
      c[to[i][0]][to[i][1]] = to[i][2];
    }
    nn = new int[n+2];
    for(int i = 0; i < n+2; i++)
      for(int j = 0; j < n+2; j++)
        if(c[i][j] > 0 || c[j][i] > 0) {
          nei[i][nn[i]++] = j;
        }
  }
  
  static int solve(int[] val, int[][] to) {
    n = val.length; 
    m = to.length;
    SRC = n; SNK = n+1;
    init(val, to);
    
    int tot_pos = 0;
    for(int i = 0; i < n; i++) {
      if(val[i] > 0) tot_pos += val[i];
    }

    tot_flow = 0;
    while(has_aug());
    
    return tot_pos - tot_flow;    
  }
  
  public static void main(String[] args) throws IOException {
    OutputStreamWriter ow = new OutputStreamWriter(System.out);
    BufferedWriter writer = new BufferedWriter(ow);
    
		FastScanner in = new FastScanner();
		int t = in.nextInt();

    // -----------------------------------------------------
    while (t > 0) { t--;
      n = in.nextInt();
      m = in.nextInt();
      int[] val = new int[n];
      
      for(int i = 0; i < n ;i++) {
        val[i] = in.nextInt();
      }

      int[][] to = new int[m + n][3];
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < 3; j++)
          to[i][j] = in.nextInt();
        to[i][0]--;
        to[i][1]--;
      }

      final int SRC = n, SNK = n+1;
      for(int i = 0; i < n; i++) {
        if(val[i] > 0) {
          to[m+i][0] = SRC;
          to[m+i][1] = i;
          to[m+i][2] = val[i];
        } else {
          to[m+i][0] = i;
          to[m+i][1] = SNK;
          to[m+i][2] = -val[i];
        }
      }
      writer.write(String.format("%d\n", solve(val, to)));
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

