package bronze.template;

import java.io.*;
import java.util.*;

public class template {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("template.in"));
        int n = in.nextInt();
    
        PrintWriter out = new PrintWriter(new File("template_out.out"));
        System.out.println(n);
        out.println(n);
        out.close();
    }
}