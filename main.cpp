#include <iostream>
#include "World.hpp"
#include "NPCCharacter.hpp"
#include "Character.hpp"
#include <memory>

void displayMainMenu() {
    std::cout << "===== Main Menu =====\n";
    std::cout << "1. Create Ability\n";
    std::cout << "2. Character\n";
    std::cout << "3. Create NPCCharacter\n";
    std::cout << "4. Exit\n";
    std::cout << "Please select an option: ";
}

void displayCharacterMenu() {
    std::cout << "===== Character Menu =====\n";
    std::cout << "1. Create New Character\n";
    std::cout << "2. Show Character Details\n";
    std::cout << "3. Edit Character\n";
    std::cout << "4. Go Back\n";
    std::cout << "Please select an option: ";
}

void displayEditCharacterMenu() {
    std::cout << "===== Edit Character Menu =====\n";
    std::cout << "1. Edit Name\n";
    std::cout << "2. Edit Ability\n";
    std::cout << "3. Go Back\n";
    std::cout << "Please select an option: ";
}

void displayNPCMenu() {
    std::cout << "===== NPC Menu =====\n";
    std::cout << "1. Create NPCCharacter\n";
    std::cout << "2. Show NPC Details\n";
    std::cout << "3. Go Back\n";
    std::cout << "Please select an option: ";
}

void createCharacter(World& world) {
    auto character = Character::createCharacterFromInput();
    world.addCharacter(std::move(character));
}

void createNPC(World& world) {
    std::string npcName;
    std::cout << "Enter NPC name: ";
    std::cin.ignore();  // Clear the input buffer
    std::getline(std::cin, npcName);

    Ability npcAbility = Ability::createAbilityFromInput();

    int health;
    std::cout << "Enter NPC health: ";
    std::cin >> health;

    auto npc = std::make_unique<NPCCharacter>(npcName, std::make_unique<Ability>(npcAbility), health);
    world.addCharacter(std::move(npc));

    std::cout << "NPC '" << npcName << "' created successfully.\n";
}

void showCharacterDetails(const World& world) {
    if (world.getCharacters().empty()) {
        std::cout << "No characters available.\n";
        return;
    }

    int index = 0;
    for (const auto& charac : world.getCharacters()) {
        std::cout << ++index << ". " << charac->getName() << "\n";
    }

    std::cout << "Select a character to show details: ";
    std::cin >> index;
    std::cin.ignore(); // Clear the input buffer

    if (index < 1 || index > world.getCharacters().size()) {
        std::cout << "Invalid selection.\n";
        return;
    }

    world.getCharacters()[index - 1]->display();
}

void editCharacter(const World& world) {
    if (world.getCharacters().empty()) {
        std::cout << "No characters available to edit.\n";
        return;
    }

    int index = 0;
    for (const auto& charac : world.getCharacters()) {
        std::cout << ++index << ". " << charac->getName() << "\n";
    }

    std::cout << "Select a character to edit: ";
    std::cin >> index;
    std::cin.ignore(); // Clear the input buffer

    if (index < 1 || index > world.getCharacters().size()) {
        std::cout << "Invalid selection.\n";
        return;
    }

    auto& character = world.getCharacters()[index - 1];
    bool editing = true;

    while (editing) {
        displayEditCharacterMenu();
        int editChoice;
        std::cin >> editChoice;
        std::cin.ignore(); // Clear the input buffer

        switch (editChoice) {
            case 1: {
                // Edit Name
                std::string newName;
                std::cout << "Enter new name for " << character->getName() << ": ";
                std::getline(std::cin, newName);
                character->setName(newName);
                break;
            }
            case 2: {
                // Edit Ability
                Ability newAbility = Ability::createAbilityFromInput();
                character->setAbility(std::make_unique<Ability>(newAbility));
                break;
            }
            /*case 3: {
                // Edit Spell Level
                int newSpellLevel;
                std::cout << "Enter new spell level for " << character->getName() << ": ";
                std::cin >> newSpellLevel;
                std::cin.ignore(); // Clear the input buffer
                Ability newAbility = Ability::createAbilityFromInput();
                newAbility.setSpellLevel(newSpellLevel); // Update the spell level
                character->setAbility(std::make_unique<Ability>(newAbility));
                break;
            }*/
            case 3:
                editing = false;
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }
}

void createAbility() {
    std::cout << "Creating a new ability...\n";
    Ability newAbility = Ability::createAbilityFromInput();
    newAbility.display();
}

int main() {
    World world;
    bool running = true;

    while (running) {
        displayMainMenu();
        int option;
        std::cin >> option;
        std::cin.ignore(); // Clear the input buffer

        switch (option) {
            case 1: {
                createAbility();
                break;
            }
            case 2: {
                displayCharacterMenu();
                int characterOption;
                std::cin >> characterOption;
                std::cin.ignore();  // Clear the input buffer

                switch (characterOption) {
                    case 1: {
                        createCharacter(world);
                        break;
                    }
                    case 2: {
                        showCharacterDetails(world);
                        break;
                    }
                    case 3: {
                        editCharacter(world);
                        break;
                    }
                    case 4:
                        break;
                    default:
                        std::cout << "Invalid option.\n";
                        break;
                }
                break;
            }
            case 3: {
                displayNPCMenu();
                int npcOption;
                std::cin >> npcOption;
                std::cin.ignore();  // Clear the input buffer

                switch (npcOption) {
                    case 1: {
                        createNPC(world);
                        break;
                    }
                    case 2: {
                        showCharacterDetails(world);  // Assuming NPCs are shown as characters
                        break;
                    }
                    case 3:
                        break;
                    default:
                        break;
                }
                break;
            }
            case 4: {
                running = false;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
