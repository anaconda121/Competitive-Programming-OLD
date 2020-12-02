import java.io.*;
import java.util.*;

public class tttt {
    static char[][] winners = new char[8][3];

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("tttt.in"));
        PrintWriter out = new PrintWriter(new File("tttt.out"));
        //input
        char[][] board = new char[3][3];
        for (int i = 0; i < 3; i++) {
            String row = in.nextLine();
            char[] letters = row.toCharArray();
            board[i][0] = letters[0]; board[i][1] = letters[1]; board[i][2] = letters[2];
        }
        int solo = 0;
        int team = 0;
        //checking rows
        char[] cows = new char[3];
        char[] teamCows = new char[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cows[j] = board[i][j];
            }
            teamCows = distinctCount(cows);
            storeWinners(winners, teamCows, i);
        }
       
        //checking cols
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                cows[i] = board[i][j];
            }
            teamCows = distinctCount(cows);
            storeWinners(winners, teamCows, j+3);
        }
        //checking diagonals
        cows[0] = board[0][0]; cows[1] = board[1][1]; cows[2] = board[2][2]; 
        teamCows = distinctCount(cows);
        storeWinners(winners, teamCows, 6);

        cows[0] = board[0][2]; cows[1] = board[1][1]; cows[2] = board[2][0];
        teamCows = distinctCount(cows);
        storeWinners(winners, teamCows, 7);

        //System.out.println(Arrays.deepToString(winners));
        //countWinners(winners);

        String[] winners = new String[8];
        int index = 0;
        int count = 0;
        for (int i = 0; i < 8; i++) {
            char one = tttt.winners[i][0]; char two = tttt.winners[i][1]; char three = tttt.winners[i][2]; 
            //System.out.println(one + " " + two + " " + three + "test test");
            if ((int)one == 0 || (int)two == 0 || (int)three == 0) {
                StringBuilder sb = new StringBuilder();

                if ((int) one == 0 && (int) two == 0) sb.append(three);
                else if ((int) one == 0 && (int) three == 0) sb.append(two);
                else if ((int) two  == 0 && (int) three == 0) sb.append(one);
                else if ((int) one == 0) sb.append(two).append(three);
                else if ((int) two == 0) sb.append(one).append(three);
                else if ((int) three == 0) sb.append(one).append(two);
               

                winners[index] = sb.toString();
                index++; count++;
            }
        }
        System.out.println(Arrays.toString(winners));
        int count2 = 0; //int team = 0; int solo = 0;
        for (int i = 0; i < count; i++) {   
            //winners[i] = winners[i].replaceAll("\\s+", "");    
            String curr = winners[i];
            String curr2 = curr.replace(" ", "");    
            for (int j = i; j < count; j++) {
                if (!(curr2.equals(winners[j]))) {
                    count2++;
                }
            }
            //System.out.println(curr2 + " , " + curr2.length());
            if (count2 == count - i -1) {
                if (curr2.length() == 2) {
                    //team dub
                    team++;
                } else if (curr2.length() == 1) {
                    solo++;
                }
            } 
            count2 = 0;    
        }
        out.println(solo);
        out.println(team);
        out.close();
    }

    public static void storeWinners(char[][] arr, char[] store, int row) {
        for (int i = 0; i < store.length; i++) {
            winners[row][i] = store[i];
        }
    }   
    
    public static char[] distinctCount(char[] arr) {
        char[] unique = new char[arr.length];
        int index = 0;
        for (int i = 0; i < arr.length; i++) { 
            // Check if the picked element  
            // is already printed 
            int j; 
            for (j = 0; j < i; j++) {
                if (arr[i] == arr[j]) 
                    break; 
            }
            
            // If not printed earlier,  
            // then print it 
            if (i == j) {
                unique[index] = arr[i];
                index++;
            }
        } 
        return unique;
    }
}