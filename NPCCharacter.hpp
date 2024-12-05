#ifndef NPCCHARACTER_HPP
#define NPCCHARACTER_HPP

#include "Character.hpp"

/**
 * @brief Represents a non-playable character (NPC) with mana.
 */
class NPCCharacter : public Character {
private:
 int mana; ///< Mana of the NPC character.

public:
 /**
  * @brief Constructs a new NPCCharacter object.
  *
  * @param name The name of the NPC.
  * @param primaryAbility The ability of the NPC.
  * @param mana The mana of the NPC.
  */
 NPCCharacter(std::string name, std::unique_ptr<Ability> primaryAbility, int mana);
 ~NPCCharacter() override = default;

 /**
  * @brief Casts a spell with the NPC's remaining mana.
  */
 void castSpell() const;

 /**
  * @brief Introduces the NPC and displays its ability and mana.
  */
 void introduce() const override;

 /**
  * @brief Displays the NPC's details.
  */
 void display() const override;

 /**
  * @brief Creates a clone of the NPC.
  *
  * @return A new NPCCharacter object cloned from this NPC.
  */
 [[nodiscard]] std::unique_ptr<Character> clone() const override;
};

#endif // NPCCHARACTER_HPP
