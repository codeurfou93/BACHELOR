class GameLogic:
    def __init__(self):
        self.board = [[0 for _ in range(7)] for _ in range(6)]
        self.winning_length = 4

    def place_token(self, column, player):
        if self.is_valid_move(column):
            for row in reversed(range(6)):
                if self.board[row][column] == 0:
                    self.board[row][column] = player
                    return True
        return False

    def is_valid_move(self, column):
        return self.board[0][column] == 0

    def check_winner(self, player):
        return (self.check_lines(player) or
                self.check_columns(player) or
                self.check_diagonals(player))

    def check_lines(self, player):
        for row in self.board:
            count = 0
            for cell in row:
                count = count + 1 if cell == player else 0
                if count >= self.winning_length:
                    return True
        return False

    def check_columns(self, player):
        for col in range(7):
            count = 0
            for row in range(6):
                count = count + 1 if self.board[row][col] == player else 0
                if count >= self.winning_length:
                    return True
        return False

    def check_diagonals(self, player):
        for row in range(6):
            for col in range(7):
                if self.board[row][col] == player:
                    if self.check_diagonal_right(row, col, player) or self.check_diagonal_left(row, col, player):
                        return True
        return False

    def check_diagonal_right(self, row, col, player):
        count = 0
        for i in range(4):
            if row + i < 6 and col + i < 7 and self.board[row + i][col + i] == player:
                count += 1
        return count >= self.winning_length

    def check_diagonal_left(self, row, col, player):
        count = 0
        for i in range(4):
            if row + i < 6 and col - i >= 0 and self.board[row + i][col - i] == player:
                count += 1
        return count >= self.winning_length

    def is_full(self):
        return all(self.board[0][col] != 0 for col in range(7))
