import json
import os

class ScoreManager:
    def __init__(self, filename='scores.json'):
        self.filename = filename
        self.scores = self.load_scores()

    def load_scores(self):
        if os.path.exists(self.filename):
            with open(self.filename, 'r') as f:
                return json.load(f)
        return {1: 0, 2: 0}

    def update_score(self, player):
        self.scores[player] += 1
        self.save_scores()

    def save_scores(self):
        with open(self.filename, 'w') as f:
            json.dump(self.scores, f)

    def display_scores(self):
        print("Scores:")
        for player, score in self.scores.items():
            print(f"Player {player}: {score}")
