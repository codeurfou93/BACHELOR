from game_logic import GameLogic
from display import Display
from score_manager import ScoreManager

class Game:
    def __init__(self):
        self.logic = GameLogic()
        self.display = Display()
        self.score_manager = ScoreManager()
        self.active_player = 1

    def play(self):
        while True:
            self.display.show_board(self.logic.board)
            column = self.display.get_column(self.active_player)
            if self.logic.place_token(column, self.active_player):
                if self.logic.check_winner(self.active_player):
                    self.display.show_board(self.logic.board)
                    self.display.show_winner(self.active_player)
                    self.score_manager.update_score(self.active_player)
                    break
                self.active_player = 2 if self.active_player == 1 else 1
            if self.logic.is_full():
                self.display.show_board(self.logic.board)
                self.display.show_draw()
                break
