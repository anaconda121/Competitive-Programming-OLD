import java.io.*;
import java.util.*;
public class diamond {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
        Scanner in = new Scanner(new File("diamond.in"));		
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("diamond.out")));
        //input
        int diamonds = in.nextInt(); int diff = in.nextInt(); in.nextLine();
        int[] sizes = new int[diamonds];
        for (int i = 0; i < diamonds; i++) {
            sizes[i] = in.nextInt(); 
            if (i < diamonds - 1) {
                in.nextLine();
            }
        }
        //calc various diffs
        int currDiff = 0;
        int count = 0;
        for (int i = 0; i < diamonds; i++) {
            int curr = sizes[i];
            for (int j = i + 1; j < diamonds; j++) {
                if (i > 0) {
                    currDiff = Math.abs(curr - sizes[j]);
                    if (currDiff <= diff) {
                        if (!(alreadyIn(sizes, sizes[j], j)) && curr != sizes[j]) {
                            count++;
                            System.out.println("2adding : " + count + " , " + curr + " , " + sizes[j]);
                        }
                    }
                } else if (i == 0) {
                    currDiff = Math.abs(curr - sizes[j]);
                    if (currDiff <= diff && curr != sizes[j]) {
                        count++;
                        System.out.println("adding : " + count + " , " + curr + " , " + sizes[j]);
                    }
                }
            }
        }
        out.println(count);
        out.close();
    }
    
    public static boolean alreadyIn(int[] arr, int num, int index) {
        for (int i = 0; i < index; i++) {
            if (arr[i] == num) {
                return true;
            }
        }
        return false;
    }
}