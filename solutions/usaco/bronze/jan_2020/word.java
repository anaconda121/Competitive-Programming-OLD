import java.io.*;
import java.util.*;

public class word {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("word.in"));
        PrintWriter out = new PrintWriter(new File("word.out"));
        //input
        int N = in.nextInt();
        int K = in.nextInt(); in.nextLine();
        String[] words = new String[N];
        int[] lengths = new int[N];
        String whole = in.nextLine();
        words = whole.split(" ");
        for (int i = 0; i < N; i++) {
            lengths[i] = words[i].length();
        }
        //creating line separations
        int currLenCount = 0;
        String[] lines = new String[N];
        int index = 0;
        boolean nextLine = false;
        for (int i = 0; i < N; i++) {
            if (currLenCount + lengths[i] < K) {
                //adding to current line
                currLenCount += lengths[i];
                if (lines[index] == null) {
                    lines[index] = words[i];
                } else {
                    lines[index] += " " + words[i];  
                }
            } else if (currLenCount + lengths[i] == K) {
                //adding to current line than move to next line
                currLenCount += lengths[i];
                if (lines[index] == null) {
                    lines[index] = words[i]; index++;
                } else {
                    lines[index] += " " + words[i]; index++;
                }
                nextLine = true;
            } else if (currLenCount + lengths[i] > K) {
                //need to add word to next line
                index++;
                if (lines[index] == null) {
                    lines[index] = words[i]; 
                } else {
                    lines[index] += " " + words[i]; 
                }
                currLenCount = 0; currLenCount += lengths[i];
            }
            //System.out.println(Arrays.toString(lines) + "     " + currLenCount);
            if (nextLine == true) {
                currLenCount = 0;
                nextLine = false;
            }
        }
        for (int i = 0; i < index+1; i++) {
            out.println(lines[i]);
        }
        //System.out.println(Arrays.toString(lines));
        

        out.close();
    }
}