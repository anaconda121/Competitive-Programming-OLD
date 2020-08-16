import java.util.Scanner;
public class elephant {
    /* https://codeforces.com/problemset/problem/617/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int friendCoords = sc.nextInt();
        if (friendCoords % 5 == 0) {
            System.out.println(friendCoords / 5);
        } else {
            System.out.println((friendCoords / 5) + 1);
        }
        sc.close();
    }
}