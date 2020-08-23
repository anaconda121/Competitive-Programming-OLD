import java.util.Scanner;
public class netflixwords {
    /* https://codeforces.com/problemset/problem/59/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.nextLine();
        int upperCount = 0;
        int lowerCount = 0;
        for (int i = 0; i < word.length(); i++) {
            char x = word.charAt(i);
            if (Character.isUpperCase(x)) {
                upperCount++;
            } else {
                lowerCount++;
            }
        }
        if (upperCount > lowerCount) {
            System.out.println(word.toUpperCase());
        } else {
            System.out.println(word.toLowerCase());
        }
        sc.close();
    }
}