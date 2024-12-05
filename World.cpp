#include "World.hpp"
#include <iostream>

void World::addCharacter(std::unique_ptr<Character> character) {
    characters.push_back(std::move(character));
}

void World::displayCharacters() const {
    if (characters.empty()) {
        std::cout << "No characters created yet.\n";
    } else {
        for (const auto& character : characters) {
            character->display();
        }
    }
}

void World::introduceAllCharacters() const {
    for (const auto& character : characters) {
        character->introduce();
    }
}
