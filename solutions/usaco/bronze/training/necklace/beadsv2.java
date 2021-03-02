/*
ID: tanisht1
LANG: JAVA
PROG: beads
*/

import java.io.*;
import java.util.*;

public class beadsv2 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("beads.in"));
        PrintWriter out = new PrintWriter(new File("beads.out"));

        int length = in.nextInt();
        in.nextLine();
        String sequence = in.nextLine();
        int splitLength = 1;
        String necklace = sequence + sequence;
        System.out.println(necklace);
        int index = 0;
        String[] parts = {"", ""};

        for (int i = 0; i < length * 2; i++) {
            for (int j = 0; j < length * 2; j++) {
                System.out.println("iteration: " + + splitLength);
                if (j == (length * 2 - 1)) {
                    parts[index] += necklace.charAt(j);
                    index = 0;
                } else if (j < splitLength) {
                    parts[index] += necklace.charAt(j);
                } else if (j == splitLength) {
                    parts[index] += necklace.charAt(j);

                    index++;
                } else if (j > splitLength) {
                    parts[index] += necklace.charAt(j);
                }  
                System.out.println(Arrays.toString(parts));
            }
            System.out.println("iteration: " + + splitLength + Arrays.toString(parts));

            splitLength++;
            parts[0] = "";
            parts[1] = "";
        }
    }
}