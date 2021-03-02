import java.io.*;
import java.util.*;
public class div7 {
    /* LOGIC
        Define a prefix of a list to be the first K numbers of the list. 
        Note that any sublist of numbers can be obtained by taking some prefix of the original list and removing a smaller prefix of the list. 
        Note furthermore that if you take the sums of the two prefixes, they have the same remainder when divided by 7.
        Therefore, for every prefix, we can compute the sum of the numbers in the prefix modulo 7, and keep track of the shortest and longest prefixes that when summed are 
        equivalent to x modulo 7 for 0<x<7. The answer is then the maximum difference between the lengths of the shortest and longest prefixes over all x.
    */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("div7.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("div7.out")));
		
		int n = Integer.parseInt(br.readLine());
		int[] first = new int[7]; //7 because max of anything % 7 can be 7
		int[] last = new int[7];
		Arrays.fill(first, Integer.MAX_VALUE);
		first[0] = 0;
		int currPref = 0;
		for(int i = 1; i <= n; i++) {
			currPref += Integer.parseInt(br.readLine());
			currPref %= 7;
			first[currPref] = Math.min(first[currPref], i); //start of streak
			last[currPref] = i; //end of streak
        }
        // first arr = [0,2,3,1,intmax,intmax,7]
        // last arr = [0,4,3,6,0,0,7]                                           
        // 6 - 1 = 5, which is ans
		int ret = 0;
		for(int i = 0; i < 7; i++) {
			if(first[i] <= n) {
				ret = Math.max(ret, last[i] - first[i]);
			}
		}
		pw.println(ret);
		pw.close();
	}
}