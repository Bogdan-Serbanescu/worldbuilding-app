#include "Character.hpp"
#include <iostream>
#include <limits>

Character::Character(const std::string& name, std::unique_ptr<Ability> ability)
    : name(name), ability(std::move(ability)) {}

[[nodiscard]] const std::string& Character::getName() const {
    return name;
}

void Character::setName(const std::string& newName) {
    name = newName;
}

void Character::setAbility(std::unique_ptr<Ability> newAbility) {
    ability = std::move(newAbility);
}

void Character::display() const {
    std::cout << "Character: " << name << "\n";
    if (ability) {
        ability->display();
    } else {
        std::cout << "No ability assigned.\n";
    }
}

Character::~Character() = default;

std::unique_ptr<Character> Character::createCharacterFromInput() {
    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
    std::cout << "Enter character name: ";
    std::getline(std::cin, name); // Correctly read the character name

    auto ability = Ability::createAbilityFromInput();
    return std::make_unique<Character>(name, std::make_unique<Ability>(ability->getName(), ability->getPowerLevel()));
}

