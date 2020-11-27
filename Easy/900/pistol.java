import java.util.Scanner;
import java.util.Arrays;

public class pistol {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCans = sc.nextInt();
        int[] canStrength = new int[numCans];
        for (int i = 0; i < canStrength.length; ++i) {
            canStrength[i] = sc.nextInt();
        }   
        calcShots(canStrength);
    }

    public static void calcShots(int[] cans) {
        int[] oldCans = cans;
        System.out.println(Arrays.toString(oldCans));
        Arrays.sort(cans);
        int cansHit = 0;
        int totalShots = 0;
        int[] order = new int[cans.length + 1];
        System.out.println(order.length);
        int index = 0;
        for (int i = cans.length; i > 0; --i) {
            totalShots += (cans[i-1] * cansHit) + 1;
            cansHit++;
            for (int x = 0; x < cans.length; ++x) {
                System.out.println(oldCans[x]);
                if (i > 0 && oldCans[x] == cans[i-1]) {
                    /*for (int y = 0; y < order.length; y++) {
                        System.out.print(order[y] + " index");
                    }*/
                    order[index] = x;
                    index++;
                }
            }
        } 
        System.out.println(totalShots);
        for (int i = 0; i < order.length; ++i) {
            System.out.print(order[i] + " ");
        }
    }
}