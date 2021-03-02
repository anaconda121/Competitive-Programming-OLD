/* http://darrenyao.com/usacobook/java.pdf page 30 */
import java.io.*;
import java.util.*;

public class buckets {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("buckets.in"));
        PrintWriter out = new PrintWriter(new File("buckets.out"));

        int numBuckets = in.nextInt(); in.nextLine(); 
        int[] capacities = new int[numBuckets];
        int[] filled = new int[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            capacities[i] = in.nextInt(); 
        }
        in.nextLine();
        for (int i = 0; i < numBuckets; i++) {
            filled[i] = in.nextInt(); 
        }

        for (int i = 0; i < numBuckets; i++) {
            if (i < numBuckets - 1) {
                filled[i+1] += filled[i];
                filled[i] = 0;
                if (filled[i+1] > capacities[i+1]) {
                    int putBack = filled[i+1] - capacities[i+1];
                    filled[i+1] -= putBack;
                    filled[i] += putBack;
                }
            }
        }

        for (int i = 0; i < numBuckets; i++) {
            out.println(filled[i] + " ");
        }
        out.close();
    }
}