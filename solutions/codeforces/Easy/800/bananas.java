import java.util.Scanner;
/* https://codeforces.com/problemset/problem/546/A */
public class bananas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int costBananas = sc.nextInt();
        int soilderMoney = sc.nextInt();
        int bananasWanted = sc.nextInt();
        int totalCost = 0;
        for (int i = 1;  i <= bananasWanted; i++){
            totalCost += costBananas * i;
        }
        if (totalCost > soilderMoney) {
            System.out.println(totalCost - soilderMoney);
        } else {
            System.out.println("0");
        }
        sc.close();
    }
}