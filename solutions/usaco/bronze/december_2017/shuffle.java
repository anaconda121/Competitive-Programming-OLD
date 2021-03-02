import java.io.*;
import java.util.*;

public class shuffle {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("shuffle.in"));
        PrintWriter out = new PrintWriter(new File("shuffle.out"));
        //input
        int cows = in.nextInt(); in.nextLine();
        int[] shuffle = new int[cows];
        int[] id = new int[cows];
        for (int i = 0; i < cows; i++) {
            shuffle[i] = in.nextInt();
            if (i == cows - 1) {
                in.nextLine();
            }
        }
        for (int i = 0; i < cows; i++) {
            id[i] = in.nextInt();
        }
        //performing shuffle
        int[] order = new int[cows];
        for (int i = 0; i < cows; i++) {
            order[i] = i+1;
        }
        int[] currShuffle = new int[cows];
        System.arraycopy(shuffle, 0, currShuffle, 0, shuffle.length);
        for (int i = 0; i < 3; i++) {
            //i++ to represent shuffle
            for (int j = 0; j < cows; j++) {
                //j++ to represent shift in shuffle
                currShuffle[shuffle[j] - 1] = order[j];
                //System.out.println("cS[ " + (shuffle[j] - 1) + " ]" + " = " + currShuffle[shuffle[j] - 1]);
            }
            System.arraycopy(currShuffle, 0, order, 0, currShuffle.length);
            //System.out.println(Arrays.toString(currShuffle));
        }
        //getting ids
        int[] initalOrder = new int[cows];
        for (int i = 0; i < cows; i++) {
            initalOrder[currShuffle[i] - 1] = id[i];
        }
        //System.out.println(Arrays.toString(initalOrder));
        for (int i = 0; i < cows; i++) {
            if (i == cows - 1) {
                out.print(initalOrder[i]);
            } else {
                out.println(initalOrder[i]);
            }
        }

        out.close();
    }
}