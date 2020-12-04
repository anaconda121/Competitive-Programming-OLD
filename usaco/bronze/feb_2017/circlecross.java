import java.io.*;
import java.util.*;

public class circlecross {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("circlecross.in"));    
        PrintWriter out = new PrintWriter(new File("circlecross.out"));
        //input
        char[] letters = new char[52];
        String word = in.nextLine();
        letters = word.toCharArray();
        int[] positions = new int[52];
        for (int i = 0; i < positions.length; i++) {
            if (i <= 25) positions[i] = i;
            else positions[i] = i-26;
        }
        //System.out.println(Arrays.toString(positions));
        //calculating sim scores
        int count = 0;
        char[] pair = new char[2];
        int[] scores = new int[26];
        int k = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 52; j++) {
                if (letters[j] == letters[i] && j != i) {
                    scores[k] = Math.abs(positions[j] - positions[i]);
                    System.out.println(Arrays.toString(scores));
                    k++;
                }
            }
        }
        int unique = distinctCount(scores);
        System.out.println(unique);
        if (unique == 1 || unique == 13) count = 0;
        else {
            for (int i = 0; i < 26; i++) {
                if (scores[i] != 1) {
                    count++;
                }
            }
            count /=4 ;
        } 
        
        out.println(count);
        out.close();
    }

    public static int distinctCount(int[] arr) {
        int[] unique = new int[arr.length];
        int index = 0;
        for (int i = 0; i < arr.length; i++) { 
            // Check if the picked element  
            // is already printed 
            int j; 
            for (j = 0; j < i; j++) {
                if (arr[i] == arr[j]) 
                    break; 
            }
            
            // If not printed earlier,  
            // then print it 
            if (i == j) {
                unique[index] = arr[i];
                index++;
            }
        } 
        return index;
    }
}