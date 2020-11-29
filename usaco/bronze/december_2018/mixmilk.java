import java.io.*;
import java.util.*;

public class mixmilk {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("mixmilk.in"));
        PrintWriter out = new PrintWriter(new File("mixmilk.out"));

        int pours = 100;
        int[] capacities = new int[3];
        int[] amounts = new int[3];
        for (int i = 0; i < 3; i++) {
            capacities[i] = in.nextInt();
            amounts[i] = in.nextInt();
            if (i != 2) {
                in.nextLine();
            }
        }

        int bucket = 1;
        for (int i = 0; i < pours; i++) {
            if (bucket > 3) {
                bucket = 1;
            }
            int amt = 0;
            if (bucket != 3) {
                amt = Math.min(amounts[bucket-1], capacities[bucket] - amounts[bucket]);
            } else {
                amt = Math.min(amounts[2], capacities[0] - amounts[0]);
            }
            if (bucket == 1) {
                amounts[0] -= amt;
                amounts[1] += amt;
            } else if (bucket == 2) {
                amounts[1] -= amt;
                amounts[2] += amt;
            } else if (bucket == 3) {
                amounts[2] -= amt;
                amounts[0] += amt;
            }
            bucket++;
        }

        for (int i = 0; i < amounts.length; i++) {
            if (i < amounts.length - 1) {
                out.println(amounts[i]);
            } else {
                out.print(amounts[i]);
            }
        }
        out.close();
    }
}