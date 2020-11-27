package ride;

/*
ID: tanisht1
LANG: JAVA
PROG: ride
*/
import java.util.*;
import java.io.*;

public class ride {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("ride.in"));
        PrintWriter out = new PrintWriter(new File("ride.out"));
        String comet = in.nextLine();
        String group = in.nextLine();
        int cometScore = calcScore(comet);
        int groupScore = calcScore(group);
        String outcome = "";
        if ((int) cometScore % 47 == (int) groupScore % 47) {
            outcome = "GO";
        } else {
            outcome = "STAY";
        }
        out.println(outcome);
        out.close();
    }

    public static int calcScore(String str) {
        str = str.toLowerCase();
        char[] ch  = str.toCharArray();
        int score = 1;
        for(char c : ch){
            int temp = (int)c;
            int temp_integer = 96; //for lower case
            if (temp<=122 && temp>=97) {
                score *= (temp-temp_integer);
            }
        }
        return score;
    }
}