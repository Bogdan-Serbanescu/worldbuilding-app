#include "Character.hpp"
#include "NPCCharacter.hpp"
#include <iostream>

Character::Character(std::string name, std::unique_ptr<Ability> primaryAbility)
    : name(std::move(name)), primaryAbility(std::move(primaryAbility)) {}

void Character::introduce() const {
    std::cout << name << " showcases their ability: ";
    primaryAbility->display();
}

/*void Character::rest() const {
    std::cout << name << " is resting to regain strength." << std::endl;
}
*/
void Character::display() const {
    std::cout << "Character: " << name << ", ";
    primaryAbility->display();
}

void Character::setName(const std::string& newName) {
    name = newName;
}

void Character::setAbility(std::unique_ptr<Ability> newAbility) {
    primaryAbility = std::move(newAbility);
}

const std::string& Character::getName() const {
    return name;
}

const Ability* Character::getAbility() const {
    return primaryAbility.get();
}

std::unique_ptr<Character> Character::createCharacterFromInput() {
    std::string charName;
    std::cout << "Enter Character Name: ";
    std::getline(std::cin, charName);

    std::unique_ptr<Ability> ability = std::make_unique<Ability>(Ability::createAbilityFromInput());

    return std::make_unique<NPCCharacter>(charName, std::move(ability), 100);
}

