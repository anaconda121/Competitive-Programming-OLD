/*
ID: tanisht1
LANG: JAVA
PROG: beads
*/

import java.io.*;
import java.util.*;

public class beadsv4 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("beads.in"));
        PrintWriter out = new PrintWriter(new File("beads.out"));
        
        int length = in.nextInt();
        in.nextLine();
        String sequence = in.nextLine();
        int splitLength = 0;

        String[] singleParts = sequence.split("");
        String[] parts = {"", ""};
        int index = 0;
        int largestScore = 0;
        int score = 0;
        int bestSplitLength = 0;
        String reverse = "";
        for (int m = 0; m < length; m++) {
            for (int i = 0; i < length; i++) {
                //System.out.println("I: " + i);
                if (i < splitLength) {
                    parts[index] += singleParts[i];
                } else if (i == splitLength) {
                    //System.out.println("I equals split length at index: " + i);
                    index++;
                } else if (i > splitLength) {
                    parts[index] += singleParts[i];
                } else if (i == length - 1) {
                    index = 0;
                }
                
                String index1 = parts[1];
                
                for (int j = parts[1].length() - 1; j >= 0; j--) {
                    reverse += index1.charAt(j);
                }
                parts[1] = reverse;
                //System.out.println(Arrays.toString(parts));
            }

            for (int k = 0; k < parts[0].length(); k++) {
                if (k > 0) {
                    String currentLetter = Character.toString(parts[0].charAt(k));
                    String previousLetter = Character.toString(parts[0].charAt(k-1));
                    if (currentLetter.equals(previousLetter)) {
                        score++;
                        System.out.println("current letter: " + currentLetter + " , previous letter: " + previousLetter + " , score: " + score);
                    } else {
                        System.out.println("score lost: current letter: " + currentLetter + " , previous letter: " + previousLetter + " , score: " + score);
                        break;
                    } 
                } 
            }

            for (int z = parts[1].length(); z > 0 ; z--) {
                if (z < parts[1].length()) {
                    String currentLetter = Character.toString(parts[1].charAt(z));
                    String previousLetter = Character.toString(parts[1].charAt(z+1));
                    if (currentLetter.equals(previousLetter)) {
                        score++;
                        System.out.println("current letter: " + currentLetter + " , previous letter: " + previousLetter + " , score: " + score);
                    } else {
                        System.out.println("score lost: current letter: " + currentLetter + " , previous letter: " + previousLetter + " , score: " + score);
                        break;
                    }
                }
            }

            if (score > largestScore) {
                largestScore = score;
                bestSplitLength = splitLength;
                score = 0;
            }

            System.out.println("split length: " + splitLength + reverse + " , index: " + index);
            System.out.println("split length: " + splitLength + Arrays.toString(parts));

            splitLength++;
        }
        
        System.out.println(bestSplitLength);
        System.out.println(largestScore);



        out.close();
    }
}