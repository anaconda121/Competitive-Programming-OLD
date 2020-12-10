import java.io.*;
import java.util.*;

public class outofplace {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("outofplace.in"));    
        PrintWriter out = new PrintWriter(new File("outofplace.out"));
        //input
        int N = Integer.parseInt(in.nextLine());
        int[] after = new int[N];
        int unique = 0;
        for (int i = 0; i < N; i++) {
            after[i] = Integer.parseInt(in.nextLine());
            if (i > 0) {
                if (after[i-1] != after[i]) {
                    unique++;
                }
            }
        }
        //finding index bessie needs to go in
        int[] original = new int[N];
        System.arraycopy(after,0,original,0,N);
        Arrays.sort(original);
        int bessieIndex = 0;
        for (int i = 0; i < N; i++) {
            if (after[i]!=original[i]){
                bessieIndex = i; 
            }
        }
        int[] uniqueArray = new int[unique];
        int index = 0;
        for (int i = 0; i < N; i++) {
            if (i > 0) {
                if (after[i-1] != after[i]) {
                    uniqueArray[index] = after[i]; index++;
                }
            } else if (i == 0) {
                uniqueArray[index] = after[i];
            }
        }
        System.out.println(Arrays.toString(uniqueArray));
        out.close();
    }
}