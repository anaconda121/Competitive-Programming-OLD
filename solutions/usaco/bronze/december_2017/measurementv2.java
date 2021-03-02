import java.io.*;
import java.util.*;
public class measurementv2 {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
		
		// read in all of the notes
		int n = Integer.parseInt(br.readLine());
		int[] day = new int[n];
		String[] cow = new String[n];
		int[] change = new int[n];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			day[i] = Integer.parseInt(st.nextToken());
			cow[i] = st.nextToken();
			change[i] = Integer.parseInt(st.nextToken());
		}
		
		// the milk variables track the amount of milk that each cows was last known to produce
		int bessieMilk = 7, elsieMilk = 7, mildredMilk = 7;
		// the on variables are true if that cow produced the highest amount of milk on the previous day
		boolean bessieOn = true, elsieOn = true, mildredOn = true;
		int dayAdjust = 0;
		
		for(int currDay = 1; currDay <= 100; currDay++) {
			// look through the notes to see if there were any changes on this day
			for(int i = 0; i < n; i++) {
				if(day[i] == currDay) {
					if(cow[i].equals("Bessie")) {
						bessieMilk += change[i];
					}
					if(cow[i].equals("Elsie")) {
						elsieMilk += change[i];
					}
					if(cow[i].equals("Mildred")) {
						mildredMilk += change[i];
					}
				}
			}
			// compute the highest milk total and see which cows produced the most milk 
			int highestMilk = Math.max(bessieMilk, Math.max(elsieMilk, mildredMilk));
			boolean bessieOnNext = bessieMilk == highestMilk;
			boolean elsieOnNext = elsieMilk == highestMilk;
			boolean mildredOnNext = mildredMilk == highestMilk;
			if(bessieOn != bessieOnNext || elsieOn != elsieOnNext || mildredOn != mildredOnNext) {
                //any one of the booleans has to change for leader to change, ties can also work since only ONE boolean has to be true, other 2 can be false
				dayAdjust++;
            }
            /* saves result for who is leader for producing milk */
			bessieOn = bessieOnNext;
			elsieOn = elsieOnNext;
			mildredOn = mildredOnNext;
		}

		// print the answer
		pw.println(dayAdjust);
		pw.close();
	}

}