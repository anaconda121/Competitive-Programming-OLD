import java.io.File;
import java.io.IOException;
import java.util.*;

public class question3_2 {

    static class cow {
        char direction;
        int x;
        int y;
        int eat;
        int endx;
        int endy;
        boolean stopped;
        int stopper;

        public cow(char d, int x2, int y2) {
            direction = d;
            x = x2;
            y = y2;    
            eat = Integer.MAX_VALUE;
            endx = Integer.MIN_VALUE;
            endy = Integer.MIN_VALUE;
            stopped = false;
            stopper = Integer.MAX_VALUE;
        }

        public void print() {
            System.out.println("direction: " + direction 
            + " x: " + x
            + " y: " + y 
            + " squares eaten: " + eat);
        }
    }

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new File("input.in"));
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        cow[] cows = new cow[n];
        int[] xcoords = new int[n];
        //System.out.println("\n");
        for (int i = 0; i < n; i++) {
            String all = in.nextLine();
            //System.out.println(all);
            String[] split = all.split(" ");
            //System.out.println(Arrays.toString(split));
            char d = all.charAt(0);
            int x = Integer.parseInt(split[1]);
            int y = Integer.parseInt(split[2]);
            //System.out.println(d + " " + x + " " + y);
            cows[i] = new cow(d,x,y);
            //cows[i].print();
            //System.out.println("\n");
            xcoords[i] = x;
        }

        cows = calcStopping(cows);
        cows = getDist(cows);
        for (int i = 0; i < cows.length; i++) {
            if (cows[i].eat == Integer.MAX_VALUE) {
                System.out.println("Infinity");
            } else {
                System.out.println(cows[i].eat);
            }
        }
        in.close();
    }

    public static cow[] calcStopping(cow[] cows) {
        for (int i = 0; i < cows.length; i++) {
            for (int j = 0; j < cows.length; j++) {
                int eastcow = 0;
                int northcow = 0;
                //cows[i].print();
                //cows[j].print();
                if (cows[i].direction != cows[j].direction) {
                    if (cows[i].direction == 'E') {
                        eastcow = i;
                        northcow = j;
                    } else {
                        eastcow = j;
                        northcow = i;
                    }
    
                    if (cows[northcow].x > cows[eastcow].x && cows[northcow].y < cows[eastcow].y) {
                        //calc times, cows will intersect at some point
                        //System.out.println("intersecting, " + i + " " + j);
                        int northtime = cows[eastcow].y - cows[northcow].y;
                        int eastime = cows[northcow].x - cows[eastcow].x;

                        if (eastime > northtime ) {
                            //north cow comes first
                            //System.out.println("north wins " + i + " " + j);
                            cows[eastcow].stopper = Math.min(cows[eastcow].stopper, cows[northcow].x);

                            /*if (cows[eastcow].eat > eastime && cows[eastcow].eat == Integer.MAX_VALUE) {
                                cows[eastcow].eat = eastime;
                                //System.out.println("replacing east " + cows[eastcow].eat);
                            } else if (cows[eastcow].eat > eastime) {
                                cows[eastcow].eat += eastime;
                            }*/

                            //cows[eastcow].stopped = true;
                            //if (i == 1 ) cows[eastcow].print();
                        } else if (northtime > eastime) {
                            //east cow comes first
                            //System.out.println("east wins " + i + " " + j);
                            cows[northcow].stopper = Math.min(cows[northcow].stopper, cows[eastcow].y);
                            //cows[northcow].stopped = true;
                            
                            /*if (cows[northcow].eat > northtime && cows[northcow].eat == Integer.MAX_VALUE) {
                                cows[northcow].eat = northtime;
                            } else if (cows[northcow].eat > northtime) {
                                cows[northcow].eat += northtime;
                            }*/

                            //if (i == 1 ) cows[eastcow].print();
                        } 
                    }
                }
            }
        }
        return cows;
    }

    public static cow[] getDist(cow[] cows) {
        for (int i = 0; i < cows.length; i++) {
            for (int j = 0; j < cows.length; j++) {
                if (cows[i].direction != cows[j].direction) {
                    int eastcow = 0;
                    int northcow = 0;
                    if (cows[i].direction == 'E') {
                        eastcow = i;
                        northcow = j;
                    } else {
                        eastcow = j;
                        northcow = i;
                    }

                    if (cows[northcow].x > cows[eastcow].x && cows[northcow].y < cows[eastcow].y) {
                        //calc times, cows will intersect at some point
                        int northtime = Math.abs(cows[eastcow].y - cows[northcow].y);
                        int eastime = Math.abs(cows[eastcow].x - cows[northcow].x);

                        if (eastime > northtime && cows[northcow].stopper > cows[eastcow].y) {
                            //north comes first
                            cows[eastcow].eat = Math.min(cows[eastcow].eat, eastime);
                        } else if (northtime > eastime && cows[eastcow].stopper > cows[northcow].x) {
                            //east comes first
                            cows[northcow].eat = Math.min(cows[northcow].eat, northtime);
                        }
                    }
                }
            }
        }    
        return cows;
    }
}
