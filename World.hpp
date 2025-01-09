#pragma once
#include <vector>
#include <memory>
#include "Character.hpp"

class World {
public:
 void addCharacter(std::unique_ptr<Character> character);
 void executeAllCommands() const;
 [[nodiscard]] const std::vector<std::unique_ptr<Character>>& getCharacters() const;

private:
 std::vector<std::unique_ptr<Character>> characters;
};
