#include "NPCCharacter.hpp"
#include <iostream>

NPCCharacter::NPCCharacter(std::string name, std::unique_ptr<Ability> primaryAbility, int mana)
    : Character(std::move(name), std::move(primaryAbility)), mana(mana) {}

void NPCCharacter::castSpell() const {
    std::cout << "Casting a spell with " << mana << " mana remaining." << std::endl;
}

void NPCCharacter::introduce() const {
    std::cout << "NPC " << name << " showcases their ability: ";
    primaryAbility->display();
    std::cout << "Mana: " << mana << std::endl;
}

void NPCCharacter::display() const {
    Character::display();  // Display base class data
    std::cout << "Mana: " << mana << "%" << std::endl;
}

std::unique_ptr<Character> NPCCharacter::clone() const {
    return std::make_unique<NPCCharacter>(name, std::make_unique<Ability>(*primaryAbility), mana);
}
