#include "NPCCharacter.hpp"
#include <iostream>

NPCCharacter::NPCCharacter(const std::string& name, std::unique_ptr<Ability> ability, int health)
    : Character(name, std::move(ability)), health(health) {}

void NPCCharacter::display() const {
    Character::display();
    std::cout << "Health: " << health << "\n";
}
