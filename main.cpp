#include <iostream>
#include <limits>
#include <vector>
#include <memory>
#include "World.hpp"
#include "NPCCharacter.hpp"
#include "Character.hpp"
#include "Utility.hpp"
#include "Ability.hpp"

void displayMainMenu() {
    std::cout << "===== Main Menu =====\n";
    std::cout << "1. Create Ability\n";
    std::cout << "2. Manage Characters\n";
    std::cout << "3. Create NPCCharacter\n";
    std::cout << "4. Execute Commands\n";
    std::cout << "5. Exit\n";
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
    std::cout << "Enter NPC name: ";
    std::getline(std::cin, npcName); // Correctly read the full name

    auto npcAbilityShared = Ability::createAbilityFromInput();

    // Convert shared_ptr to unique_ptr
    std::unique_ptr<Ability> npcAbilityUnique = std::make_unique<Ability>(*npcAbilityShared);

    int health;
    std::cout << "Enter NPC health: ";
    std::cin >> health;

    auto npc = std::make_unique<NPCCharacter>(npcName, std::move(npcAbilityUnique), health);
    world.addCharacter(std::move(npc));

    std::cout << "NPC '" << npcName << "' created successfully.\n";
}




void showCharacterDetails(const World &world) {
    if (world.getCharacters().empty()) {
        std::cout << "No characters available.\n";
        return;
    }

    int index = 0;
    for (const auto &charac : world.getCharacters()) {
        std::cout << ++index << ". " << charac->getName() << "\n";
    }

    std::cout << "Select a character to show details: ";
    std::cin >> index;
    std::cin.ignore();

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
    std::cin.ignore();

    if (index < 1 || index > world.getCharacters().size()) {
        std::cout << "Invalid selection.\n";
        return;
    }

    auto& character = world.getCharacters()[index - 1];
    bool editing = true;

    while (editing) {
        std::cout << "1. Edit Name\n";
        std::cout << "2. Edit Ability\n";
        std::cout << "3. Go Back\n";
        std::cout << "Please select an option: ";

        int editChoice;
        std::cin >> editChoice;
        std::cin.ignore();

        switch (editChoice) {
            case 1: {
                std::string newName;
                std::cout << "Enter new name for " << character->getName() << ": ";
                std::getline(std::cin, newName);
                character->setName(newName);
                break;
            }
            case 2: {
                auto newAbilityShared = Ability::createAbilityFromInput();
                character->setAbility(std::make_unique<Ability>(newAbilityShared));
                break;
            }
            case 3:
                editing = false;
            break;
            default:
                std::cout << "Invalid choice.\n";
            break;
        }
    }
}



void executeCommands(World &world) {
    world.executeAllCommands();
}

// Updated Create Ability function using Composite Pattern
void createAbility(std::vector<std::shared_ptr<Ability>> &abilities) {
    int choice;
    do {
        std::cout << "\n===== Create Ability Menu =====\n"
                  << "1. Create Individual Ability\n"
                  << "2. Create Composite Ability\n"
                  << "3. Display All Abilities\n"
                  << "0. Go Back\n";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int power;
            std::cout << "Enter Ability Name: ";
            std::cin >> name;
            std::cout << "Enter Ability Power: ";
            std::cin >> power;

            abilities.push_back(std::make_shared<Ability>(name, power));
            std::cout << "Created Individual Ability: " << name << " (Power: " << power << ")\n";

        } else if (choice == 2) {
            std::string compositeName;
            std::cout << "Enter Composite Ability Name: ";
            std::cin >> compositeName;

            auto composite = std::make_shared<CompositeAbility>(compositeName);

            int addChoice;
            do {
                std::cout << "\n1. Add Individual Ability\n"
                          << "2. Add Existing Composite\n"
                          << "0. Done\n";
                std::cin >> addChoice;

                if (addChoice == 1) {
                    std::string name;
                    int power;
                    std::cout << "Enter Ability Name: ";
                    std::cin >> name;
                    std::cout << "Enter Ability Power: ";
                    std::cin >> power;

                    composite->addAbility(std::make_shared<Ability>(name, power));
                    std::cout << "Added: " << name << " to Composite: " << compositeName << "\n";

                } else if (addChoice == 2) {
                    std::cout << "Available Abilities:\n";
                    for (size_t i = 0; i < abilities.size(); ++i) {
                        if (std::dynamic_pointer_cast<CompositeAbility>(abilities[i])) {
                            std::cout << i + 1 << ". " << abilities[i]->getName() << "\n";
                        }
                    }
                    size_t index;
                    std::cout << "Enter Composite Index: ";
                    std::cin >> index;

                    if (index > 0 && index <= abilities.size()) {
                        auto existingComposite = std::dynamic_pointer_cast<CompositeAbility>(abilities[index - 1]);
                        if (existingComposite) {
                            composite->addAbility(existingComposite);
                            std::cout << "Added Composite Ability to " << compositeName << "\n";
                        }
                    }
                }
            } while (addChoice != 0);

            abilities.push_back(composite);
        } else if (choice == 3) {
            std::cout << "\n=== Abilities ===\n";
            for (const auto &ability : abilities) {
                ability->display();
            }
        }
    } while (choice != 0);
}

int main() {
    World world;
    std::vector<std::shared_ptr<Ability>> abilities;
    bool running = true;

    while (running) {
        displayMainMenu();
        int option;
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                createAbility(abilities);
                break;
            case 2: {
                displayCharacterMenu();
                int characterOption;
                std::cin >> characterOption;
                std::cin.ignore();

                switch (characterOption) {
                    case 1:
                        createCharacter(world);
                        break;
                    case 2:
                        showCharacterDetails(world);
                        break;
                    case 3:
                        editCharacter(world);
                        break;
                    case 4:
                        break;
                    default:
                        std::cout << "Invalid option.\n";
                        break;
                }
                break;
            }
            case 3:
                displayNPCMenu();
                int npcOption;
                std::cin >> npcOption;
                std::cin.ignore();

                switch (npcOption) {
                    case 1:
                        createNPC(world);
                        break;
                    case 2:
                        showCharacterDetails(world);
                        break;
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid option.\n";
                        break;
                }
                break;
            case 4:
                executeCommands(world);
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
                break;
        }
    }

    return 0;
}
