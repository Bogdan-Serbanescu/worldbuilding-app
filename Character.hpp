#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Ability.hpp"
#include <string>

#include <memory>


/**
 * @brief Represents a generic character with abilities.
 */
class Character {
protected:
    std::string name; ///< The name of the character.
    std::unique_ptr<Ability> primaryAbility; ///< The primary ability of the character.

public:
    /**
     * @brief Constructs a new Character object.
     *
     * @param name The name of the character.
     * @param primaryAbility The primary ability of the character.
     */
    Character(std::string name, std::unique_ptr<Ability> primaryAbility);
    virtual ~Character() = default;

    /**
     * @brief Introduces the character and displays their ability.
     */
    virtual void introduce() const;

    /**
     * @brief Simulates the character resting to regain strength.
     */
 /*   virtual void rest() const;

    /**
     * @brief Displays the character's details.
     */

    virtual void display() const;

    /**
     * @brief Creates a character from user input.
     *
     * @return A unique pointer to the created Character.
     */
    static std::unique_ptr<Character> createCharacterFromInput();

    /**
     * @brief Creates a clone of the character.
     *
     * @return A unique pointer to a new cloned Character.
     */
    [[nodiscard]] virtual std::unique_ptr<Character> clone() const = 0;

    /**
     * @brief Sets the name of the character.
     *
     * @param newName The new name of the character.
     */
     void setName(const std::string& newName);

    /**
     * @brief Sets a new ability for the character.
     *
     * @param newAbility The new ability of the character.
     */
    void setAbility(std::unique_ptr<Ability> newAbility);

    /**
     * @brief Gets the name of the character.
     *
     * @return The name of the character.
     */
    [[nodiscard]] const std::string& getName() const;

    /**
     * @brief Gets the ability of the character.
     *
     * @return A pointer to the character's primary ability.
     */
    [[nodiscard]] const Ability* getAbility() const;
};

#endif // CHARACTER_HPP
