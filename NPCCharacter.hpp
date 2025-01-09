#ifndef NPC_CHARACTER_HPP
#define NPC_CHARACTER_HPP

#include "Character.hpp"

class NPCCharacter : public Character {
private:
 int health;

public:
 NPCCharacter(const std::string& name, std::unique_ptr<Ability> ability, int health);
 void display() const override;
};

#endif // NPC_CHARACTER_HPP
