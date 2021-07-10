# https://leetcode.com/problems/valid-sudoku/submissions/

def isValidSudoku(board):
    """
    :type board: List[List[str]]
    :rtype: bool
    """
    multi = 0
    
    for i in range(3):
        for j in range(3):
            curr_r = 3 * multi + j
            curr_nums = []
            for k in range(9):
                if k != 0 and k % 3 == 0:
                    curr_nums = []

                curr_c = k
                
                print(curr_r, curr_c , board[curr_r][curr_c], board[curr_r][curr_c] != ".", curr_nums)
                flag = board[curr_c][curr_c] != "."
                if flag == True:
                    #print(b[curr_r][curr_c])
                    curr_nums.append(int(board[curr_c][curr_c]))
                    unique = list(set(curr_nums))
                    curr_nums.sort()
                    unique.sort()
                    #print(curr_nums, unique)
                    if (unique != curr_nums):
                        #print("1: ")
                        return False
        multi += 1
    
    for i in range(9):
        curr_nums = []
        for j in range(9):
            flag = board[i][j] != "."
            if flag == True:
                curr_nums.append(int(board[i][j]))
                unique = list(set(curr_nums))
                curr_nums.sort()
                unique.sort()
                if (unique != curr_nums):
                    #print("2: ")
                    return False
    
    for j in range(9):
        curr_nums = []
        for i in range(9):
            flag = board[i][j] != "."
            if flag == True:
                curr_nums.append(int(board[i][j]))
                unique = list(set(curr_nums))
                curr_nums.sort()
                unique.sort()
                if (unique != curr_nums):
                    #print("3: ")
                    return False
    return True

#b = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
#b=[["8","3",".",".","7",".",".",".","."]
# ,["6",".",".","1","9","5",".",".","."]
# ,[".","9","8",".",".",".",".","6","."]
# ,["8",".",".",".","6",".",".",".","3"]
# ,["4",".",".","8",".","3",".",".","1"]
# ,["7",".",".",".","2",".",".",".","6"]
# ,[".","6",".",".",".",".","2","8","."]
# ,[".",".",".","4","1","9",".",".","5"]
# ,[".",".",".",".","8",".",".","7","9"]]
#print(b[0][2] != ".", b[0][2])
b=[ [".",".",".",".","5",".",".","1","."],
    [".","4",".","3",".",".",".",".","."],
    [".",".",".",".",".","3",".",".","1"],
    ["8",".",".",".",".",".",".","2","."],
    [".",".","2",".","7",".",".",".","."],
    [".","1","5",".",".",".",".",".","."],
    [".",".",".",".",".","2",".",".","."],
    [".","2",".","9",".",".",".",".","."],
    [".",".","4",".",".",".",".",".","."]]

    # [['.', '.', '.', '.', '5', '.', '.', '1', '.'], 
    # ['.', '4', '.', '3', '.', '.', '.', '.', '.'], 
    # ['.', '.', '.', '.', '.', '3', '.', '.', '1']]

print(b[0:3][0:3])
#print(b)
#ans = isValidSudoku(b)
#print(ans)

# for r in range(9):
#     for c in range(9):
#         print(b[r][c], b[r][c] != ".")
