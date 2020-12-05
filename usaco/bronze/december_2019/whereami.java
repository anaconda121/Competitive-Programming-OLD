import java.io.*;
import java.util.*;

public class whereami {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("whereami.in"));    
        PrintWriter out = new PrintWriter(new File("whereami.out"));
        //input
        int len = Integer.parseInt(in.nextLine());
        String sequence = in.nextLine();
        char[] mailboxes = sequence.toCharArray();
        //setting if combo is unique
        String testSequence = null;
        String longestSequence = null;
        int minLength = 0;
        String[] pair = new String[len];
        String combo = null;
        for (int i = 0; i < len; i++) {
            if (i == 0) testSequence = Character.toString(mailboxes[i]);
            else testSequence += mailboxes[i];
            System.out.println(testSequence);

            System.out.println(Arrays.toString(pair));
            if (pair[1].contains(testSequence) == false) {
                minLength = testSequence.length();
                break;
            }
        }
        System.out.println(minLength);
        out.close();
    }

    public static boolean contains(int index, Set<String> s, int len) {
        for (int i = 0; i < len - index; i++) {
            if (s.)
        }
    }
}