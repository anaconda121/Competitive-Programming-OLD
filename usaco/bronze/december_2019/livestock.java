import java.io.*;
import java.util.*;

public class livestock {
    public static void main(String[] args) throws IOException {
        //read and write files
        Scanner in = new Scanner(new File("lineup.in"));
        PrintWriter out = new PrintWriter(new File("lineup.out"));

        int lines = in.nextInt();
        in.nextLine(); //skips white space to prevent array-index-out-of-bounds-exception
        out.println(lines);

        String [] cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
        String [] names = new String [cows.length];
        int[] indexes = new int[6];

        int index = 0;
        while(in.hasNext()) {
            String word = in.nextLine();
            String[] individualWord = new String [6];
            individualWord = word.split(" ");
            System.out.println(Arrays.toString(individualWord)); 
            String name1 = individualWord[0];
            System.out.println("1: "+ name1);
            String name2 = individualWord[5];  
            System.out.println("2: "+ name2);
            for (int i = 0; i < cows.length; i++) {
                if (cows[i].equals(name1)) {
                    //System.out.println("Storing cow: " + cows[i] + " at index #: " + index);
                    indexes[index] = i;
                    index++;
                } else if (cows[i].equals(name2)) {
                    //System.out.println("Storing cow: " + cows[i] + " at index #: " + index);
                    indexes[index] = i;
                    index++;
                }
            }
        }

        //System.out.println(Arrays.toString(indexes));
        //System.out.println(index);
        for (int i = 0; i < names.length; i++) {
            out.println(names[i] + "\n");
        }
    }
}
