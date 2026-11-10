class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
    
        check_row = set()
        check_col = set()
        for i in range(9):
            for j in range(9):
                if board[i][j] in check_row or board[j][i] in check_col:
                    return False
                if board[i][j] != '.':
                    check_row.add(board[i][j])
                if board[j][i] != '.':
                    check_col.add(board[j][i])
            check_row.clear()
            check_col.clear()
        

        for x in range(0,9,3):
            for y in range(0,9,3):
                check = set()
                for i in range(x,x+3):
                    for j in range(y,y+3):
                        if board[i][j] in check:
                            return False
                        if board[i][j] != '.':
                            check.add(board[i][j])
                check.clear()
        
        return True
                        
        