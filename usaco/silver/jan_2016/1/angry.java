import java.io.*;
import java.util.*;
public class angry {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("angry.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("angry.out")));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int[] locations = new int[n];
		for(int i = 0; i < n; i++) {
			locations[i] = Integer.parseInt(br.readLine());
		}
		
		Arrays.sort(locations);
		
		int min = 0;
		int max = 500000000;
		while(min != max) {
			int mid = (min+max)/2;
			int used = 0;
			int last = 0;
			while(last < n) {
				used++;
				int curr = last+1;
				while(curr < n && locations[curr] - locations[last] <= 2*mid) {
					curr++;
				}
				last = curr;
			}
			if(used <= k) {
				max = mid;
			}
			else {
				min = mid+1;
			}
		}
		System.out.println(min);
        pw.close();
	}
	
}
