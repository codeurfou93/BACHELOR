import random
from pokemon import Pokemon

class Dresseur:
    def __init__(self, name, experience=0, level=1):
        self.name = name
        self.experience = experience
        self.level = level
        self.pokemons = []

    def add_pokemon(self, pokemon):
        self.pokemons.append(pokemon)

    def taverne(self):
        for pokemon in self.pokemons:
            pokemon.heal(10)

    def update(self):
        if self.experience >= 10:
            self.level += 1
            self.experience = 0

    def Defi_Aleatoire(self, dresseur2):
        self.taverne()
        dresseur2.taverne()

        if not self.pokemons or not dresseur2.pokemons:
            raise ValueError("Un des dresseurs n'a pas de Pokémon.")
        
        pokemon1 = random.choice(self.pokemons)
        pokemon2 = random.choice(dresseur2.pokemons)

        while pokemon1.life_point > 0 and pokemon2.life_point > 0:
            pokemon1.attack(pokemon2)
            if pokemon2.life_point > 0:
                pokemon2.attack(pokemon1)

        if pokemon1.life_point <= 0 and pokemon2.life_point <= 0:
            print("Match nul!")
        elif pokemon1.life_point > 0:
            pokemon1.experience += 1
            self.experience += 1
        else:
            pokemon2.experience += 1
            dresseur2.experience += 1

        self.update()
        dresseur2.update()
