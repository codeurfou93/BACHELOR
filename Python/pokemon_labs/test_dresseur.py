from dresseur import Dresseur
from pokemon import Pokemon

def test_defi_aleatoire():
    dresseur1 = Dresseur("Ash")
    dresseur2 = Dresseur("Misty")
    
    pokemon1 = Pokemon("Pikachu", 35)
    pokemon2 = Pokemon("Bulbasaur", 30)
    pokemon3 = Pokemon("Charmander", 25)
    pokemon4 = Pokemon("Squirtle", 28)

    dresseur1.add_pokemon(pokemon1)
    dresseur1.add_pokemon(pokemon2)
    dresseur2.add_pokemon(pokemon3)
    dresseur2.add_pokemon(pokemon4)

    initial_experience_dresseur1 = dresseur1.experience
    initial_experience_dresseur2 = dresseur2.experience
    
    dresseur1.Defi_Aleatoire(dresseur2)

    assert dresseur1.experience == initial_experience_dresseur1 + 1 or dresseur2.experience == initial_experience_dresseur2 + 1
