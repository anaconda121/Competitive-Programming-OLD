import java.io.*;
import java.util.*;
public class pails2 {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("pails.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("pails.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		// read X, Y, and M
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int ans = 0;
		// loop over how many times we can pour the X-size bucket
		for(int xPour = 0; xPour*x <= m; xPour++) {
			// loop over how many times we can then pour over the Y-size bucket
			for(int yPour = 0; xPour*x + yPour*y <= m; yPour++) {
				// determine if we have filled the bucket more than any previous time
				if(xPour*x + yPour*y > ans) {
					ans = xPour*x + yPour*y;
				}
			}
		}
		// print the answer
		pw.println(ans);
		// close output stream
		pw.close();
	}
}