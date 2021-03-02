import java.util.Scanner;
import java.util.Arrays;
public class rooms {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rooms = sc.nextInt();
        int roomsAvailable = 0;
        int[] roomSpaces = new int[rooms * 2];
        for (int i = 0; i < rooms; i++) {
            roomSpaces[i] = sc.nextInt();
        }
        System.out.println(Arrays.toString(roomSpaces));
        for (int i = 0; i < roomSpaces.length; i++) {
            if (i > 0 && i % 2 == 0) {
                if (roomSpaces[i] > roomSpaces[i-1]) {
                    roomsAvailable++;
                }
            } 
        }
        System.out.println(roomsAvailable);
    }
}