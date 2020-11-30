import java.io.*;
import java.util.*;
public class sol {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("cowqueue.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cowqueue.out")));
		
		// read in the number of cows
		int n = Integer.parseInt(br.readLine());
		
		// allocate arrays to store entry times and duration of questioning times
		int[] enter = new int[n];
		int[] duration = new int[n];
		
		// allocate an array to store if a cow has already been processed
		boolean[] processed = new boolean[n];
		
		// read in the entry and questioning times
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			enter[i] = Integer.parseInt(st.nextToken());
			duration[i] = Integer.parseInt(st.nextToken());
		}
		
		int nextAvailableTime = 0;
		// loop over the cows
		for(int a = 0; a < n; a++) {
			int nextToEnter = -1;
			for(int i = 0; i < n; i++) {
				// if a cow has not been processed and it has the earlier entry time of all cows seen so far, it is next to enter
				if(!processed[i] && (nextToEnter == -1 || enter[i] < enter[nextToEnter])) {
					nextToEnter = i;
				}
			}
			// process that cow, tracking exactly when questioning ends
			processed[nextToEnter] = true;
			if(enter[nextToEnter] > nextAvailableTime) {
				nextAvailableTime = enter[nextToEnter] + duration[nextToEnter];
			}
			else {
				nextAvailableTime = nextAvailableTime + duration[nextToEnter];
			}
		}
		
		pw.println(nextAvailableTime);
		pw.close();
	}
}