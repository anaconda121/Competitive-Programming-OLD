import java.util.Scanner;
public class football {
    /* https://codeforces.com/problemset/problem/96/A */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String teams = sc.nextLine();
        if (teams.length() < 7) {
            System.out.println("NO");
        } else {
            dangerous(teams);
        }
    }

    public static void dangerous(String teams) {
        int counter = 0;
        for (int i = 0; i < teams.length(); i++) {
            char player = teams.charAt(i);
            if (i > 0 && player == teams.charAt(i-1)) {
                counter++;
                if (counter >= 6) {
                    break;
                }
            } else {
                counter = 0;
            }

        }
        if (counter >= 6) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}