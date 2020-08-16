import java.util.Scanner;
public class wrongsubtraction {
    /* https://codeforces.com/problemset/problem/977/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int originalNumber = sc.nextInt();
        int numSubtract = sc.nextInt();
        for (int i = 0; i < numSubtract; i++) {
            if (originalNumber % 10 != 0) { 
                originalNumber--;
            } else {
                originalNumber /= 10;
            }
        }
        System.out.println(originalNumber);
        sc.close();
    }
}