/*
ID: tanisht1
LANG: JAVA
PROG: beads
*/

import java.io.*;
import java.util.*;

public class beads {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("beads.in"));
        PrintWriter out = new PrintWriter(new File("beads.out"));

        int length = in.nextInt();
        in.nextLine();
        String sequence = in.nextLine();
        int split = 0;
        char[] string = sequence.toCharArray();
        
        int prevMax = countBeads(string,0);

        for (int i=1;i<string.length; i++) {
            if (string[i] != string[prevIndex(i,string.length)]) {
                int n = countBeads(string,i);
                if ( n > prevMax) {
                    prevMax = n;
                }
            }
        }
        
        out.println(prevMax);
        out.close();
    }        

    private static int countBeads(char[] string, int i) {

        int fwdBeadsCount = 1;
        char color = string[i];
        int fi = nextIndex(i, string.length);
        while (match(string[fi], color)) {
            color=(color=='w')?string[fi]:color;
            fwdBeadsCount++;
            fi = nextIndex(fi, string.length);
            
            if (fi==i) return string.length; // edge case if all beads are same or w
        }

        int backBeadsCount = 1;
        int pi = prevIndex(i,string.length);
        color = string[pi];
        pi = prevIndex(pi, string.length);
        while (match(string[pi], color)) {
            color=(color=='w')?string[pi]:color;
            backBeadsCount++;
            if (pi==fi) break;
            pi = prevIndex(pi, string.length);
            if (pi==i) return string.length; // edge case if all beads are same or w
        }

        //System.out.println("i=" + i + ", fwdBeadsCount=" + fwdBeadsCount + ",backBeadsCount=" + backBeadsCount);
        return fwdBeadsCount+backBeadsCount;

    }

    private static boolean match(char c1,char c2) {
        if (c1=='w' || c2=='w') return true;
        return (c1==c2);
    }

    private static int nextIndex(int i, int len) {
        if (++i >= len) {
            return i-len;
        }
        return i;
    }

    private static int prevIndex(int i, int len) {
        if (--i < 0) {
            return i+len;
        }
        return i;
    }
}
