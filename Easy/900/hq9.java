import java.util.Scanner;
public class hq9 {
    /* https://codeforces.com/problemset/problem/133/A?csrf_token=fe34058d3f1c8bc12f61b98206f0d997 */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == 'H' || input.charAt(i) == 'Q' || input.charAt(i) == '9') {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
        sc.close();
    }
}