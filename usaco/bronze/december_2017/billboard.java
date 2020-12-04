import java.io.*;
import java.util.*;

class Point {
    int x,y;
    public Point(int a, int b){
        this.x = a;
        this.y = b;
    }
    public static void displayPoint(Point p) { 
        System.out.println("(" + p.x + ", " + p.y + ")"); 
    } 
}

public class billboard {
    
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("billboard.in"));
        PrintWriter out = new PrintWriter(new File("billboard.out"));
        //input
        int bX1 = in.nextInt(); int bY1 = in.nextInt(); // billboard 1
        int bX2 = in.nextInt(); int bY2 = in.nextInt(); // billboard 1
        in.nextLine();
        int b2X1 = in.nextInt(); int b2Y1 = in.nextInt(); // billboard 2
        int b2X2 = in.nextInt(); int b2Y2 = in.nextInt(); // billboard 2
        in.nextLine();
        int tX1 = in.nextInt(); int tY1 = in.nextInt(); // truck
        int tX2 = in.nextInt(); int tY2 = in.nextInt(); // truck

        //store all coordiantes as point class objs
        Point b1 = new Point(bX1, bY1);// billboard 1
        Point b2 = new Point(bX2, bY2);// billboard 1
        Point b3 = new Point(b2X1, b2Y1);// billboard 2
        Point b4 = new Point(b2X2, b2Y2);// billboard 2
        Point t1 = new Point(tX1, tY1); //truck
        Point t2 = new Point(tX2, tY2); //truck

        //calc areas of both billboards
        int billboard1 = calcArea(bX1, bX2, bY1, bY2);
        int billboard2 = calcArea(b2X1, b2X2, b2Y1, b2Y2);
        
        //calc intersection points for b1 and t
        Point A = new Point(bX1, bY1); Point B = new Point(bX2, bY1);
        Point C = new Point(tX1, tY1); Point D = new Point(tX1, tY2);
        Point intersect = intersect(A, B, C, D);
        A = new Point(bX2, bY1); B = new Point(bX2, bY2);
        C = new Point(tX1, tY2); D = new Point(tX2, tY2);
        Point intersect2 = intersect(A, B, C, D);
        System.out.println(intersect2.x + " , " + intersect2.y);

        //calc intersection points for b2 and t
        A = new Point(tX1, tY1); B = new Point(tX2, tY1);
        C = new Point(b2X1, b2Y1); D = new Point(b2X2, b2Y1);

        displayPoint(A); displayPoint(B); displayPoint(C); displayPoint(D);

        Point intersect3 = intersect(A, B, C, D);
        System.out.println(intersect3.x + " , " + intersect3.y);

        out.close();
    }

    public static void displayPoint(Point p) { 
        System.out.println("(" + p.x + ", " + p.y + ")"); 
    } 

    public static int calcArea(int x1, int x2, int y1, int y2) {
        return (Math.abs(x2-x1) * Math.abs(y2-y1));
    }
    
    public static Point intersect(Point A, Point B, Point C, Point D) {
        int a1 = B.y - A.y; 
        int b1 = A.x - B.x; 
        int c1 = a1*(A.x) + b1*(A.y); 
       
        // Line CD represented as a2x + b2y = c2 
        int a2 = D.y - C.y; 
        int b2 = C.x - D.x; 
        int c2 = a2*(C.x)+ b2*(C.y); 
       
        int determinant = a1*b2 - a2*b1; 
       
        if (determinant == 0) { 
            // The lines are parallel. This is simplified 
            // by returning a pair of FLT_MAX 
            return new Point(Integer.MAX_VALUE, Integer.MAX_VALUE); 
        } 
        else{ 
            int x = (b2*c1 - b1*c2)/determinant; 
            int y = (a1*c2 - a2*c1)/determinant; 
            return new Point(x,y);
        } 
    }
}
