import java.util.Scanner;
/*  https://codeforces.com/contest/69/problem/A */
public class physics {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pairs = sc.nextInt();
        int[] x_coord = new int[pairs];
		int[] y_coord = new int[pairs];
		int[] z_coord = new int[pairs];

		for (int i = 0; i < pairs; i++) {
			x_coord[i] = sc.nextInt();
			y_coord[i] = sc.nextInt();
			z_coord[i] = sc.nextInt();
		}
		//summing up array values
		int x_count = 0;
		int y_count = 0;
		int z_count = 0;

		for (int i = 0; i < x_coord.length; i++) {
			x_count += x_coord[i];
			y_count += y_coord[i];
			z_count += z_coord[i];
		}

		//returning output
		if (x_count == 0 && y_count == 0 && z_count == 0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
        }
        sc.close();
    }   
}