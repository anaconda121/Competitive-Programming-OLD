import java.io.*;
import java.time.YearMonth;
import java.util.*;

public class pails {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("pails.in"));    
        PrintWriter out = new PrintWriter(new File("pails.out"));
        //input
        int x = in.nextInt(); int y = in.nextInt(); int m = in.nextInt(); 
        //calc 4 diff options
        Integer[] options = {0,0,0,0,0,0};
        int index = 0;
        int count = 0;
        //option1
        while (m - options[index] >= x) { options[index] += x; count++; }
        //option2
        index++;
        while (m - options[index] >= y) { options[index] += y; count++; }
        //option3
        index++;
        while (m - options[index] >= x){
            count++;
            if (m - options[index] -x <= y) {
                options[index] += y;
                break;
            } else options[index] += x;
        }
        //option4
        index++;
        while (m - options[index] >= y){
            count++;
            if (m - options[index] -y <= x) {
                options[index] += x;
                break;
            } else options[index] += y;
        }
        //option5
        index++;
        int avg = Math.round((float) count/4);
        if (avg % 2 != 0) {
            int x_count = avg/2;
            options[index] = x_count * x + (avg - x_count) * y;
            //option6
            index++;
            options[index] = x_count * y + (avg - x_count) * x;
        }
        
        //System.out.println(Arrays.toString(options));
        int max = Collections.max( Arrays.asList(options));
        out.println(max);
        
        

        out.close();
    }
}