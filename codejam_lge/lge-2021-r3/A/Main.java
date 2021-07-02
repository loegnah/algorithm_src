import java.util.stream.*;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
  static final int maxn = 16384, maxk = 64;
  
  static long solve(String[] dat) {
    int n = dat.length, k = dat[0].length();
    List<HashMap<List<Integer>, Integer>> cnt = new ArrayList<>();

    for(int i = 0; i <= k; i++) cnt.add(new HashMap<>());
    for(int i = 0; i < n; i++) {
      int cu = 0;
      int[] counter = new int[26];
      for(int j = 0; j < k; j++) {
        if('A' <= dat[i].charAt(j) && dat[i].charAt(j) <= 'Z') cu++;
        int v = dat[i].charAt(j) - 'A';
        if(dat[i].charAt(j) >= 'a') v = dat[i].charAt(j) -'a';
        counter[v]++;
      }
      List<Integer> elem = new ArrayList<>();
      for(int j = 0; j < 26; j++) elem.add(counter[j]);
      cnt.get(cu).put(elem, cnt.get(cu).getOrDefault(elem,0) + 1);      
    }
    long ans = 0;
    for(int i = 0; i <= k; i++) {
      for(int v: cnt.get(i).values()) {
        long vv = v;
        ans += vv * (vv-1L) / 2L;
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
      int k = in.nextInt();
      String[] dat = new String[n];
      for(int i = 0; i < n; i++)
        dat[i] = in.next();

      long ans = solve(dat);
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
