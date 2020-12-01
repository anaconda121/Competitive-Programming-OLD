import java.util.Scanner;
public class beautifulmatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] matrix = new int[5][5];
        int rowBeautiful = 2;
        int colBeautiful = 2;
        int rowCurrentBeautiful = 0;
        int colCurrentBeautiful = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = sc.nextInt();
                if (matrix[i][j] == 1) {
                    rowCurrentBeautiful = i;
                    colCurrentBeautiful = j;
                }
            }
        }
        int moves = Math.abs(rowBeautiful - rowCurrentBeautiful) + Math.abs(colBeautiful - colCurrentBeautiful);
        System.out.println(moves);
        sc.close();
    }
}