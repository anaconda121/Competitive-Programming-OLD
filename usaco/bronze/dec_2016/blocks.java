import java.io.*;
import java.util.*;

public class blocks {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("blocks.in"));    
        PrintWriter out = new PrintWriter(new File("blocks.out"));
        //input
        int N = Integer.parseInt(in.nextLine());
        String[][] words = new String[N][2];
        String[] split = new String[N];
        for (int i = 0; i < N; i++) {
            String word = in.nextLine();
            split = word.split(" ");
            words[i][0] = split[0];
            words[i][1] = split[1];
        }
        for (char a = 'a'; a <= 'z'; a++) {
            int count = 0;
            for (int i = 0; i < N; i++) {
                int fcount = countChar(words[i][0].toCharArray(), a);
                int bcount = countChar(words[i][1].toCharArray(), a);
                count += Math.max(fcount, bcount);
            }
            out.println(count);
        }
        out.close();
    }

    public static int countChar(char[] arr, char a) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == a) {
                count++;
            }
        }
        return count;
    }
}