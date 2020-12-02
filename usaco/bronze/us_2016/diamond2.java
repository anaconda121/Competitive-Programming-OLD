import java.io.*;
import java.util.*;

public class diamond2 {
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
        //System.out.println(diamonds + " , " + diff);
        //calc diamonds
        Arrays.sort(sizes);
        //System.out.println(Arrays.toString(sizes));
        int count = 0;
        int max = -75;
        for (int i = 0; i < sizes.length; i++) {
            int num = sizes[i];
            int threshold = num + diff;
            //System.out.print(threshold + ", ");
            for (int j = i; j < sizes.length; j++) {
                count = count(sizes, i, threshold);
            }
            if (count > max) {
                max = count;
            }
            //System.out.print(count + " , ");
            count = 0;
        }
        out.println(max);
        out.close();
    }

    public static int count(int[] arr, int j, int threshold) {
        int count = 0;
        for (int i = j; i < arr.length; i++) {
            if (arr[i] <= threshold) {
                count++;
            }
        }
        return count;

            
    }
    
}
