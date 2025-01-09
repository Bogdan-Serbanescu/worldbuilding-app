#include "World.hpp"
#include <iostream>

void World::addCharacter(std::unique_ptr<Character> character) {
    characters.push_back(std::move(character));
}

const std::vector<std::unique_ptr<Character>>& World::getCharacters() const {
    return characters;
}

void World::executeAllCommands() const {
    std::cout << "Executing all stored commands...\n";
    for (const auto& character : characters) {
        character->display();
    }
}
