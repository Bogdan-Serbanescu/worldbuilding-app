#ifndef WORLD_HPP
#define WORLD_HPP

#include "Character.hpp"
#include <vector>
#include <memory>

/**
 * @brief Represents a world containing multiple characters.
 */
class World {
private:
    std::vector<std::unique_ptr<Character>> characters; ///< A list of characters in the world.

public:
    World() = default;
    ~World() = default;

    /**
     * @brief Adds a character to the world.
     *
     * @param character A unique pointer to the character to add.
     */
    void addCharacter(std::unique_ptr<Character> character);

    /**
     * @brief Displays all characters in the world.
     */
    void displayCharacters() const;

    /**
     * @brief Introduces all characters in the world.
     */
    void introduceAllCharacters() const;

    /**
     * @brief Gets the list of characters.
     *
     * @return A constant reference to the list of characters.
     */
    [[nodiscard]] const std::vector<std::unique_ptr<Character>>& getCharacters() const {
        return characters;
    }
};

#endif // WORLD_HPP
