#include "Ability.hpp"

#include <limits>

// Implementation of Ability class
Ability::Ability(const std::string &name, int powerLevel)
    : name(name), powerLevel(powerLevel) {}

void Ability::display() const {
    std::cout << "Ability: " << name << ", Power Level: " << powerLevel << "\n";
}

[[nodiscard]] std::string Ability::getName() const {
    return name;
}

[[nodiscard]] int Ability::getPowerLevel() const {
    return powerLevel;
}

void Ability::addAbility(std::shared_ptr<Ability>) {
    // Default implementation: Do nothing.
    // This method will be overridden in CompositeAbility.
}

// Static method to create an ability from user input
std::shared_ptr<Ability> Ability::createAbilityFromInput() {
    std::string name;
    int powerLevel;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    std::cout << "Enter ability name: ";
    std::getline(std::cin, name); // Read the full ability name


    std::cout << "Enter power level: ";
    std::cin >> powerLevel;

    return std::make_shared<Ability>(name, powerLevel);
}


// Implementation of CompositeAbility class
CompositeAbility::CompositeAbility(const std::string &name)
    : Ability(name, 0) {} // Composite doesn't have its own power level.

void CompositeAbility::addAbility(std::shared_ptr<Ability> ability) {
    abilities.push_back(ability);
}

void CompositeAbility::display() const {
    std::cout << "Composite Ability: " << name << "\n";
    for (const auto &ability : abilities) {
        ability->display();
    }
}

