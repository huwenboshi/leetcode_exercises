import copy

class Solution:
    # @return a list of lists of string
    def solveNQueens(self, n):
        
        # create a board
        board = [['.']*n for i in xrange(n)]
       
        # run helper
        solutions = set()
        self.nqueen_helper(board, n, solutions)

        # to list
        solution_list = []
        for sol in solutions:
            solution_list.append(sol.split())

        return solution_list

    def is_attacked(self, board, i, j):
        
        # get board size
        n = len(board)
        
        # check row
        for k in xrange(0, n):
            if(k == j):
                continue
            if(board[i][k] == 'Q'):
                return True

        # check col
        for k in xrange(0, n):
            if(k == i):
                continue
            if(board[k][j] == 'Q'):
                return True

        # check diag left to right
        k = 1
        while(i+k<n and j+k<n):
            if(board[i+k][j+k] == 'Q'):
                return True
            k += 1
        k = 1
        while(i-k>=0 and j-k>=0):
            if(board[i-k][j-k] == 'Q'):
                return True
            k += 1
        k = 1
        while(i+k<n and j-k>=0):
            if(board[i+k][j-k] == 'Q'):
                return True
            k += 1
        k = 1
        while(i-k>=0 and j+k<n):
            if(board[i-k][j+k] == 'Q'):
                return True
            k += 1

        return False
    
    def get_valid_steps(self, board):
        n = len(board)
        valid_steps = []
        for i in xrange(n):
            for j in xrange(n):
                if(board[i][j] != 'Q'
                   and (not self.is_attacked(board,i,j))):
                    valid_steps.append((i,j))
        return valid_steps

    def nqueen_helper(self, board, num_left, solutions):
      
        # get board size
        n = len(board)

        # if no queen to place return
        if(num_left == 0):
            board_str = self.board_to_str(board)
            solutions.add(board_str)

        # get valid step
        valid_steps = self.get_valid_steps(board)
        
        # try placing a queen at the valid step and solve it
        for step in valid_steps:
            new_board = copy.deepcopy(board)
            new_board[step[0]][step[1]] = 'Q'
            self.nqueen_helper(new_board, num_left-1, solutions)

    def board_to_str(self, board):
        board_str = ''
        for row in board:
            board_str += ''.join(row) + ' '
        return board_str

sol = Solution()
print sol.solveNQueens(4)
