#include "Ability.hpp"
#include <iostream>
#include <string>

Ability::Ability(std::string name, int spellLevel) : name(std::move(name)), spellLevel(spellLevel) {}

std::string Ability::getName() const {
    return name;
}

int Ability::getSpellLevel() const {
    return spellLevel;
}

void Ability::display() const {
    std::cout << "Ability: " << name << ", Spell Level: " << spellLevel << std::endl;
}

Ability Ability::createAbilityFromInput() {
    std::string abilityName;
    int spellLevel;

    std::cout << "Enter Ability Name: ";
    std::getline(std::cin, abilityName);

    std::cout << "Enter Spell Level: ";
    std::cin >> spellLevel;
    std::cin.ignore();  // Ignore leftover newline character

    return Ability(abilityName, spellLevel);
}
