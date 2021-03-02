/*
ID: tanisht1
LANG: JAVA
PROG: gift1
*/

import java.util.*;
import java.io.*;

public class gift1 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("gift1.in"));
        PrintWriter out = new PrintWriter(new File("gift1.out"));

        int totalPeople = in.nextInt();
        in.nextLine();
        //System.out.println(totalPeople);

        String[] names = new String[totalPeople];
        for (int i = 0; i < names.length; i++) {
            names[i] = in.nextLine();
        }
        //System.out.println(Arrays.toString(names));

        int[] balances = new int[totalPeople];
        int[] budgets = new int[totalPeople];
        int[] numGifts = new int[totalPeople];
        String[] recievers = new String[totalPeople];

        for (int i = 0; i < totalPeople; i++) {
            String name = in.nextLine();
            //System.out.println(i + " : " + name);
            budgets[i] = in.nextInt();
            numGifts[i] = in.nextInt();
            //System.out.println("budget: " + budgets[i]);
            //System.out.println("numGifts: " + numGifts[i]);
            //System.out.println(Arrays.toString(budgets));
            //System.out.println(Arrays.toString(numGifts));
            if (!(numGifts[i] == 0 && i == totalPeople - 1)){
                //System.out.println("name: " + name + " going to next line");
                in.nextLine();
            } 

            //System.out.println("got passed, name: " + name);
            
            int index = 0;
            for (int z = 0; z < names.length; z++) {
                if (names[z].equals(name)) {
                    index = z;
                    break;
                }
            }

            //System.out.println("index for name: " + index);

            int giftAmount = 0;
            if (budgets[i] != 0 && numGifts[i] != 0) {
                giftAmount = (int) budgets[i] / numGifts[i];
            } else {
                giftAmount = 0;
            }

            //System.out.println("gift amount for: " + names[index] + " " + giftAmount);

            int backToGiver = budgets[i] - (giftAmount * numGifts[i]);

            //System.out.println("back to giver or: " + names[index] + " " + backToGiver);

            balances[index] += (-1 * budgets[i]) + backToGiver;

            for (int j = 0; j < numGifts[i]; j++) {
                recievers[j] = in.nextLine();
                for (int k = 0; k < totalPeople; k++) {
                    if (names[k].equals(recievers[j])) {
                        balances[k] += giftAmount;
                    }
                }
            }
            //System.out.println(Arrays.toString(balances));
        }

        String [] outcomes = new String[totalPeople];
        for (int i = 0; i < totalPeople; i++) {
            outcomes[i] = names[i] + " " + String.valueOf(balances[i]);
            out.println(outcomes[i]);
        }
        out.close();
    }
}