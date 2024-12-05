#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <string>
#include <iostream>

/**
 * @brief Represents an ability with a name and spell level.
 */
class Ability {
private:
    std::string name; ///< The name of the ability.
    int spellLevel; ///< The level of the ability.

public:
    /**
     * @brief Constructs a new Ability object.
     *
     * @param name The name of the ability.
     * @param spellLevel The spell level of the ability.
     */
    Ability(std::string name, int spellLevel);
    virtual ~Ability() = default;

    /**
     * @brief Gets the name of the ability.
     *
     * @return The name of the ability.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Gets the spell level of the ability.
     *
     * @return The spell level of the ability.
     */
    [[nodiscard]] int getSpellLevel() const;

    /**
     * @brief Displays the ability's details.
     */
    virtual void display() const;

    /**
     * @brief Creates an ability from user input.
     *
     * @return A new Ability object created from input.
     */
    static Ability createAbilityFromInput();
};

#endif // ABILITY_HPP
