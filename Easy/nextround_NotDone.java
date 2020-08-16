import java.util.Scanner;
import java.util.Arrays;
public class nextround_NotDone {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int totalPlayers = sc.nextInt();
        int kPlayer = sc.nextInt();
        int[] scores = new int[totalPlayers];
        int advanceCount = 0;
        int sameCount = 0;

        for (int i = 0; i < totalPlayers; i++) {
            scores[i] = sc.nextInt();

            if (scores[i] > kPlayer) {
                advanceCount++;
            }

            if (scores[i] == kPlayer) {
                sameCount++;
            }
        }

        if (sameCount == totalPlayers || areSame(scores)) {
            advanceCount = totalPlayers;
        }
        System.out.println(advanceCount);
    }

    public static boolean areSame(int arr[]) { 
        int first = arr[0]; 
        for (int i=1; i<arr.length; i++) {
            if (arr[i] != first || arr[i] == 0) {
                return false; 
            }
        }
        return true; 
    } 
}