from pokemon import Pokemon, Attack

def test_attack_initialization():
    attack = Attack("griffe", 10)
    assert attack.name == "griffe"
    assert attack.damages == 10
    assert attack.usage_limit == 5
    assert attack.usage == 0

def test_pokemon_initialization():
    pokemon = Pokemon("Pikachu", 35)
    assert pokemon.name == "Pikachu"
    assert pokemon.life_point == 35
    assert len(pokemon.attacks) == 0

def test_add_attack():
    pokemon = Pokemon("Pikachu", 35)
    attack = Attack("griffe", 10)
    pokemon.add_attack(attack)
    assert len(pokemon.attacks) == 1

def test_attack_limit():
    pokemon = Pokemon("Pikachu", 35)
    attack = Attack("griffe", 10)
    pokemon.add_attack(attack)
    pokemon.add_attack(attack)  # Trying to add the same attack again
    assert len(pokemon.attacks) == 1
