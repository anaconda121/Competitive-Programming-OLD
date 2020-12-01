import java.util.Scanner;
public class chessgames {
    /* https://codeforces.com/problemset/problem/734/A*/
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String gamesPlayed = sc.nextLine();
        String record = sc.nextLine();
        int anton = 0;
        int danik = 0;
        for (int i = 0; i < record.length(); i++) {
            char game = record.charAt(i);
            if (game == 'D') {
                danik++;
            } else {
                anton++;
            }
        }
        if (danik > anton) {
            System.out.println("Danik");
        } else if(anton > danik) {
            System.out.println("Anton");
        } else {
            System.out.println("Friendship");
        }
        sc.close();
    }
}