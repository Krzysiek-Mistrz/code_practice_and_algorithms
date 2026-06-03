def gamestate(board):
    x_count = sum(row.count('X') for row in board)
    o_count = sum(row.count('O') for row in board)
    
    if o_count > x_count:
        raise ValueError("Wrong turn order: O started")
    if x_count > o_count + 1:
        raise ValueError("Wrong turn order: X went twice")
        
    def has_won(player):
        for row in board:
            if all(cell == player for cell in row):
                return True
        
        for col in range(3):
            if all(board[row][col] == player for row in range(3)):
                return True
        
        if board[0][0] == board[1][1] == board[2][2] == player:
            return True
        
        if board[0][2] == board[1][1] == board[2][0] == player:
            return True
        
        return False

    x_win = has_won('X')
    o_win = has_won('O')
    
    if x_win and o_win:
        raise ValueError("Impossible board: game should have ended after the game was won")
    
    if x_win and x_count == o_count:
        raise ValueError("Impossible board: game should have ended after the game was won")
    
    if o_win and x_count > o_count:
        raise ValueError("Impossible board: game should have ended after the game was won")
    
    if x_win or o_win:
        return "win"
        
    if x_count + o_count == 9:
        return "draw"
        
    return "ongoing"