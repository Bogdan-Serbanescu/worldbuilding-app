#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Ability {
private:
    std::string name;
    int SpellLevel;

public:
    // Constructor explicativ (pass by value and use std::move)
    Ability(std::string name, int SpellLevel)
        : name(std::move(name)), SpellLevel(SpellLevel) {}

    // Constructor de copiere
    Ability(const Ability& other) = default;

    // Operator= de copiere
    Ability& operator=(const Ability& other) = default;

    // Destructor
    ~Ability() = default;

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Ability& ability) {
        os << "Ability: " << ability.name << ", Power Level: " << ability.SpellLevel;
        return os;
    }
};

class Character {
private:
    std::string name;
    Ability primaryAbility;

public:
    // Constructor explicativ (pass by value and use std::move)
    Character(std::string name, Ability primaryAbility)
        : name(std::move(name)), primaryAbility(std::move(primaryAbility)) {}

    // Constructor de copiere
    Character(const Character& other) = default;

    // Operator= de copiere
    Character& operator=(const Character& other) = default;

    // Destructor
    ~Character() = default;

    // Funcții membre
    void introduce() const {
        std::cout << name << " showcases their " << primaryAbility << std::endl;
    }

    void rest() const {
        std::cout << name << " is resting to regain strength." << std::endl;
    }

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const Character& character) {
        os << "Character: " << character.name << ", " << character.primaryAbility;
        return os;
    }
};

class World {
private:
    std::vector<Character> characters;

public:
    // Constructor explicit
    World() = default;

    // Constructor de copiere
    World(const World& other) = default;

    // Operator= de copiere
    World& operator=(const World& other) = default;

    // Destructor
    ~World() = default;

    // Funcții membre
    void addCharacter(const Character& character) {
        characters.push_back(character);
    }

    void displayCharacters() const {
        for (const auto& character : characters) {
            std::cout << character << std::endl;
        }
    }

    void introduceAllCharacters() const {
        for (const auto& character : characters) {
            character.introduce();
        }
    }
};

// Clasa NPCCharacter moștenește Character
class NPCCharacter : public Character {
private:
    int mana;

public:
    // Constructor explicativ (pass by value and use std::move)
    NPCCharacter(std::string name, Ability primaryAbility, int mana)
        : Character(std::move(name), std::move(primaryAbility)), mana(mana) {}

    // Constructor de copiere
    NPCCharacter(const NPCCharacter& other) = default;

    // Operator= de copiere
    NPCCharacter& operator=(const NPCCharacter& other) = default;

    // Destructor
    ~NPCCharacter() = default;

    // Funcții membre
    void castSpell() const {
        std::cout << "Casting a spell with " << mana << " mana remaining." << std::endl;
    }

    // Operator de afișare
    friend std::ostream& operator<<(std::ostream& os, const NPCCharacter& mCharacter) {
        os << static_cast<const Character&>(mCharacter) << ", Mana: " << mCharacter.mana << "%";
        return os;
    }
};

int main() {
    Ability fireball("Fireball", 3);
    Character hero("Aragon", fireball);
    NPCCharacter mage("Luna", Ability("Dominate Person", 5), 75);

    World world;
    world.addCharacter(hero);
    world.addCharacter(mage);

    world.displayCharacters();
    world.introduceAllCharacters();
    hero.rest();
    mage.castSpell();

    return 0;
}
