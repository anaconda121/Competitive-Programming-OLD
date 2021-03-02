import java.util.Scanner;
public class twins {
    /* https://codeforces.com/problemset/problem/160/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfCoins = sc.nextInt();
        int[] coinValues = new int[numberOfCoins];
        int sumOfCoins = 0;
        for (int i = 0; i < numberOfCoins; i++) {
            coinValues[i] = sc.nextInt();
            sumOfCoins += coinValues[i];
        }
        bsort(coinValues);
        int runningTotal = 0;
        int index = 0;
        while ((runningTotal / (double) sumOfCoins) <= 0.5) {
            runningTotal += coinValues[index];
            index++;
        }
        System.out.println(index);
    }

    public static void bsort(int[] number) {
        boolean sorted = false;
        while(sorted == false) {
            sorted = true;
            for (int i = 0; i < number.length - 1; i++) {
                int tempStorage = 0;
                if (number[i] < number[i + 1] && i < number.length) {
                    sorted = false;
                    tempStorage = number[i];
                    number[i] = number[i+1];
                    number[i+1] = tempStorage;
                }
            }
        }
    }
}