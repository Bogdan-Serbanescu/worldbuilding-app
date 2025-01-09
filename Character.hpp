#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Ability.hpp"
#include <memory>
#include <string>

class Character {
private:
    std::string name;
    std::unique_ptr<Ability> ability;

public:
    Character(const std::string& name, std::unique_ptr<Ability> ability);

    [[nodiscard]] const std::string& getName() const;
    void setName(const std::string& newName);

    void setAbility(std::unique_ptr<Ability> newAbility);

    virtual void display() const;
    virtual ~Character();

    [[nodiscard]] static std::unique_ptr<Character> createCharacterFromInput();
};

#endif // CHARACTER_HPP
