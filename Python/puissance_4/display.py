class Display:
    def show_board(self, board):
        for row in board:
            print(" | ".join(str(x) for x in row))
            print("-" * 29)

    def get_column(self, player):
        column = int(input(f"Player {player}, choose a column (0-6): "))
        return column

    def show_winner(self, player):
        print(f"Player {player} wins!")

    def show_draw(self):
        print("It's a draw!")
