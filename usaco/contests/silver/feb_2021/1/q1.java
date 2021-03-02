import java.util.*;

class q1 { 
private static boolean debug = false;

private static int numCows;
private static int NUM = 3100;

private static int[][] cowsMat = new int[NUM][NUM];
private static Queue<Integer> comfCowsQueue = new LinkedList<>();

private static boolean[][] addCowsExist = new boolean[NUM][NUM];
private static boolean[][] cowExist = new boolean[NUM][NUM];
private static int neededCows = 0;
private static int comfortableCows = 0;


static void log(String str) {
    if (debug) 
    System.out.println(str); 
}

public static void main(String args[]) { 

    Scanner sin =  new Scanner(System.in);
    numCows = sin.nextInt(); 
    sin.nextLine();

    for (int i=0; i<numCows; i++) {
        int x = 1010+sin.nextInt(); ;
        int y = 1010+sin.nextInt(); ;
        
        if (isAdditionalCowHere(x,y)) {
            removeAdditionalCow(x, y);
        } else {
            addCow(x,y, "orig");
            updateAdditionalCowsNeeded();
        }

        log("Comfortable :" + comfortableCows); 
        log("Needed :" + neededCows); 
        System.out.println(neededCows); 

    }

    sin.close();
}


static boolean isComfortable(int x, int y) {
    if (3 == cowsMat[x][y]) {
        return true;
    }

    return false;
}

static void updateAdditionalCowsNeeded() {

    while (!comfCowsQueue.isEmpty()) {

        int cow = comfCowsQueue.poll();
        int x = cow / NUM;
        int y = cow % NUM;

        if (!isComfortable(x,y)) continue;

        int freeloc = getFreeLocation(x, y);
        int freeX = freeloc / NUM;
        int freeY = freeloc % NUM;

        log("updateAdditionalCowsNeeded:" + x + ":" + y + ", free:" + freeX + ":" + freeY + 
        ", xyCount:" + cowsMat[x][y] + ", freexyCount:" + cowsMat[freeX][freeY]);
        
        addAdditionalCow(freeX, freeY);
        addCow(freeX, freeY, "additional");

        log("after addcow updateAdditionalCowsNeeded:" + x + ":" + y + ", free:" + freeX + ":" + freeY + 
        ", xyCount:" + cowsMat[x][y] + ", freexyCount:" + cowsMat[freeX][freeY]);
    }
}

static int getFreeLocation(int x, int y) {
    if (!cowExist[x-1][y]) {
        return NUM*(x-1) + y;
    }
    if (!cowExist[x+1][y]) {
        return NUM*(x+1) + y;
    }
    if (!cowExist[x][y-1]) {
        return NUM*(x) + y-1;
    }
    if (!cowExist[x][y+1]) {
        return NUM*(x) + y+1;
    }
    throw new IllegalStateException("getFreeLocation called for non-comfortable cow:" + x + ":" + y + 
    ", cowMat:" + cowsMat[x][y]);
}


static void addCow(int x, int y, String where) {

    log (where + " adding Cow:" + x + ":" + y);

    cowExist[x][y] = true;

    if (cowsMat[x][y] == 3) {
        comfortableCows++;
        addToComfCowQueue(x, y);
    }

    updateNeighbors(x-1, y);
    updateNeighbors(x+1, y);
    updateNeighbors(x, y-1);
    updateNeighbors(x, y+1);
}

static void updateNeighbors(int x, int y) {
    cowsMat[x][y]++; 

    if (cowExist[x][y]) {
        if (cowsMat[x][y] == 3) {  // i.e. this is comfortable now so increase the count
            comfortableCows++;
            addToComfCowQueue(x, y);
        } else if (cowsMat[x][y] > 3) {  // i.e. it was comfortable before but now 4 neighbours so reduce the count
            comfortableCows--;
        }
    }
}

static void addAdditionalCow(int x, int y) {
        addCowsExist[x][y] = true;
        neededCows++;
        log("adding additional :" + x + ":" + y);
}

static void removeAdditionalCow(int x, int y) {
        addCowsExist[x][y] = false;
        neededCows--;
        log("removing additional :" + x + ":" + y);
}

static boolean isAdditionalCowHere(int x, int y) {
    return addCowsExist[x][y];
}

static void addToComfCowQueue(int x, int y) {
    comfCowsQueue.add(NUM*x + y);
    log("addToComfCowQueue :" + x + ":" + y);
}

} 
