import java.util.Scanner;
public class translation {
    /* https://codeforces.com/problemset/problem/41/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.nextLine();
        String reverseWord = sc.nextLine();
        int count = 0;
        int len = word.length();
        //System.out.println(len);
        //System.out.print(reverseWord.length());
        for(int i = 0; i < reverseWord.length(); i++) {
            if (word.length() != reverseWord.length()) {
                break;
            }
            if (reverseWord.charAt(i) == (word.charAt(len - 1))) {
                count++;
            }
            len--;
        }
        if (count == word.length()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}