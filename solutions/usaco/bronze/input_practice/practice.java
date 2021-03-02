import java.io.*;
import java.util.*;

public class practice {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("practice_input.in"));
        PrintWriter out = new PrintWriter(new File("practice_input.out"));
        /*
        int n = 0;
        for (int i = 0; i < 2; i ++) {
            n += in.nextInt();
        }
        
        int [][]numbers = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                numbers[i][j] = in.nextInt();
            }
        }*/
        while(in.hasNext()){
            int row = in.nextInt();
            int letterCount = in.nextInt();
            System.out.println(row);
            System.out.println(letterCount);
            char [][] words = new char[row][letterCount];
        
            for (int i = 0; i < row; i++) {
                String word = in.nextLine();
                System.out.println("Word" + word);
                out.println(word);

                char[] ch = word.toCharArray(); 
                System.out.println(Arrays.toString(ch));

                int j = 0;
                for (int k = 0; k < letterCount; k++){
                    words[j][k] = ch[k];
                }
                j++;
                
                out.println(Arrays.deepToString(words));
                out.close();
            }
        }
        //out.println(n);
        //out.println(Arrays.deepToString(numbers));


        
    
        

    }
}