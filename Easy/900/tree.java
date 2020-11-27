import java.util.Scanner;
import java.util.Arrays;
public class tree {
    /* https://codeforces.com/problemset/problem/1248/B */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numSticks = sc.nextInt();
        int[] stickLengths = new int[numSticks];
        for (int i = 0; i < numSticks; i++) {
            stickLengths[i] = sc.nextInt();
        }
        largestLength(stickLengths);
        sc.close();
    }

    public static void largestLength(int[] sticks) {
        //System.out.println(Arrays.toString(reverseBubbleSort(sticks)));
        Arrays.sort(sticks);
        long xAxisTotal = 0;
        long yAxisTotal = 0;
        int boundary;
        if (sticks.length%2==0) {
            boundary = sticks.length/2;
        } else {
            boundary = (sticks.length-1)/2;
        }

        for (int i = 0; i < sticks.length; i++) {
            if (i < boundary) {
                xAxisTotal += sticks[i];
            } else {
                yAxisTotal += sticks[i];
            }
        }
        //System.out.println(xAxisTotal);
        //System.out.println(yAxisTotal);
        System.out.println(xAxisTotal*xAxisTotal+yAxisTotal*yAxisTotal);
    }

}   