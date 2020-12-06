import java.io.*;
import java.util.*;

public class promote {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("promote.in"));    
        PrintWriter out = new PrintWriter(new File("promote.out"));
        //input
        int N = 4;
        int[] before = new int[N];
        int[] after = new int[N];
        for (int i = 0; i < N; i++) {
            before[i] = in.nextInt();
            after[i] = in.nextInt();
            if (i < N - 1) in.nextLine();
        }
        //logic
        int[] count = new int[3];
        int diff = 0;
        for (int i = 0; i < N; i++) {
            if (after[i] > before[i]) { 
                diff = after[i]-before[i];
                if (i == 1) {
                    count[0]++; //bronze - silver
                } else if (i == 2) {
                    count[0]++; count[1]++;
                } else if(i == 3) {
                    count[0]++; count[1]++; count[2]++;
                }
            } 
            if (after[i] < before[i]) {
                if (i == 1) {
                    
                } else if (i == 2) {

                } else if (i == 3) {
                    
                }
            }
            ///System.out.println(Arrays.toString(count));
        }
        for (int i = 0; i < count.length; i++){
            out.println(count[i]);
        }
        out.close();
    }
}