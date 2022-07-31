import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {

	static int n;
  static int[][][][] dp, fr;
  static int[][] d;
//	int dp[maxn][maxn][2][2], fr[maxn][maxn][2][2];
	// 0 = a < b
	// 1 = a > b

	static boolean ok(int todo, int i, int j) {
		if(d[i][0] >= d[j][0]) return false;
		if(i == 0 && j == n) return false;
		return i == 0
		|| (todo == 0 && d[i][1] < d[j][1])
		|| (todo == 1 && d[i][1] > d[j][1]);
	}
	static int doit(int i, int j, int x, int y) {
		if(i == 0 && j == 1) return 1;
		int ret = dp[i][j][x][y];
		if(ret != -1) return ret;
		ret = 0;

		if(i+1 == j) {
			for(int k = 0; k < i; k++) {
				if(ok(1-y, k, j)) {
					ret = doit(k, i, 1-y, x);
					if(ret != 0) {
						fr[i][j][x][y] = k;
						break;
					}
				}
			}
		}
		else {
			if(ok(1-y, j-1, j)) {
				ret = doit(i, j-1, x, 1-y);
				if(ret != 0) {
					fr[i][j][x][y] = j-1;
				}
			}
		}
		return dp[i][j][x][y] = ret;
	}

  static int comp(int[] a, int[] b) {
    // negative: a before b (a < b)
    // positive: a after b (a > b)
    if(a[0] == b[0]) {
      if(a[1] == b[1]) 
        return a[2] - b[2];
      return a[1] - b[1];
    }
    return a[0] - b[0];
  }

  static List<Integer> solve(int[][] v) {
    d = new int[n+1][3];
		for(int i = 0; i <= n; i++) {
			if(i > 0) {
				d[i][0] = v[i-1][0];
				d[i][1] = v[i-1][1];
				d[i][2] = i;
			}
		}
    Arrays.sort(d, (a, b) -> comp(a, b));
    dp = new int[n+1][n+1][2][2];
    fr = new int[n+1][n+1][2][2];
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= n; j++) 
        for(int k = 0; k < 2; k++)
          for(int l = 0; l < 2; l++)
            dp[i][j][k][l] = fr[i][j][k][l] = -1;

    for(int i = 1; i < n; i++) for(int x = 0; x < 2; x++) 
      if(doit(i, n, x, 1-x) == 1 && ok(x, i, n)) {
				int y = 1-x, j = n, sig = 0;
        List<List<Integer>> p = new ArrayList<>();
        p.add(new ArrayList<>());
        p.add(new ArrayList<>());
				while(true) {
					int k = fr[i][j][x][y];
					p.get(1-sig).add(j);
					if(k == -1) break;
					if(i+1 == j) {
						sig = 1-sig;
						j = i;
						i = k;
						int tmp = x;
						x = 1-y;
						y = tmp;
					} else {
						j--;
						y = 1-y;
					}
				}
        List<Integer> ans = new ArrayList<>();
        for(int l = p.get(0).size() - 1; l >= 0; l--)
          ans.add(d[p.get(0).get(l)][2]);
        for(int l = 0; l < p.get(1).size(); l++)
          ans.add(d[p.get(1).get(l)][2]);
				return ans;
			}
    
    return new ArrayList<>();
  }  
  
  
  public static void main(String[] args) throws IOException {
    OutputStreamWriter ow = new OutputStreamWriter(System.out);
    BufferedWriter writer = new BufferedWriter(ow);
    
		FastScanner in = new FastScanner();
		int t = in.nextInt();

    // -----------------------------------------------------
    while (t > 0) { t--;
      n = in.nextInt();
      int[][] data = new int[n][2];
      for(int j = 0; j < 2; j++)
        for(int i = 0; i < n; i++)
          data[i][j] = in.nextInt();
    
     List<Integer> ans = solve(data);
     if(ans.size() == 0) {
       writer.write("-1\n");
     }
     else {
       writer.write(ans.stream().map(i->i.toString()).collect(Collectors.joining(" ")));
       writer.write("\n");
     }
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
