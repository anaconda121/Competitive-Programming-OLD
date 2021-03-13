import java.util.*;
import java.io.*;

public class shuffle {

	public static int n;
	public static int[] parent;
	public static int[] currStatus;

	public static void count(int i) {
		HashSet<Integer> there = new HashSet<Integer>();
		while (currStatus[i] == 0) {
			there.add(i);
			currStatus[i] = 1;
			i = parent[i];
		}
		if (there.contains(i)) {
			int savei = i;
			do {
				currStatus[i] = 2;
				i = parent[i];
			} while (i != savei);
		}
	}

	public static void main(String[] args) throws Exception {
		// Read in the parenting array.
		BufferedReader stdin = new BufferedReader(new FileReader("shuffle.in"));
		StringTokenizer tok = new StringTokenizer(stdin.readLine());
		n = Integer.parseInt(tok.nextToken());
		StringTokenizer line = new StringTokenizer(stdin.readLine());
		parent = new int[n];
		for (int i=0; i<n; i++)
			parent[i] = Integer.parseInt(line.nextToken())-1;

		currStatus = new int[n];

		for (int i=0; i<n; i++)
			if (currStatus[i] == 0)
				count(i);

		// Count items in a cycle.
		int res = 0;
		for (int i=0; i<n; i++)
			if (currStatus[i] == 2)
				res++;

		PrintWriter out = new PrintWriter(new FileWriter("shuffle.out"));
		out.println(res);
		out.close();
		stdin.close();
	}	
}