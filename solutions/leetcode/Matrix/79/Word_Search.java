class Word_Search {
    public boolean exist(char[][] board, String word) {
        
        int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(board[i][j] == word.charAt(0) && dfs(i, j, 0, word, dir, board)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    public static boolean dfs(int i, int j, int idx, String word, int[][] dir, char[][] board) {
       
        if(idx == word.length())
            return true;
        
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(idx)) {
            return false;
        }
        
        boolean result = false;
        char temp = board[i][j];
        board[i][j] = '#';
        
        for(int d = 0; d < dir.length; d++) {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            
            if(dfs(x, y, idx + 1, word, dir, board)) {
                result = true;
                break;
            }
        }
        
        board[i][j] = temp;
        return result;
    }
}