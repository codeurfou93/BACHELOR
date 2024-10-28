import unittest
from game_logic import GameLogic

class TestGameLogic(unittest.TestCase):
    def setUp(self):
        self.logic = GameLogic()

    def test_place_token(self):
        self.logic.place_token(0, 1)
        self.assertEqual(self.logic.board[5][0], 1)

    def test_check_winner_horizontal(self):
        for col in range(4):
            self.logic.place_token(col, 1)
        self.assertTrue(self.logic.check_winner(1))

    def test_check_winner_vertical(self):
        for _ in range(4):
            self.logic.place_token(0, 1)
        self.assertTrue(self.logic.check_winner(1))

    def test_check_winner_diagonal(self):
        self.logic.place_token(0, 1)
        self.logic.place_token(1, 1)
        self.logic.place_token(2, 1)
        self.logic.place_token(3, 1)
        self.assertTrue(self.logic.check_winner(1))

if __name__ == '__main__':
    unittest.main()
