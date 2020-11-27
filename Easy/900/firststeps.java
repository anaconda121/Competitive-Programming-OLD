import java.util.Scanner;
public class firststeps {
    /* https://codeforces.com/problemset/problem/580/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int days = sc.nextInt();
        int[] money = new int[days];
        for (int i = 0; i < money.length; i++) {
            money[i] = sc.nextInt();
        }
        subsegmentNumbers(money);
        sc.close();
    }
    public static void subsegmentNumbers(int[] numbers) {
        int largest = Integer.MIN_VALUE;
        int[] counterStreaks = new int[numbers.length];
        int counterIndex = 0;
        for (int i = 0; i < numbers.length; i++) {
            if (i > 0 && numbers[i] >= numbers[i-1]) {
                counterStreaks[counterIndex]++;
            } else {
                counterIndex++;
            }
        }
        for (int i = 0; i < counterStreaks.length; i++) {
            if (counterStreaks[i] > largest) {
                largest = counterStreaks[i];
            }
        }
        System.out.println(largest + 1);
    }
}