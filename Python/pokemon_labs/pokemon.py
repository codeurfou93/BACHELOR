import random
class Attack:
    def __init__(self, name, damage, usage_limit=0):
        self.name = name
        self.damage = damage
        self.usage = usage_limit
        self.limit = usage_limit

    def __str__(self):
        return f"name: {self.name}\ndamage: {self.damage}\nusage: {self.usage}\nlimit: {self.limit}"

class Pokemon:
    counter = 0

    def __init__(self, name, life_point):
        self.name = name
        self.life_point = life_point
        self.attacks = []
        Pokemon.counter += 1

    def add_attack(self, attack):
        if attack not in self.attacks and len(self.attacks) < 4:
            self.attacks.append(attack)

    def heal(self, points):
        self.life_point += points
        for attack in self.attacks:
            attack.usage = attack.limit

    def attack(self, other_pokemon):
        if self.attacks:
            chosen_attack = random.choice(self.attacks)
            if chosen_attack.usage > 0:
                other_pokemon.life_point -= chosen_attack.damage
                chosen_attack.usage -= 1

    def __str__(self):
        return f"{self.name}, Life Points: {self.life_point}, Attacks: {len(self.attacks)}"
